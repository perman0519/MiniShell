#include "minishell.h"

/**
1. line을 순회하며 공백을 찾는다.
	" or ' 짝을 찾는다
1-1. 공백을 찾을 시 인덱스를 기억한다.
2. 인용부호가 등장하면 플래그를 설정하고, 짝이 맞는 인용부호가 등장할 때까지 리터럴로 취급한다.
	if (line[i] =='\'')
		flag = '\''; 첫 인용부호
	if (line[i] =='\'')
		flag = 0; 다음 인용부호
3.
*/

//리드라인 널 처리 -> signal 함수 사용하자 cmd + d일 때
//"가 하나 있을 때 에러처리 int로 리턴 넘겨서 메인에서 바로 종료 되게 하기
//연결리스트 프리
//히스토리에 커맨드
//놈 에러, 함수 쪼개기
//5개만 하면됨

void	op_token(t_list **token_list, char **line)
{


}

int	is_op(char c)
{
	return (c == '<' || c == '>' || c == '|');
}

int	tokenize(char *line, t_list **token_list)
{
	t_list	*new_token;
	char	*token;
	int		token_size;
	char	flag;

	flag = 0;
	while (*line != '\0')
	{
		token_size = 0;
		while (*line == ' ')
			line++;
		while (*line)
		{
			if (*line == '\"' || *line == '\'')
			{
				if (flag == 0)
					flag = *line;
				else if (flag == *line)
					flag = 0;
			}
			else if (flag == 0 && is_op(*line)) // aa<<
			{
				op_token(token_list, &line);
			}
			else if (flag == 0) //문자, 숫자, _) // aa<<
			{
				nor_token
			}
			else if (flag == 0 && *line == ' ')
				break ;
			line++;
			token_size++;
		}
		if (*line && flag != 0)
			return (0);
		if (token_size > 0)
		{
			token = ft_substr(line - token_size, 0, token_size);
			new_token = ft_lstnew(token);
			if (new_token == NULL)
				exit(1);
			ft_lstadd_back(token_list, new_token);
		}
	}
	return (flag);
}

/**
*
* << >> < > |
<, > 가 나오는 경우 다음 문자가 현재 문자와 다를 경우
현재 문자를 리스트에 삽입, 같을 경우 라인++, token++

*/
