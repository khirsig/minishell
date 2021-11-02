/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:45:01 by pweinsto          #+#    #+#             */
/*   Updated: 2021/11/02 14:33:52 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_lex	*lex;
	t_data	data;
	char	*shellprefix;
	char	*temp;
	char	*str;

	data.path_prefix = ft_strdup("minishell");
	(void)argc;
	(void)argv;
	data.envp = envp;
	while (1)
	{

		temp = ft_strjoin("\033[1;32m➜\033[1;36m  ", data.path_prefix);
		shellprefix = ft_strjoin(temp, "\033[1;33m ✗\033[0m ");
		free(temp);
		temp = NULL;

		str = readline(shellprefix);

		free(shellprefix);
		shellprefix = NULL;
		lex = NULL;

		lex_analyzer(lex, str, &data);
		// if (str && *str)
		// 	add_history(str);
	}
	return (0);
}


// two CDQUOTES following