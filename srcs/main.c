/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:50:41 by khirsig           #+#    #+#             */
/*   Updated: 2021/09/29 11:00:25 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	while (1)
	{
		char	*str = readline("TestPrompt: ");
		printf("%s: %d\n", str, access(str, F_OK));
		signal(SIGQUIT, SIG_IGN);
		//signal(SIGQUIT, signal_handler);
		signal(SIGINT, signal_handler);
	}
	int i = 0;
	while (envp[i] != NULL)
	{
		if (strnstr(envp[i], "PATH", strlen(envp[i])) != 0)
			break ;
		i++;
	}
	// printf("PATH: %s\n", envp[i]);
	// char *ptr = strtok(envp[i], ":");
	// while(ptr != NULL)
	// {
	// 	printf("'%s'\n", ptr);
	// 	ptr = strtok(NULL, ":");
	// }
	//system("leaks a.out > leaks.txt");
	return (0);
}
