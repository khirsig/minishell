/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:50:41 by khirsig           #+#    #+#             */
/*   Updated: 2021/09/29 11:37:09 by khirsig          ###   ########.fr       */
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

	data = malloc(sizeof(t_data));
	ft_bzero(data, sizeof(t_data));
	(void)argv;
	(void)argc;
	while(42)
	{
		// write(2, "Tes1\n", 5);
		// ret = readline("\033[1;32m➜\033[1;36m  testshell \033[1;34mgit:(\033[1;31mmaster\033[1;34m)\033[1;33m ✗\033[0m ");
		// write(2, "Tes2\n", 5);
		write(1, "\033[1;32m➜\033[1;36m  testshell \033[1;34mgit:(\033[1;31mmaster\033[1;34m)\033[1;33m ✗\033[0m ", 79);
		// rl_replace_line("Test\n", 2);
		while ((bytes = read(1, &c, 1)) && c != '\n')
			ret = ft_readadd(ret,c);
		data->fd_in = 0;
		data->fd_out = 1;
		if (ret[0])
			pipex(ret, envp, data);
		// write(2, "Te4\n", 5);
		if (ret)
		{
			free(ret);
			ret = NULL;
		}
	}
	// write(2, "Test\n", 5);
	system("leaks minishell > leaks.txt");
	return (0);
}
