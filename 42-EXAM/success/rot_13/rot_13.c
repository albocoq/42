#include <unistd.h>

int ischaracter(char a)
{
	return ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'));
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
		char a = argv[1][count];
		char newcharacter; 
		if (ischaracter(argv[1][count]))
		{
			if ((a >= 'a' && a <= 'm') || (a >= 'A' && a <= 'M'))
				newcharacter = argv[1][count] + 13;
			else if ((a >= 'n' && a <= 'z') || (a >= 'N' && a <= 'Z'))
				newcharacter = argv[1][count] - 13;
		}
		else
			newcharacter = argv[1][count];
		write(1, &newcharacter, 1);
		count++;
	}
	write(1, "\n", 1);
}
