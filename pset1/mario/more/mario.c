#include<stdio.h>

int read_height()
{
	int height;
	do {
		scanf("%d", &height);
	} while(height <= 0 || height > 23);

	return height;
}

void draw_pyramid(int height)
{
	for(int i = 0; i < height; i++)
	{
		for(int k = 0; k < height - i - 1; k++)
		{
			printf(" ");
		}

		for(int j = 0; j <= i; j++)
		{
			printf("#");
		}

		printf("  ");

		for(int j = 0; j <= i; j++)
		{
			printf("#");
		}		

		printf("\n");
	}
}

int main()
{
	int height = read_height();

	draw_pyramid(height);
}