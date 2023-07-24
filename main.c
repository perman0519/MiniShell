// #include "minishell.h"

// void	print_token(void *content)
// {
// 	printf("token: %s\n", content);
// }

// int	main(void)
// {
// 	char	*read_line;
// 	t_list	*token_list = NULL; //t_token

// 	while (1)
// 	{
// 		read_line = readline("minishell$ ");
// 		if (!read_line)
// 		{
// 			printf("exit");
// 			continue ; //추후 exit 빌트인 함수 구현 시 추가 예정
// 		}
// 		add_history(read_line);
// 		// read_line == null <- eof ctrl + d
// 		if (tokenize(read_line, &token_list) != 0)
// 		{
// 			ft_lstclear(&token_list, free);
// 		}
// 		ft_lstiter(token_list, print_token);
// 		free(read_line);
// 	}
// }

// // void	ft_lstiter(t_list *lst, void (*f)(void *))
// // {
// // 	if (!lst || !f)
// // 		return ;
// // 	while (lst->next != NULL)
// // 	{
// // 		f(lst->content);
// // 		lst = lst->next;
// // 	}
// // 	f(lst->content);
// // }

#include "minishell.h"

void make_token(char *input, t_list **token_list, int token_size)
{
	char *token;
	t_list *new_token;

	token = ft_substr(input, 0, token_size);
	new_token = ft_lstnew(token);
	if (new_token == NULL)
		exit(1);
	ft_lstadd_back(token_list, new_token);
}

void tokenized(char *input, t_list **token_list)
{
	int token_size;
	int flag;

	while (*input)
	{
		token_size = 0;
		flag = 0;
		while (*input == ' ')
			input++;
		while (*input && *input != ' ')
		{
			if (*input == '|')
			{
				if (token_size)
				{
					make_token(input - token_size, token_list, token_size);
					token_size = 0;
				}
				make_token(input++, token_list, 1);
			}
			else if (*input == '<' || *input == '>')
			{
				if (token_size)
				{
					make_token(input - token_size, token_list, token_size);
					token_size = 0;
				}
				if (*(input + 1) == *input)
				{
					make_token(input, token_list, 2);
					input += 2;
				}
				else
					make_token(input++, token_list, 1);
			}
			else if (*input == '\"' || *input == '\'')
			{
				flag = *input;
				while (flag && *input)
				{
					token_size++;
					input++;
					if (*input == flag)
					{
						token_size++;
						input++;
						flag = 0;
					}
				}
				if (flag)
					return;
			}
			else
			{
				token_size++;
				input++;
			}
		}
		printf("token size: %d\n", token_size);
		if (token_size)
			make_token(input - token_size, token_list, token_size);
	}
}

void list_print(void *content)
{
	printf("token: %s\n", content);
}

int main(void)
{
	char *input;
	t_list *token_list;

	token_list = NULL;
	while (1)
	{
		input = readline("$ ");
		printf("user input: %s\n", input);
		tokenized(input, &token_list);
		ft_lstiter(token_list, list_print);
		token_list = NULL;
	}
}
