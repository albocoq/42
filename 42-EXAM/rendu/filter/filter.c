#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv){

	if (argc != 2 || !argv[1][0])
	{
		perror("Error: ");
		return 1;
	}

	char *value = argv[1];
	int len_value = strlen(value);
	char *buf = malloc(1024);
	if (!buf) {
		perror("Error");
		return 1;
	}
	int n;

	while ((n = read(0, buf, 1024)) > 0) {
		for (int i = 0; i < n; i++) {
			int match = 1;

			for (int j = 0; j < len_value; j++) {
				if (buf[i + j] != value[j])
				{
					match = 0;
					break;
				}
			}
			if (match) {
				for (int k = 0; k < len_value; k++) {
					printf("*");
				}
			} else {
				printf("%c", buf[i]);
			}
		}
	}
	if (n == -1) {
		perror("Error: ");
		free(buf);
		return 1;
	}
	free(buf);
	return 0;
}
