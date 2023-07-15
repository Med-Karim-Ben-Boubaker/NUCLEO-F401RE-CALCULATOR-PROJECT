/*
    File: i2c-lcd.h

    Description:
    This header file provides functions for initializing and controlling an LCD (Liquid Crystal Display) connected to an STM32 microcontroller using I2C serial Communication Protocol.

    Dependencies:
    - stm32f4xx_hal.h: STM32 HAL library

    Functions:
    - void lcd_init(void)
        - Initializes the LCD.

    - void lcd_send_cmd(char cmd)
        - Sends a command to the LCD.

    - void lcd_send_data(char data)
        - Sends data to the LCD.

    - void lcd_send_string(char *str)
        - Sends a string to the LCD.

    - void lcd_put_cur(int row, int col)
        - Sets the cursor position on the LCD display.

    - void lcd_clear(void)
        - Clears the LCD display.

    - void cursor_deplacement_right(int* row, int* col)
        - Moves the cursor one position to the right.

    - void cursor_deplacement_left(int* row, int* col)
        - Moves the cursor one position to the left.

    - void remove_cursor_element(int* row, int* col)
        - Removes the character at the current cursor position.

    - void clear_row(int row)
        - Clears the specified row on the LCD display.

    Authors: [ControllersTech, Mohamed Karim Benboubaker]
    Date: [07/04/2023]
*/
#include "stm32f4xx_hal.h"

void lcd_init(void);
void lcd_send_cmd(char cmd);
void lcd_send_data(char data);
void lcd_send_string(char *str);
void lcd_put_cur(int row, int col);
void lcd_clear(void);
void cursor_deplacement_right(int* row, int* col);
void cursor_deplacement_left(int* row, int* col);
void remove_cursor_element(int* row, int* col);
void clear_row(int row);
