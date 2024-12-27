#include <stdio.h>

int main(int argc, char** argv)
{
	int input_number = 0;
	int sum = 1;
	
	printf("Enter number to calc factorial: ");
	scanf("%d", &input_number);

	for(int i = 1; i <= input_number; i++)
	{
		sum *= i;
	}

	printf("Sum is: %d.\n", sum);

	return 0;
}
