/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:33:30 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/06 15:55:01 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void run_fullpathcmd(char **cmd, char **envp)
{
	char *full_path;

	if (access(cmd[0], F_OK) == -1)
	{
		ft_putstr_fd("zsh: no such file or directory: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
	}
	full_path = ft_strdup(cmd[0]);
	cmd[0] += ft_revchrsrch(cmd[0], '/');
	execve(full_path, cmd, envp);
	free(full_path);
	return ;
}

static void	ft_run_err(t_pipex *p_strct, int index, char **cmd, char *cmd_prefix)
{
	if (p_strct->envpath == NULL)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
		free(cmd_prefix);
		exit(EXIT_SUCCESS);
	}
	if (p_strct->envpath[index] == NULL)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
		free(cmd_prefix);
		exit(EXIT_SUCCESS);
	}
}

void	runcmd(t_pipex *p_strct, char **cmd, char **envp)
{
	char	*temp;
	char	*cmd_prefix;
	char	*full_cmdpath;
	int		index;

	cmd_prefix = ft_strdup(cmd[0]);
	if (ft_chrsrch(cmd[0], '/') != -1)
	{
		run_fullpathcmd(cmd, envp);
		exit(EXIT_SUCCESS);
	}
	index = 0;
	ft_run_err(p_strct, index, cmd, cmd_prefix);
	while (p_strct->envpath[index] != NULL)
	{
		temp = ft_strjoin(p_strct->envpath[index], "/");
		full_cmdpath = ft_strjoin(temp, cmd_prefix);
		if (access(full_cmdpath, F_OK) != -1)
		{
			execve(full_cmdpath, cmd, envp);
			free(cmd_prefix);
			exit(EXIT_SUCCESS);
		}
		free(temp);
		free(full_cmdpath);
		index++;
		ft_run_err(p_strct, index, cmd, cmd_prefix);
	}
}
