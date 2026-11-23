# FA608UM-Linux-RGB-keyboard-light-initializer

A C program `keyboard-rgb.c` that enables your keyboard to set Lamp state itself/autonomously (i.e. without the Host sending Lamp update messages).

The program works by sending a boolean value `1` (`true`) to report *ID 70 (0x46)* that is responsible for enabling and disabling autonomous mode.

# program life-cycle

The bash script `keyboard-rgb-script.sh` should be enabled as a *systemd* service so it can run on boot. The script gets the current *hidrawX* file that corresponds to the keyboard device by querying through the available *hidraw* files and grepping for *0B05:19B6* which is the hardware ID for the built-in ASUS N-KEY keyboard and RGB lighting controller.

the script then runs `keyboard-rgb.c` with one argument - the hidrawX file name - the program then initialize a small 2 byte buffer and opens the *hidrawX* file, then it writes *0x46* (report ID 70) and *0x01* (true) and use ioctl to send this buffer to *hidrawX* by `HIDIOCSFEATURE`.
