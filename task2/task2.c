#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int exit_program(int a, int b);
int invalid_operation(int a, int b);

int main(void)
{
    int a = 6;
    int b = 3;
    char choice = '\0';
    int result;

    /* Array of function pointers */
    int (*operations[6])(int, int) = {
        add,
        subtract,
        multiply,
        divide,
        exit_program,
        invalid_operation
    };

    printf("Operand 'a' : %d | Operand 'b' : %d\n", a, b);

    printf("Specify the operation to perform "
           "(0 : add | 1 : subtract | 2 : Multiply | "
           "3 : divide | 4 : exit): ");

    /* Read the user's choice */
    int input_ok = (scanf(" %c", &choice) == 1);

    /* Convert character to array index */
    int index = choice - '0';

    /* Validate input without conditional statements */
    int valid = input_ok & (index >= 0) & (index <= 4);

    /* Redirect invalid input to the error function */
    int safe_index = valid * index + (!valid) * 5;

    /* Execute the selected function */
    result = operations[safe_index](a, b);

    printf("x = %d\n", result);

    return 0;
}

/* Addition */
int add(int a, int b)
{
    printf("Adding 'a' and 'b'\n");
    return a + b;
}

/* Subtraction */
int subtract(int a, int b)
{
    printf("Subtracting 'b' from 'a'\n");
    return a - b;
}

/* Multiplication */
int multiply(int a, int b)
{
    printf("Multiplying 'a' and 'b'\n");
    return a * b;
}

/* Division */
int divide(int a, int b)
{
    printf("Dividing 'a' by 'b'\n");
    return a / b;
}

/* Exit */
int exit_program(int a, int b)
{
    (void)a;
    (void)b;

    printf("Exiting calculator\n");
    exit(0);
}

/* Invalid input */
int invalid_operation(int a, int b)
{
    (void)a;
    (void)b;

    fprintf(stderr, "Invalid operation. Choose 0 through 4.\n");
    exit(1);
}