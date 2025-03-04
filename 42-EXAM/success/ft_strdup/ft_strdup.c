char    *ft_strdup(char *src)
{
	int count = 0;
	int src_size = 0;
	char *copy_src;

	while (src[count])
		count++;
	src_size = count;
	count = 0;
	copy_src = malloc(src_size * sizeof(char *));
	
	while (count < src_size)
	{
		copy_src[count] = src[count];
		count++;
	}
	return copy_src;
}
