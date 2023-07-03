# NUCLEO-F401RE Calculator Project

This repository contains the source code and documentation for the NUCLEO-F401RE Calculator Project. The project is developed for the STM32 Nucleo-F401RE development board and implements a simple calculator application.
This Project still can be used by other STM32 Microcntrollers but some other configurations and "stm32f4xx_hal.h" header file may change.

## Features

- Basic arithmetic operations: addition, subtraction, multiplication, and division.
- Respects the order of operations (*, /, +, -)
- Keypad input for entering numbers and operators.
- LCD display for showing input and result.
- Error handling for division by zero and invalid expressions.
- User-friendly interface with cursor control.

## Hardware Requirements

To run the NUCLEO-F401RE Calculator Project, you need the following hardware:

- STM32 Nucleo-F401RE development board.
- HC-543 Keypad module.
- I2C Serial Interface 1602 LCD Module.

## Software Requirements

The project is developed using the following software:

- STM32CubeIDE: An Integrated Development Environment (IDE) for STM32 microcontrollers.
- STM32CubeF4: A software development kit (SDK) for STM32F4 microcontrollers.
- HAL Library: Hardware Abstraction Layer (HAL) library for STM32F4 microcontrollers.
- Standard Peripheral Library: Peripheral library for STM32F4 microcontrollers.
- CMSIS: Cortex Microcontroller Software Interface Standard.

## Getting Started

To get started with the NUCLEO-F401RE Calculator Project, follow these steps:

1. Clone the repository to your local machine.
2. Open the project in STM32CubeIDE.
3. Connect the Nucleo board to your computer.
4. Build the project and flash it to the board.
5. Connect the keypad module and LCD module to the appropriate pins on the Nucleo board.
6. Power on the Nucleo board.
7. Use the keypad to enter expressions and see the results on the LCD display.

## Contributing

Contributions to the NUCLEO-F401RE Calculator Project are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE). Feel free to modify and distribute the code as per the terms of the license.

## Contact

For any inquiries or questions about the NUCLEO-F401RE Calculator Project, please contact [mohamedkarim.benboubaker@insat.ucar.tn]

Feel free to customize this README file to fit your specific project requirements and provide detailed information about the project, its usage, and any additional instructions or dependencies.
