cmd_/home/pi/device-drivers/native/assignment/day4_prg1/modules.order := {   echo /home/pi/device-drivers/native/assignment/day4_prg1/chardriver.ko; :; } | awk '!x[$$0]++' - > /home/pi/device-drivers/native/assignment/day4_prg1/modules.order
