/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltin_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:39:20 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/01 08:52:16 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	old_pwd(t_pipex *p_strct, char *oldpath)
{
	int	envnum;

	envnum = get_envnum(p_strct->data->envp, "OLDPWD");
	if (envnum != -1)
	{
		free(p_strct->data->envp[envnum]);
		p_strct->data->envp[envnum] = ft_strjoin("OLDPWD=", oldpath);
	}
	else
		addback_env(p_strct, ft_strjoin("OLDPWD=", oldpath));
	return ;
}

static int	no_such_file(char *str)
{
	ft_putstr_fd("cd: no such file or directory: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

static int	cd_min(t_pipex *p_strct)
{
	int	envnum;

	envnum = get_envnum(p_strct->data->envp, "OLDPWD=");
	if (envnum != -1)
		chdir(p_strct->data->envp[envnum] + 7);
	else
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		return (1);
	}
	return (0);
}

int	bltin_cd(t_pipex *p_strct, char **cmd)
{
	int		envnum;
	char	*cwd;
	char	*oldpath;

	oldpath = getcwd(NULL, 0);
	envnum = get_envnum(p_strct->data->envp, "HOME=");
	if (!cmd[1] && envnum != -1 && chdir(p_strct->data->envp[envnum] + 5) == -1)
		return (no_such_file(p_strct->data->envp[envnum] + 5));
	if (cmd[1] && cmd[1][0] == '-' && cmd[1][1] == '\0' && cd_min(p_strct) == 1)
		return (1);
	else if (cmd[1] && chdir(cmd[1]) == -1)
		return (no_such_file(cmd[1]));
	cwd = getcwd(NULL, 0);
	cwd += ft_revchrsrch(cwd, '/') + 1;
	free(p_strct->data->path_prefix);
	p_strct->data->path_prefix = ft_strdup(cwd);
	old_pwd(p_strct, oldpath);
	return (0);
}
