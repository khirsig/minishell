/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:33:30 by khirsig           #+#    #+#             */
/*   Updated: 2021/11/25 08:53:44 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static int run_fullpathcmd(char **cmd, char **envp)
{
	char *full_path;

	if (access(cmd[0], F_OK) == -1)
	{
		ft_putstr_fd("minishell: no such file or directory: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
		return (127);
	}
	full_path = ft_strdup(cmd[0]);
	cmd[0] += ft_revchrsrch(cmd[0], '/');
	execve(full_path, cmd, envp);
	free(full_path);
	return (0);
}

static void	ft_run_err(t_pipex *p_strct, int index, char **cmd, char *cmd_prefix)
{
	if (p_strct->envpath == NULL)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
		free(cmd_prefix);
		exit(127);
	}
	if (p_strct->envpath[index] == NULL)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
		free(cmd_prefix);
		exit(127);
	}
}

int	runcmd(t_pipex *p_strct, char **cmd)
{
	char	*temp;
	char	*cmd_prefix;
	char	*full_cmdpath;
	int		index;
	int		is_bltin;

	is_bltin = 0;
	is_bltin = bltin_compare(cmd[0]);
	if (is_bltin != -1)
		exit(runbltin(p_strct, cmd, is_bltin));
	cmd_prefix = ft_strdup(cmd[0]);
	if (ft_chrsrch(cmd[0], '/') != -1)
		exit(run_fullpathcmd(cmd, p_strct->data->envp));
	index = 0;
	ft_run_err(p_strct, index, cmd, cmd_prefix);
	while (p_strct->envpath[index] != NULL)
	{
		temp = ft_strjoin(p_strct->envpath[index], "/");
		full_cmdpath = ft_strjoin(temp, cmd_prefix);
		if (access(full_cmdpath, F_OK) != -1)
		{
			execve(full_cmdpath, cmd, p_strct->data->envp);
			free(cmd_prefix);
			exit(EXIT_SUCCESS);
		}
		free(temp);
		free(full_cmdpath);
		index++;
		ft_run_err(p_strct, index, cmd, cmd_prefix);
	}
	exit (EXIT_SUCCESS);
}
