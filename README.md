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


## HOSTAPD
- it is a linux deamon process that we use to manage the wireless interface. it is a user space software which will turn the linux device into an access point.

Hostapd talks with client like GUI using control interface. This is the port 8877 where hostapd will be listening to.


## SYSTEM CALL
- there are two modes in kernel usermode and kernel mode
- to switch to kernel mode I need system call

    user mode (write system call) ------------------interrupt-----------> kernel mode(trap handler will start and  system call number in system call table and execute that function and return back control to the user program)
