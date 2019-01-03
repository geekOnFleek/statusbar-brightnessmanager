main: client-bins
	gcc statusbar-brightness-daemon.c -o bin/statusbar-brightnessmanager
	systemctl stop brightness-management.service
	cp bin/statusbar-brightnessmanager ~/.uscripts/brightservice/statusbar-brightnessmanager
	systemctl start brightness-management.service

client-bins:
	mkdir -p bin
	gcc statusbar-brightness-daemon.c -o bin/statusbar-brightnessmanager
	gcc client-up.c -o bin/client-up
	gcc client-down.c -o bin/client-down
