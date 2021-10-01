/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:58:00 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/01 10:19:32 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
# include <readline/readline.h>
# include <readline/history.h>
/*
** -----------------------------------------------------------------------------
** Structs and typedef.
*/
typedef struct s_data {
	char	**bltin_cmds;
	char	*path_prefix;
	int		fd_in;
	int		fd_out;
}				t_data;

typedef struct s_pipex {
	char ***cmd;
	char **envpath;
	int	end[2];
	int cmdpathfound;
	int	cmd_amt;
	int	fd_temp;
	int	cmd_count;
	pid_t child;
}				t_pipex;
/*
** -----------------------------------------------------------------------------
** Function prototypes
*/
char	*ft_strcpy(char *dest, const char *src);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
int		ft_chrsrch(char *haystack, char needle);
int		ft_revchrsrch(char *haystack, char needle);

int		pipex(char *input, char **envp, t_data *data);
int		error_handler(t_pipex *p_strct, char *input);
void	runcmd(t_data *data, t_pipex *p_strct, char **cmd, char **envp);
int		forking(t_pipex *p_strct, t_data *data, char **envp);
void	parsing_envpath(t_pipex *p_strct, char **envp);

void	bltin_cd(t_data *data, char **cmd);
int		bltin_compare(t_data *data, char *needle);
int		bltin_init(t_data *data);

#endif