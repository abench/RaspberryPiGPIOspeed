#include <gpiod.h>
#include <iostream>
#include <unistd.h>

int main() {
    gpiod_chip *chip;
    gpiod_line *line;
	// "gpiochip0" for Raspberry Pi 4, "gpiochip4" for Raspberry Pi 5
    const char *chipname = "gpiochip4";
    const unsigned int line_offset = 25;
    
    chip = gpiod_chip_open_by_name(chipname);
    if (!chip) {
        std::cerr << "Chip open error." << std::endl;
        return 1;
    }

    line = gpiod_chip_get_line(chip, line_offset);
    if (!line) {
        std::cerr << "Line open error." << std::endl;
        gpiod_chip_close(chip);
        return 1;
    }

    if (gpiod_line_request_output(line, "blinktest", 0) < 0) {
        std::cerr << "Line setting error" << std::endl;
        gpiod_chip_close(chip);
        return 1;
    }

    while (true) {
        gpiod_line_set_value(line, 1);        
        gpiod_line_set_value(line, 0);       
    }

    gpiod_chip_close(chip);
    return 0;
}
