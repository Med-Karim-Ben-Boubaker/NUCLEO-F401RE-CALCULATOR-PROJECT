/*
    File: arithmetic_calculator.h

    Description:
    This header file contains function declarations and constants for an arithmetic calculator application on STM32 microcontroller.
    It includes dependencies on STM32 HAL library, an I2C LCD library, and standard input/output library.

    Dependencies:
    - stm32f4xx_hal.h: STM32 HAL library
    - i2c-lcd.h: I2C LCD library
    - stdio.h: Standard input/output library

    Constants:
    - ERROR_MESSAGE_INVALID_EXPRESSION
        - Represents the error message for an invalid expression.
    - ERROR_MESSAGE_DIVISION_ZERO
        - Represents the error message for division by zero.

    Functions:
    - void print_result(char* stringResult)
        - Prints the result of the arithmetic calculation to the LCD display.
    - void calculate_and_display(char* expression)
        - Calculates the arithmetic expression and displays the result on the LCD display.
    - void print_invalid_expression_error(void)
        - Prints the error message for an invalid expression to the LCD display.
    - void display_error_division_by_zero(void)
        - Prints the error message for division by zero to the LCD display.

    Author: [Mohamed Karim Benboubaker]
    Date: [07/04/2023]
*/
#include "stm32f4xx_hal.h"
#include "i2c-lcd.h"
#include "arithmetic_calculator.h"
#include <stdio.h>

#define ERROR_MESSAGE_INVALID_EXPRESSION "INVALID EXPRESSION"
#define ERROR_MESSAGE_DIVISION_ZERO "DIVISION BY ZERO"

void print_result(char* stringResult);
void calculate_and_display(char* expression);
void print_invalid_expression_error(void);
void display_error_division_by_zero(void);
