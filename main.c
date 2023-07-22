#include "minishell.h"

void	print_token(void *content)
{
	printf("token: %s\n", content);
}

int	main(void)
{
	char	*read_line;
	t_list	*token_list = NULL; //t_token

	while (1)
	{
		read_line = readline("minishell$ ");
		if (!read_line)
		{
			printf("exit");
			continue ; //추후 exit 빌트인 함수 구현 시 추가 예정
		}
		add_history(read_line);
		// read_line == null <- eof ctrl + d
		if (tokenize(read_line, &token_list) != 0)
		{
			ft_lstclear(&token_list, free);
		}
		ft_lstiter(token_list, print_token);
		free(read_line);
	}
}

// void	ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	if (!lst || !f)
// 		return ;
// 	while (lst->next != NULL)
// 	{
// 		f(lst->content);
// 		lst = lst->next;
// 	}
// 	f(lst->content);
// }

