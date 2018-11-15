# statusbar-brightnessmanager
Daemon that runs in background an writes brightness on Key-events. Currently there's conflict when both - statusbar-networkmanager and statusbar-brightnessmanager are called by root. Slows down startup. Causes High CPU usage, but only if called b root. It also wrote 5Gb of loggin, so I should look into that, as well.
