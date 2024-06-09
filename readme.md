# Oven Controller Project

## Overview

This project implements an embedded system for controlling an oven using an AVR microcontroller. The system manages heating elements, a motor for a fan, and an LCD display for user interaction. It reads temperature settings and baking time from a keypad, displays the information on an LCD, and controls the heating elements and motor accordingly. Additionally, it includes a buzzer for alerts and a mechanism to check if the oven door is open.

## Features

- **Temperature Control**: Manages heating elements based on the preset temperature.
- **Time Control**: Allows users to set a baking time.
- **Motor Control**: Controls a motor to circulate air within the oven.
- **LCD Display**: Provides a user interface for setting temperature and time, and displays current status.
- **Keypad Input**: Allows user input for setting temperature and time.
- **Door Sensor**: Checks if the oven door is open and provides alerts.

## Project Structure

The project is organized into several files to maintain a clean, modular, and maintainable codebase. The files are divided into header files (`.h`) and source files (`.c`).

### Directory Layout

```
src/
│
├── main.c
├── lcd.c
├── lcd.h
├── keypad.c
├── keypad.h
├── motor.c
├── motor.h
├── bake.c
├── bake.h
└── utils.c
    └── utils.h
```

### Header Files (.h)

Header files are used to declare the interfaces to the functions, constants, macros, and data types used throughout the project. They act as a contract, providing function prototypes and shared definitions without exposing the implementation details.

### Source Files (.c)

Source files contain the actual implementation of the functions declared in the header files. They include the logic and code that performs the tasks defined by the function prototypes.

## Module Descriptions

### main.c

The `main.c` file contains the main function and the overall program logic. It initializes the system, reads user inputs, and manages the baking process.

### lcd.c and lcd.h

These files manage the LCD operations, including initialization, sending commands, and displaying strings.

#### Functions:

- `void LCD_Command(unsigned char cmnd)`: Sends a command to the LCD.
- `void LCD_Char(unsigned char data)`: Sends a character to the LCD.
- `void LCD_Init(void)`: Initializes the LCD.
- `void LCD_String(char str[])`: Displays a string on the LCD.
- `void LCD_String_xy(char row, char pos, char str[])`: Displays a string at a specified position on the LCD.
- `void LCD_Clear(void)`: Clears the LCD display.

### keypad.c and keypad.h

These files handle the keypad initialization and input. The keypad is used to set the temperature and baking time.

#### Functions:

- `void keypad_init(void)`: Initializes the keypad.
- `char keypad(void)`: Reads a key from the keypad.
- `uint16_t keypad_get_number(void)`: Reads a number from the keypad.

### motor.c and motor.h

These files manage the motor operations, including forward, backward, and stop controls.

#### Functions:

- `void motor_forward(void)`: Moves the motor forward.
- `void motor_backward(void)`: Moves the motor backward.
- `void motor_stop(void)`: Stops the motor.

### bake.c and bake.h

These files manage the baking process, including temperature control and checking the oven door status.

#### Functions:

- `void control_temperature(void)`: Controls the heating elements based on the preset temperature.
- `void Timer1_CTC_Init(void)`: Initializes Timer1 for the motor.
- `void Timer0_Init(void)`: Initializes Timer0 for timekeeping.
- `void check_door(void)`: Checks if the oven door is open.
- `void bake(void)`: Manages the baking process.

### utils.c and utils.h

These files contain utility functions and global variables used throughout the project.

#### Variables:

- `int preset_temp, baking_time`
- `int actual_temp[2]`
- `int heating_elements`
- `int fan_direction`
- `int door_status`
- `int baking_cycle_status`

## Setup

1. **Clone the Repository**:
   ```
   git clone https://github.com/yourusername/oven-controller.git
   cd oven-controller/src
   ```

2. **Compile the Code**:
   Use your preferred AVR toolchain to compile the code. For example, using `avr-gcc`:
   ```
   avr-gcc -mmcu=atmega328p -DF_CPU=8000000UL -o main.elf main.c lcd.c keypad.c motor.c bake.c utils.c
   avr-objcopy -O ihex main.elf main.hex
   ```

3. **Upload the Code**:
   Use `avrdude` or a similar tool to upload the compiled code to your AVR microcontroller:
   ```
   avrdude -c usbtiny -p m328p -U flash:w:main.hex
   ```

## Usage

1. **Power On**: Power on the system. The LCD will prompt you to set the temperature.
2. **Set Temperature**: Use the keypad to enter the desired temperature and press `#`.
3. **Set Time**: The LCD will prompt you to set the baking time. Enter the time in minutes using the keypad and press `#`.
4. **Baking Process**: The system will start the baking process, controlling the temperature and displaying the remaining time on the LCD.
5. **Alerts**: If the oven door is opened during the baking process, the buzzer will sound an alert.

---