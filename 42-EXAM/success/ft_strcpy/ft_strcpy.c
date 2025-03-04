char *ft_strcpy(char *dest, const char *src)
{
	int dest_size = 0;
	int src_size = 0;
	int count = 0;

	while (dest[count])
	{
		dest_size++;
		count++;
	}
	count = 0;
	while (src[count])
	{
		src_size++;
		count++;
	}
	count = 0;
	while (count < src_size)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}	
