/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:50:41 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/01 19:49:33 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_struct	vars;

	vars.envp = envp; 
	vars.fd_in = open("fd_in", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	vars.fd_out = open("fd_out", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	(void)argc;
	(void)argv;
	while (1)
	{
		char	*str = readline("TestPrompt: ");
		if (str == NULL)
			break;
		if (str && *str)
			add_history(str); 
		specifier(&vars, str);
		//printf("%s\n", str);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
	}
	// int fd = open("test", O_CREAT);
	// printf("fd: %d\n", fd);
	return (0);
}
