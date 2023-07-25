#include "keypad-lib.h"

// Function to read the pressed key from the keypad
char keypad_read() {
    // Iterate through each row
    for (int row = 0; row < 4; row++) {

        // Set all rows to low (deactivate all rows)
        HAL_GPIO_WritePin(GPIOC, ROW1_PIN | ROW2_PIN | ROW3_PIN | ROW4_PIN, GPIO_PIN_RESET);

        // Set the current row to high (activate the specific row)
        switch (row) {
            case 0:
                HAL_GPIO_WritePin(GPIOC, ROW1_PIN, GPIO_PIN_SET); //Write PC1
                break;
            case 1:
                HAL_GPIO_WritePin(GPIOC, ROW2_PIN, GPIO_PIN_SET); //Write PC0
                break;
            case 2:
                HAL_GPIO_WritePin(GPIOC, ROW3_PIN, GPIO_PIN_SET); //Write PC3
                break;
            case 3:
                HAL_GPIO_WritePin(GPIOC, ROW4_PIN, GPIO_PIN_SET); //Write PC2
                break;
        }

        HAL_Delay(1); // Adjust the delay duration as needed

        // Check if any column is low (indicating a key press)
        if (HAL_GPIO_ReadPin(GPIOA, COL1_PIN) == GPIO_PIN_SET) {
            if (row == 0)
                return '1';
            else if (row == 1)
                return '4';
            else if (row == 2)
                return '7';
            else if (row == 3)
                return '*';
        }

        if (HAL_GPIO_ReadPin(GPIOA, COL2_PIN) == GPIO_PIN_SET) {
            if (row == 0)
                return '2';
            else if (row == 1)
                return '5';
            else if (row == 2)
                return '8';
            else if (row == 3)
                return '0';
        }

        if (HAL_GPIO_ReadPin(GPIOA, COL3_PIN) == GPIO_PIN_SET) {
            if (row == 0)
                return '3';
            else if (row == 1)
                return '6';
            else if (row == 2)
                return '9';
            else if (row == 3)
                return '#';
        }

        if (HAL_GPIO_ReadPin(GPIOB, COL4_PIN) == GPIO_PIN_SET) {
            if (row == 0)
                return '+';
            else if (row == 1)
                return '-';
            else if (row == 2)
                return '/';
            else if (row == 3)
                return 'D';
        }
    }

    // No key press detected
    return '\0';
}
