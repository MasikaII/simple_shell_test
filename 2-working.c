#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * main - Shell Main Function
 *
 * Return: Integer Value
 */

int main(void)
{
	int val;
	int i;
	char *argv[10];
	char *path;
	size_t n = 10;
	char *buff = NULL;
	char *delim = " /";
	char *token;
	char cmd[100];

	while (1)
	{
		printf("#Ace-;)$ ");
		getline(&buff, &n, stdin);
		i = strlen(buff);
		buff[i - 1] = '\0';
		char *str = malloc(sizeof(char) * strlen(buff));

		strcpy(str, buff);
		token = strtok (str, delim);
		argv[0] = token;
		i = 1;
		while (token)
		{
			token = strtok(NULL, delim);
			argv[i++] = token;
		}
printf("\n%s\n", argv[1]);
		if (argv[0] == "bin")
		{
			strcpy (cmd, "/bin/");
			strcat (cmd, argv[1]);
		}
		else
		{
			strcpy (cmd, "/bin/");
			strcat (cmd, argv[0]);
		}
		if (fork() != 0)
			wait(NULL);
		else
		{
			val = execve(cmd, argv, NULL);
			if (val == -1)
				perror("./shell");
		}
	}
	printf("Done with execve\n");
	free(buff);

	return (0);
}

