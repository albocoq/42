#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char *str = argv[1];
	int nwords = 0;
	int len;
	if (argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return (0);
	}

	int count = 0;
	while (str[count])
	{
		if (str[count] == ' ')
			count++;
		else
		{
			while ((str[count] >= 'a' && str[count] <= 'z') || (str[count] >= 'A' && str[count] <= 'Z'))
				count++;
			nwords++;
		}
	}
	len = count;
	count = 0;
	int words = 0;
	while (str[count])
	{
		if (str[count] == ' ')
			count++;
		else
		{
			words++;
			while ((str[count] >= 'a' && str[count] <= 'z') || (str[count] >= 'A' && str[count] <= 'Z'))
			{
				if (nwords == words)
				{
					while(str[count] != ' ' && str[count] && count < len)
					{
						write(1, &str[count], 1);
						count++;
					}
					break ;
				}
				count++;
			}
		}
	}
	
	write(1, "\n", 1);
}
