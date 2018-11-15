#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define brightness_path "/sys/class/backlight/intel_backlight/brightness"

struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
}message;

int brght = 30;

void write_brightness(int new_brght)
{
	//Checks for valid value to write into brightness file
	if(new_brght > 187 || new_brght < 1)
		return;
	FILE *f = fopen(brightness_path, "w");

	if(fprintf(f, "%i", new_brght) < 0)
		printf("Error while writing into file");
	else
		brght = new_brght;
	fclose(f);
}

int main()
{
	key_t key;
	int msgid;
	
	key = ftok("progfile", 65);
	
	msgid = msgget(key, 0666 | IPC_CREAT);
	int i = 1;
	
	printf("Accessing file");
	FILE *f = fopen(brightness_path, "r");
	if(f == NULL)
		printf("Nullpointer\n");
	fscanf(f, "%i", &brght);
	fclose(f);
	printf("%d\n", brght);
	
	while(i){
		msgrcv(msgid, &message, sizeof(message), 1, 0);
		printf("%d\n", strncmp(message.mesg_text, "EXT", 3));
		if(strncmp(message.mesg_text, "EXT", 3) == 0)
			i = 0;
		if(strncmp(message.mesg_text, "UP", 2) == 0)
			write_brightness(brght + 7);
		if(strncmp(message.mesg_text, "DWN", 3) == 0)
			write_brightness(brght - 7);	
		printf("Data Received is: %s \n", message.mesg_text);
	}
	msgctl(msgid, IPC_RMID, NULL);

	return 0;
}
