#include <stdio.h>

int main(int argc, char** argv)
{
	int operator_num = 0;
	int operand_1 = 0;
	int operand_2 = 0;
	int sum = 0;

	printf("Please Enter a operator\n1: ADD\n2: SUBT\n3: DIVIDE\n4: MULT\n: ");
	scanf("%d", &operator_num);

	printf("Please Enter Ur First Number: ");
	scanf("%d", &operand_1);

	printf("Please Enter Ur Second Number: ");
	scanf("%d", &operand_2);

	switch (operator_num)
	{
		case 1:
			sum = operand_1 + operand_2;
			printf("%d + %d = %d", operand_1, operand_2, sum);
			break;
		case 2:
			sum = operand_1 - operand_2;
			printf("%d - %d = %d", operand_1, operand_2, sum);
			break;
		case 3:
			sum = operand_1 * operand_2;
			printf("%d * %d = %d", operand_1, operand_2, sum);
			break;
		case 4:
			sum = operand_1 / operand_2;
			printf("%d / %d = %d", operand_1, operand_2, sum);
			break;
		default:
			printf("IDK HOW U GOT HERE G BOSS\n");
	}

	return 0;
}
