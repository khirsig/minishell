/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:50:41 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/07 08:48:38 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char *ft_readadd(char *s, char c)
{
	size_t i;
	char *re;

	i = 0;
	if (s == NULL)
	{
		re = malloc(2);
		re[0] = c;
		re[1] = 0;
		return (re);
	}
	re = malloc(ft_strlen(s) + 2);
	while (i < ft_strlen(s))
	{
		re[i] = s[i];
		i++;
	}
	re[i] = c;
	i++;
	re[i] = 0;
	free (s);
	return (re);
}

int	main(int argc, char **argv, char **envp)
{
	char	*ret;
	t_data	*data;
	char c;
	int bytes;

	(void)argv;
	(void)argc;
	data = malloc(sizeof(t_data));
	ft_bzero(data, sizeof(t_data));
	dup2(data->fd_in, 0);
	dup2(data->fd_out, 1);
	data->path_prefix = ft_strdup("minishell");
	ret = NULL;
	while(42)
	{
		write(1, "\033[1;32m➜\033[1;36m  ", 20);
		write(1, data->path_prefix, ft_strlen(data->path_prefix));
		write(1, "\033[1;33m ✗\033[0m ", 17);
		while ((bytes = read(1, &c, 1)) && c != '\n')
			ret = ft_readadd(ret,c);
		if (ret != NULL)
			pipex(ret, envp, data);
		dup2(0, data->fd_in);
		dup2(1, data->fd_out);
		if (ret)
		{
			free(ret);
			ret = NULL;
		}
	}
	system("leaks minishell > leaks.txt");
	return (0);
}
