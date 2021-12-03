/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:45:01 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/03 11:38:59 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_envp(t_data *data)
{
	int	index;

	index = 0;
	if (data->envp == NULL)
	{
		free(data->envp);
		return ;
	}
	while (data->envp[index] != NULL)
	{
		free(data->envp[index]);
		index++;
	}
	free(data->envp[index]);
	free(data->envp);
	return ;
}

void	reg_exit(t_data *data)
{
	write(1, "exit\n", 5);
	reset(data);
	exit(0);
	return ;
}

int	prefix(t_data *data, char **shellprefix)
{
	char	*temp;

	temp = ft_strjoin("\033[1;32m➜\033[1;36m  ", data->path_prefix);
	*shellprefix = ft_strjoin(temp, "\033[1;33m ✗\033[0m ");
	free(temp);
	temp = NULL;
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*shellprefix;

	(void)argc;
	(void)argv;
	init_data(&data, envp);
	tcgetattr(STDIN_FILENO, &data.original_attr);
	while (1)
	{
		set_signal(&data);
		prefix(&data, &shellprefix);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
		data.str = readline(shellprefix);
		if (!data.str)
			reg_exit(&data);
		if (data.str && *data.str)
			add_history(data.str);
		free(shellprefix);
		shellprefix = NULL;
		if (*data.str)
			lex_analyzer(&data);
		reset(&data);
	}
	return (0);
}
