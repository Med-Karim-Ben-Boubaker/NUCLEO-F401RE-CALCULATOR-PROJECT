/*
    File: arithmetic_expression.h

    Description:
    This header file contains function declarations and constants for evaluating and validating arithmetic expressions.

    Functions:
    - bool evaluateExpression(char* expression, int* result)
        - Evaluates the given arithmetic expression and stores the result in the provided pointer.
        - Returns true if the evaluation is successful, or false if there is a division by zero.
    - int applyOperator(int a, int b, char operator)
        - Applies the given operator to the operands a and b and returns the result.
    - int precedence(char operator)
        - Determines the precedence of the given operator.
        - Returns 1 for addition and subtraction, 2 for multiplication and division, and 0 for any other operator.
    - bool checkValidExpression(char* expression)
        - Checks if the given arithmetic expression is valid.
        - Returns true if the expression is valid, or false if it contains invalid operator placements.
    - bool isOperator(char ch)
        - Checks if the given character is an operator.
        - Returns true if the character is '+', '-', '*', or '/', or false otherwise.

    Constants:
    - ERROR_DIVISION_BY_ZERO
        - Represents the error code for division by zero.

    Author: [Mohamed Karim Benboubaker]
    Date: [07/04/2023]
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define ERROR_DIVISION_BY_ZERO 0

bool evaluateExpression(char* expression, int* result);
int applyOperator(int a, int b, char operator);
int precedence(char operator);
bool checkValidExpression(char* expression);
bool isOperator(char ch);
