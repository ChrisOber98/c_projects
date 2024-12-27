#include <stdio.h>

int main(int argc, char** argv)
{
	int input_num = 0;
	int next_num = 1;
	int cur_num = 0;
	int temp = 0;

	printf("Enter Number for Fib Seq: ");
	scanf("%d", &input_num);

	for(int i = 0; i < input_num; i++)
	{
		printf("%d ", cur_num);
		temp = next_num;
		next_num = cur_num + next_num;
		cur_num = temp;
	}

	return 0;
}
