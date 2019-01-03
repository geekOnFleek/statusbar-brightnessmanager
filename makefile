main: client-bins
	gcc statusbar-brightness-daemon.c -o bin/statusbar-brightnessmanager
	systemctl stop brightness-management.service
	cp ./bin/statusbar-brightnessmanager ~/.uscripts/brightservice/statusbar-brightnessmanager
	cp ./bin/client-up ~/.uscripts/brightservice/client-up
	cp ./bin/client-down ~/.uscripts/brightservice/client-down
	cp ./bin/client-up ~/.uscripts/brght-up
	cp ./bin/client-down ~/.uscripts/brght-down
	systemctl start brightness-management.service

client-bins:
	mkdir -p bin
	gcc statusbar-brightness-daemon.c -o bin/statusbar-brightnessmanager
	gcc client-up.c -o bin/client-up
	gcc client-down.c -o bin/client-down
