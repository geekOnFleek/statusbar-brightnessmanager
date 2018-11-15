#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
}message;

int main()
{
	key_t key;
	int msgid;
	//ftok to generate unique key
	key = ftok("/home/jan/.uscripts/brghtservice/brightness-daemon.c", 65);
	
	msgid = msgget(key, 0666 | IPC_CREAT);
	message.mesg_type = 1;

	strncpy(message.mesg_text, "DWN", 3);

	msgsnd(msgid, &message, sizeof(message), 0);

	printf("Data sent is: %s \n", message.mesg_text);
	return 0;
}
