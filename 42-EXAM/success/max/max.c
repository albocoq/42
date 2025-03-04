
#include <stdio.h>
int	max(int* tab, unsigned int len)
{
	int lastnum = 0;
	int count = 0;

	if (len <= 0)
		return (0);
	while (tab[count])
	{
		if (lastnum < tab[count])
			lastnum = tab[count];
		count++;
	}
	return (lastnum);
}
