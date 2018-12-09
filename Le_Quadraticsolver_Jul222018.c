/*
FileName: Le_QuadraticSolver_Jul2218.c
FileType: C Source File
Author : Dung Le
Created On : 7/24/2018 10:00:00 AM
Last Modified On : 8/3/2018 5:19:00 PM
Description : Solve Quadratic Equations Using the Quadratic Formula 
Editor: Notepad++ Ver. 7.5.8
Complier: Raspbian 6.3.0
Kernel: Linux raspberrypi 4.9.59-v7+
=====================================================================================================================================*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void program_init()
{
	printf("\nProgram evaluates quadratic functions using the quadratic formula\n");
	printf("Please Insert 3 Values of a, b, and c following the standard form of a quadratic function\n");
	printf("Note: the standard form of a quadratic function is: ax^2 + bx + c = 0, where a and b are non-zero values\n\n");
}
 
void gather_input (double *a, double *b, double *c)
{
	printf("a = ");
	scanf(" %lf", a);
	printf("b = ");
	scanf(" %lf", b);
	printf("c = ");
	scanf(" %lf", c);
}	

void linear_function_notifier (double b, double c)
{
	printf("\na = 0, therefore the function is a linear function following the form y = mx + b\n");
	printf("y = 0\n");
	printf("m = %lf\n", b);
	printf("b = %lf\n\n", c);
}

void img_solution (double a, double b, double c, double ans, double ans2)
{
	printf("\nThe function is: %lfx^2 + %lfx + %lf = 0\n\n", a, b, c);
	printf("The solutions of x are non-real values\n\n");
	printf("The first solution of the quadratic function is x = %lfi\n", ans);						//The i indicates that the value is imaginary
	printf("The second solution of this quadratic function is x = %lfi\n\n", ans2);					//The i indicates that the value is imaginary
}	

void solution (double a, double b, double c, double ans, double ans2)
{
	printf("\nThe function is: %lfx^2 + %lfx + %lf = 0\n\n", a, b, c);
	printf("The first solution of the quadratic function is x = %lf\n", ans);
	printf("The second solution of this quadratic function is x = %lf\n\n", ans2);
}	

void rescan(char *new_values)
{
	printf("Would you like to try again with new values? If yes, you can pick 3 new values. If not, this program will resume with current inputs\n");
	printf("Please put Y for yes, and N for no: ");
	scanf(" %c", new_values);
}	

void retry(char *redo)
{
	printf("Would you like to try the program again? Please put Y for yes and N for no: ");	
	scanf(" %c", redo);
}	

int main()
{
	double a, b, c, y, discri, false_discri, com_discri, sqrt_discri, ans, ans2;
	char redo, new_values;
		
	program_init();
	
inputs:
	gather_input(&a, &b, &c);
	
	if(a == 0){
		if(b == 0){
			printf("This function is neither a quadratic nor a linear function, please try again\n\n");
			goto inputs;
		}	
		linear_function_notifier(b, c);

rescan:	
	
		rescan(&new_values);
		switch(new_values){	
		
			case 'Y':
			case 'y':
				printf("\n");
				goto inputs;
				break;
	
			case 'N':
			case 'n':
				ans = -c / b;																				//Finding the solution to a linear function
				printf("\nThe function is 0 = %lfx + %lf\n\n", b, c);
				printf("The solution to this function is x = %lf\n\n", ans);
				break;
				
			default:																						
				printf("Invalid input, please try again\n");													
				printf("Please put y for yes and n for no: ");
				goto rescan;
		}	
	}	
/*
	If no exceptions are present, program proceeds to find roots for the function
*/	
	else{
		discri = (b*b) - (4*a*c);																	
	 		
/*
	Tests whether if the discriminant less than 0. 
	If the discriminant is less than 0, the answers would contain non-real values.
*/			
		if(discri < 0){	
		
			false_discri = discri * -1;																		//Turning the negative discriminant into a positive value so it has a real square root value
			sqrt_discri = sqrt(false_discri);																//Taking the normal square root
			com_discri = sqrt_discri * -1;																	//Reversing process of making a positive discriminant, therefore not changing any values. However, this value is imaginary
			ans 	= ((0 - b) + com_discri) / (2*a);														//First solution of the quadratic function based on the quadratic formula.
			ans2	= ((0 - b) - com_discri) / (2*a);														//Second solution of the quadratic function based on the quadratic formula.
			
			img_solution (a, b, c, ans, ans2);
		}	
		else{
			sqrt_discri = sqrt(discri);
			ans 	= ((-b) + sqrt_discri) / (2*a);															//First solution of the quadratic function based on the quadratic formula.
			ans2	= ((-b) - sqrt_discri) / (2*a);															//Second solution of the quadratic function based on the quadratic formula.
			
			solution (a, b, c, ans, ans2);
		}
	}
	
/*
	Prompts a question whether if the user would like to repeat the program again.
	If yes, the user can input 3 new values to repeat the process.
	If not, program exits with a farewell message.
*/	
retrying_scan:
	
	retry(&redo);
	switch(redo){
		
		case 'Y':
		case 'y':
			printf("\n");
			printf("Please enter 3 new values for a, b, and c\n");
			goto inputs;
			break;
			
		case 'N':
		case 'n':
			printf("\nI hope this program helped you. Feel free to use this again, as it is always right here. Goodbye!\n\n");
			exit(0);
			break;
			
		default:
			printf("Invalid input, please try again\n");
			printf("Please put y for yes and n for no: ");
			goto retrying_scan;
	}
	
	return(0);
}
