/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:58:00 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/01 15:25:15 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TRUE 1
# define FALSE 0
# define ERROR -1

/*
** -----------------------------------------------------------------------------
** Includes
*/
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <string.h>
# include <termios.h>
# include <fcntl.h>
# include "libft/libft.h"
/*
** -----------------------------------------------------------------------------
** Structs and typedef.
*/
typedef struct s_struct
{
	char	**envp;
	char	*cmd;
	int		fd_in;
	int		fd_out;
}				t_struct;
/*
** -----------------------------------------------------------------------------
** Function prototypes
*/
//signals.c
void	signal_handler(int sig);
//parsing.c
void	specifier(t_struct *vars, char *str);
//redirections.c
void	output(t_struct *vars, char *file);


#endif