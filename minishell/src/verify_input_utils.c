#include "minishell.h"

int	inside_quotes(const char *str, int i)
{
	int	inside_single_quote;
	int	inside_double_quote;
	int	j;

	inside_single_quote = 0;
	inside_double_quote = 0;
	j = 0;
	while (j < i)
	{
		if (str[j] == '\'')
			inside_single_quote = !inside_single_quote;
		else if (str[j] == '\"')
			inside_double_quote = !inside_double_quote;
		j++;
	}
	if (inside_single_quote || inside_double_quote)
		return (1);
	return (0);
}


int	is_delimiter(char c)
{
	if(ft_strchr(" \t\n\v\f\r", c) != NULL)
		return (1);
	return (0);
}

int next_is_valid(const char *str, int start)
{
	int	i;

	i = start;
	while (str[i] && is_delimiter(str[i]))
		i++;
	if(str[i] == '\0')
		return (0);
	if (str[i] == '>' || str[i] == '<')
		return (0);
	return (1);
}
