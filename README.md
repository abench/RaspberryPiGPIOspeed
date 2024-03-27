# RaspberryPiGPIOspeed

Thi project contains programs in C++ and Python to test GPIO speed for different Raspberry Pi board versions.
gpiod2 library was used to GPIO access, because it is supported on the all tested platforms.
Note that "gpiochip0” constant was used to access GPIO on RPi4 and "gpiochip4” constant for RPi5.
