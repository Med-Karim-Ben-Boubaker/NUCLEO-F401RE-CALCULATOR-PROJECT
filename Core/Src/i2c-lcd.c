
/**
 * @file lcd_functions.c
 * @brief Functions for controlling an LCD display using I2C communication.
 * 
 * This file contains functions for initializing and controlling an LCD display
 * using the I2C communication protocol. It provides functions for sending commands
 * and data to the LCD, clearing the display, setting the cursor position, and
 * printing strings on the display.
 *
 * The functions assume that the I2C communication is already configured and
 * the appropriate I2C handler is defined in the main program.
 *
 * Note: This code assumes a 2-line LCD display with a 16x2 character format.
 *
 * @authors [ControllersTech, MOHAMED KARIM BENBOUBAKER]
 */

#include "i2c-lcd.h"
extern I2C_HandleTypeDef hi2c1;  // change your handler here accordingly

#define SLAVE_ADDRESS_LCD 0x4E //change this according to our setup

void lcd_send_cmd (char cmd)
{
  char data_u, data_l;
	uint8_t data_t[4];
	
	// Extract the upper and lower 4 bits of the command
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);

	// Construct the data array for transmitting via I2C
	data_t[0] = data_u|0x0C;  //en=1, rs=0
	data_t[1] = data_u|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0

	// Transmit the data array to the LCD module via I2C
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_send_data (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];

	// Extract the upper and lower 4 bits of the command
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);

	// Construct the data array for transmitting via I2C
	data_t[0] = data_u|0x0D;  //en=1, rs=0
	data_t[1] = data_u|0x09;  //en=0, rs=0
	data_t[2] = data_l|0x0D;  //en=1, rs=0
	data_t[3] = data_l|0x09;  //en=0, rs=0

	// Transmit the data array to the LCD module via I2C
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_clear (void)
{
	// Send command to set the cursor to the beginning of the first line
	lcd_send_cmd (0x80);

	// Send blank spaces to overwrite the existing characters
	for (int i=0; i<70; i++)
	{
		lcd_send_data (' ');
	}
}

void lcd_put_cur(int row, int col)
{
    switch (row)
    {
        case 0:
            col |= 0x80; // Set the cursor position for the first line
            break;
        case 1:
            col |= 0xC0; // Set the cursor position for the second line
            break;
    }

    lcd_send_cmd (col);
}


/**
 * @brief Initialize the LCD display.
 * 
 * This function initializes the LCD display by sending the necessary commands
 * for the 4-bit mode and display settings. It sets the display to 2 lines and
 * 5x8 character format, turns off the display, clears the display, and sets
 * the entry mode to increment the cursor.
 */
void lcd_init (void)
{
	// 4 bit initialisation
	HAL_Delay(50);  // wait for >40ms
	lcd_send_cmd (0x30);
	HAL_Delay(5);  // wait for >4.1ms
	lcd_send_cmd (0x30);
	HAL_Delay(1);  // wait for >100us
	lcd_send_cmd (0x30);
	HAL_Delay(10);
	lcd_send_cmd (0x20);  // 4bit mode
	HAL_Delay(10);

 	// Display initialization
	lcd_send_cmd (0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	HAL_Delay(1);
	lcd_send_cmd (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
	HAL_Delay(1);
	lcd_send_cmd (0x01);  // clear display
	HAL_Delay(1);
	HAL_Delay(1);
	lcd_send_cmd (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	HAL_Delay(1);
	lcd_send_cmd (0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)
}

void lcd_send_string (char *str)
{
	// Iterate through each character in the string until the null terminator is reached
	while (*str)
		 // Send the current character to the LCD display
		lcd_send_data (*str++);
}

// Function to move the cursor to the right
void cursor_deplacement_right(int* row, int* col){
    if(*col < 16){
        // If the current column is less than 16, move the cursor one position to the right
        lcd_put_cur(*row, ++(*col));
    }
    else if(*row == 0){
        // If the current row is 0 and the column is at the maximum position (16),
        //Move the cursor to the next row at the beginning of the line
        *col = 0;
        lcd_put_cur(++(*row), *col);
    }
    else {
        // If the current row is not 0 and the column is at the maximum position (16),
        //Move the cursor to the first row at the beginning of the line
        *col = 0;
        *row = 0;
        lcd_put_cur(*row, *col);
    }
}

// Function to move the cursor to the left
void cursor_deplacement_left(int* row, int* col){
    if(*col > 0){
        // If the current column is greater than 0, move the cursor one position to the left
        lcd_put_cur(*row, --(*col));
    }
    else if(*row == 1){
        // If the current row is 1 and the column is at the beginning (0),
        //Move the cursor to the previous row at the end of the line
        *col = 16;
        lcd_put_cur(--(*row), *col);
    }
}

void remove_cursor_element(int* row, int* col){
	if(*row == 0 && *col == 0){
		// If the cursor is at the beginning of the first line
        	// Clear the character, move the cursor to the left and send a space character
		lcd_put_cur(0, 0);
		lcd_send_string(" ");
		cursor_deplacement_left(row, col);
	}
	else {
		// If the cursor is not at the beginning of the first line
        	// Move the cursor to the left and send a space character
		cursor_deplacement_left(row, col);
		lcd_send_string(" ");

	}

}

void clear_row(int row){
	for(int i=0; i<16; i++){
		lcd_put_cur(row, i);
		lcd_send_string(" ");
	}
}

