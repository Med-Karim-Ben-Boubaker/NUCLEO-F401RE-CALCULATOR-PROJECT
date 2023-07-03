#include <arithmetic_calculator.h>

int precedence(char operator) {
    if (operator == '+' || operator == '-') // Check if the operator is addition or subtraction
        return 1;  // Return a precedence of 1 for addition and subtraction
    else if (operator == '*' || operator == '/') // Check if the operator is multiplication or division
        return 2;  // Return a precedence of 2 for multiplication and division
    else
        return 0;  // Return a precedence of 0 for any other operator
}


int applyOperator(int a, int b, char operator) {
    switch (operator) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
        	return a / b;
        default:
            return 0;
    }
}

bool isOperator(char ch){
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/') return true;
	else return false;
}

bool evaluateExpression(char* expression, int* result) {
    int i;
    int value;
    int stack[100];             // Stack to store operands
    char operatorStack[100];    // Stack to store operators
    int stackTop = -1;          // Top of the operand stack
    int operatorTop = -1;       // Top of the operator stack

    for (i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            // If the current character is a digit, extract the whole number
            value = 0;
            while (isdigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            stack[++stackTop] = value;  // Push the number onto the operand stack
        }
        else if (expression[i] == '(') {
            operatorStack[++operatorTop] = expression[i];  // Push '(' onto the operator stack
        }
        else if (expression[i] == ')') {
            // Evaluate the subexpression inside parentheses
            while (operatorTop != -1 && operatorStack[operatorTop] != '(') {
                int b = stack[stackTop--];             // Pop the second operand from the stack
                int a = stack[stackTop--];             // Pop the first operand from the stack
                char op = operatorStack[operatorTop--];  // Pop the operator from the stack

                // Check for division by zero
                if (op == '/' && b == ERROR_DIVISION_BY_ZERO) {
                    display_error_division_by_zero();
                    return false;  // Return false to indicate division by zero error
                }
                else {
                    stack[++stackTop] = applyOperator(a, b, op);  // Apply the operator and push the result onto the stack
                }
            }
            if (operatorTop != -1 && operatorStack[operatorTop] == '(') {
                operatorTop--;  // Pop '(' from the operator stack
            }
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            // Process operators: +, -, *, /
            while (operatorTop != -1 && precedence(operatorStack[operatorTop]) >= precedence(expression[i])) {
                int b = stack[stackTop--];             // Pop the second operand from the stack
                int a = stack[stackTop--];             // Pop the first operand from the stack
                char op = operatorStack[operatorTop--];  // Pop the operator from the stack

                // Check for division by zero
                if (op == '/' && b == ERROR_DIVISION_BY_ZERO) {
                    display_error_division_by_zero();
                    return false;  // Return false to indicate division by zero error
                }
                else {
                    stack[++stackTop] = applyOperator(a, b, op);  // Apply the operator and push the result onto the stack
                }
            }
            operatorStack[++operatorTop] = expression[i];  // Push the current operator onto the operator stack
        }
    }

    // Process remaining operators
    while (operatorTop != -1) {
        int b = stack[stackTop--];             // Pop the second operand from the stack
        int a = stack[stackTop--];             // Pop the first operand from the stack
        char op = operatorStack[operatorTop--];  // Pop the operator from the stack

        // Check for division by zero
        if (op == '/' && b == ERROR_DIVISION_BY_ZERO) {
            display_error_division_by_zero();
            return false;  // Return false to indicate division by zero error
        }
        else {
            stack[++stackTop] = applyOperator(a, b, op);  // Apply the operator and push the result onto the stack
        }
    }

    *result = stack[stackTop];  // Store the final result in the provided pointer
    return true;                // Return true to indicate successful evaluation
}


bool checkValidExpression(char* expression) {
    int i;

    // Check if the first character is an operator
    if (isOperator(expression[0]))
        return false;

    for (i = 0; expression[i] != '\0'; i++) {

        // Check if the current character and the next character are both operators
        if (isOperator(expression[i]) && isOperator(expression[i + 1]))
            return false;
    }

    // Check if the last character is an operator
    if (isOperator(expression[i - 1]))
        return false;

    return true;  // Return true if the expression is valid
}




