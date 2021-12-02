/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:58:00 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/02 08:38:11 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# define TRUE 1
# define FALSE 0
# define ERROR -1

/*
** -----------------------------------------------------------------------------
** Includes
*/
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libs/libft/libft.h"
# include "minishell.h"

/*
** -----------------------------------------------------------------------------
** Structs and globals
*/

typedef struct s_pipex {
	char		**cmd;
	char		**envpath;
	t_data		*data;
	int			end[2];
	int			fd_temp;
	int			cmdpathfound;
	pid_t		child;
}				t_pipex;

const static char	*g_bltin_cmds[8] = {
	"cd",
	"exit",
	"pwd",
	"echo",
	"env",
	"unset",
	"export",
	NULL
};

/*
** -----------------------------------------------------------------------------
** Function prototypes
*/
int		ft_chrsrch(char *haystack, char needle);
int		ft_revchrsrch(char *haystack, char needle);
int		get_envnum(char **envp, char *needle);

int		execute(char **input, t_data *data);
int		error_handler(t_pipex *p_strct, char *input);
int		runcmd(t_pipex *p_strct, char **cmd);
int		forking(t_pipex *p_strct);
char	**get_envpath(t_pipex *p_strct);
char	**split_args(char *temp);

int		bltin_cd(t_pipex *p_strct, char **cmd);
int		bltin_compare(char *needle);
int		bltin_init(t_pipex *p_strct);
void	bltin_exit(t_pipex *p_strct, char **cmd);
void	bltin_pikachu(t_pipex *p_strct);
int		bltin_pwd(t_pipex *p_strct, char **cmd);
void	bltin_echo(t_pipex *p_strct, char **cmd);
void	bltin_env(t_pipex *p_strct, char **cmd);
void	bltin_unset(t_pipex *p_strct, char **cmd);
int		bltin_export(t_pipex *p_strct, char **cmd);
int		runbltin(t_pipex *p_strct, char **cmd, int cmdnbr);
void	addback_env(t_pipex *p_strct, char *str);
void	rotate_env(t_data *data, int envnum);
void	replace_env(t_data *data, char *str, int envnum);
int		add_env(t_pipex *p_strct, char *cmd);

#endif