#!/bin/bash

hidraw_str=$(ls /dev/ | grep hidraw)
hidraw_arr=($hidraw_str)


for i in "${hidraw_arr[@]}"; do
	devpath=$(udevadm info --query=property --name=/dev/$i | grep 0B05:19B6)

	if [ $devpath ]; then 
		keyboard-rgb /dev/$i
	fi
	
done
