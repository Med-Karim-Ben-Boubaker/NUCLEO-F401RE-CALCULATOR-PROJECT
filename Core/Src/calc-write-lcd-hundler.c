
#include "calc-write-lcd-hundler.h"

void print_result(char* stringResult){
	clear_row(1);
	lcd_put_cur(1, 0);
	lcd_send_string("=");
	lcd_put_cur(1, 1);
	lcd_send_string(stringResult);
}

void calculate_and_display(char* expression){
	if(checkValidExpression(expression)){
		int result;
		if(evaluateExpression(expression, &result)){
			char stringResult[16] = {'\0'};
			sprintf(stringResult, "%d", result);
			print_result(stringResult);
		}
		else display_error_division_by_zero();

	}
	else{
		print_invalid_expression_error();
	}

}

void print_invalid_expression_error(){
	clear_row(1);
	lcd_put_cur(1, 0);
	lcd_send_string(ERROR_MESSAGE_INVALID_EXPRESSION);
}

void display_error_division_by_zero(){
	clear_row(1);
	lcd_put_cur(1, 0);
	lcd_send_string(ERROR_MESSAGE_DIVISON_ZERO);
}


