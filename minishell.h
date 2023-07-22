#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

/**
 * descript: this is token_type;
 *
*/
enum e_type
{
	WORD = 1,
	CMD,
	ARG,
	PIPE,
	REDIR,
	LIM,
	D_GRT,
	D_LSR,
	GRT,
	LSR,
	EXPEND
};

typedef struct s_token
{
	e_type			type;
	char			*word;
	struct s_token	*next;
}	t_token;

typedef struct s_redir
{
	e_type			type;
	char			*name;
	struct s_redir	*left;
	struct s_redir	*right;
}	t_redir;

typedef struct s_cmd
{
	struct *s_redir	root_redir;
	char			**word;
	struct s_cmd	*next;
}				t_cmd

#endif
