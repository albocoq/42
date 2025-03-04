#include <unistd.h>

int countalpha(char a)
{
	int count = 0;
	char aletter = 'a';

	if (a >= 'A' && a <= 'Z')
		aletter = 'A';
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
	{
		
		while (aletter != a)
		{
			aletter++;
			count++;
		}
		return (count);
	}
	return (0);
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int count = 0;
	while (argv[1][count])
	{
		char c = argv[1][count];
		int num = 0;

		while (num <= countalpha(c))
		{
			write(1, &c, 1);
			num++;
		}	
		count++;
	}
	write(1, "\n", 1);

}
