#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	int x = 1;
	int y = 0;
	int count = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[x])
	{
		y = 0;
		while (argv[x][y])
		{
			count++;
			y++;
		}
		count++;
		x++;
	}
	y = 0;
	x = 1;
	int c = 0;
	char word_to_print[count];
	while (argv[x])
	{
		y = 0;
		while (argv[x][y])
		{
			word_to_print[c] = argv[x][y];
			c++;
			y++;
		}
		x++;
	}
	x = 1;
	while (count > x)
	{
		x++;
		write(1, &word_to_print[count - x], 1);
	}
	write(1, "\n", 1);
	return (0);
}
