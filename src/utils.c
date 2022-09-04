#include "so_long.h"

void	ft_reset(char *buffer)
{
	int	i;

	i = 0;
	while (i < 10000)
		buffer[i++] = 0;
}

int 	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}