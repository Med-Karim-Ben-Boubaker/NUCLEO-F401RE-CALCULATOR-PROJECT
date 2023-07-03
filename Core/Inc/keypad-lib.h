/*
    File: keypad.h

    Description:
    This header file defines GPIO pins for rows and columns of a keypad connected to an STM32 microcontroller.
    It also provides a function to read the pressed key from the keypad.

    Dependencies:
    - stm32f4xx_hal.h: STM32 HAL library

    GPIO Pin Definitions:
    - ROW1_PIN: GPIO pin for the first row (PC1)
    - ROW2_PIN: GPIO pin for the second row (PC0)
    - ROW3_PIN: GPIO pin for the third row (PC3)
    - ROW4_PIN: GPIO pin for the fourth row (PC2)
    - COL1_PIN: GPIO pin for the first column (PA0)
    - COL2_PIN: GPIO pin for the second column (PA1)
    - COL3_PIN: GPIO pin for the third column (PA4)
    - COL4_PIN: GPIO pin for the fourth column (PB0)

    Functions:
    - char keypad_read(void)
        - Reads the pressed key from the keypad and returns its character representation.

    Author: [Mohamed Karim Benboubaker]
    Date: [07/04/2023]
*/
#include "stm32f4xx_hal.h"

// Define the GPIO pins for rows and columns
#define ROW1_PIN GPIO_PIN_1	//PC1
#define ROW2_PIN GPIO_PIN_0	//PC0
#define ROW3_PIN GPIO_PIN_3	//PC3
#define ROW4_PIN GPIO_PIN_2	//PC2

#define COL1_PIN GPIO_PIN_0 //PA0
#define COL2_PIN GPIO_PIN_1 //PA1
#define COL3_PIN GPIO_PIN_4 //PA4
#define COL4_PIN GPIO_PIN_0 //PB0

// Function to read the pressed key from the keypad
char keypad_read(void);
