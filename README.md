# RaspberryPiGPIOspeed

This project contains programs in C++ and Python languages to test GPIO speed for different Raspberry Pi board versions.
gpiod2 library was used for GPIO access because it is supported on all tested platforms.
Note that the "gpiochip0" constant should be used to access GPIO on RPi4 and the "gpiochip4" constant for RPi5.
