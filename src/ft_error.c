#include "pipex.h"

void    ft_error(char *str)
{
	str = ft_strjoin(strerror(errno), ft_strjoin(": ", str));
	write (2, str, ft_strlen(str));
	write (2, "\n", 1);
	free(str);
    exit (1);
}

int	ft_str_error(char *str)
{
	write (2, str, ft_strlen(str));
	return (2);
}
