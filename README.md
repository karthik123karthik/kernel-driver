# kernel-driver

this repo is my learning on kernel drivers.

what is a driver ?
kernel has two tasks : 
   1. process scheduling 
   2. handling hardware
kernel uses drivers to handle hardware
   
what happens when we power on ?
1. CPU will go to ROM and try to bring bootloader inside RAM.
2. ONCE Bootloader is loaded it will start the OS by telling the memory address of the Kernal to the CPU
3. Bootloder will also store the DTB - (device tree blob) inside a register which kernel uses to known about the hardwares associated with the devices.
