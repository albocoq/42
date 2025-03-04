#include <unistd.h>
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int y = 0;

	while (argv[1])
	{
		while (argv[1][y])
		{
			if (argv[1][y] == '_')
			{
				int a = argv[1][y + 1] - 32;
				write(1, &a, 1);
				y++;
			}
			else
				write(1, &argv[1][y], 1);
			y++;
		}
		break ;
	}
	write(1, "\n", 1);
	return (0);

}
