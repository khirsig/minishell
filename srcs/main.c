/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:50:41 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/07 10:28:49 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	ft_bzero(data, sizeof(t_data));
	data->envp = envp;
	// data->fd_in = open("fd_in", O_CREAT|O_RDWR|O_TRUNC, S_IRWXU);
	//close(data.fd_in);
	// data->fd_out = open("fd_out", O_CREAT|O_RDWR|O_TRUNC, S_IRWXU);
	// close(data->fd_out);
	// dup2(data->fd_in, 0);
	// dup2(data->fd_out, 1);
	data->fd_in = 0;
	data->fd_out = 1;
	data->path_prefix = ft_strdup("minishell");
	(void)argc;
	(void)argv;
	while (1)
	{
		// write(1, "\033[1;32m➜\033[1;36m  ", 20);
		// write(1, data->path_prefix, ft_strlen(data->path_prefix));
		// write(1, "\033[1;33m ✗\033[0m ", 17);
		char	*str = readline(data->path_prefix);
		// if (str == NULL)
		// 	break;
		// if (str && *str)
		// 	add_history(str);
		pipex(str, envp, data);
		// dup2(0, data->fd_in);
		// dup2(1, data->fd_out);
		// specifier(&data, str);
		//printf("%s\n", str);
		// signal(SIGQUIT, SIG_IGN);
		// signal(SIGINT, signal_handler);
	}
	// int fd = open("test", O_CREAT);
	// printf("fd: %d\n", fd);
	return (0);
}
