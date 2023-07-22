#include "minishell.h"

int	main()
{
	char	*read_line;

	while (1)
	{
		read_line = readline("minishell$ ");
		// read_line == null <- eof ctrl + d
		printf("read line: %s\n", read_line);
	}
}
