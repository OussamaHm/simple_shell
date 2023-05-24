/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			printf("%d is even\n", i);
		else
			printf("%d is odd\n", i);
	}

	return 0;
}
