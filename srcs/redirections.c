/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:29:30 by pweinsto          #+#    #+#             */
/*   Updated: 2021/10/01 19:49:30 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void	parse_re(char *str)
// {

// }

void	output(t_struct *vars, char *file)
{
	char	*buf;
	char	*str = "abcdefgh";

	write(vars->fd_in, &str, 10);
	close(vars->fd_in);
	buf = malloc(sizeof(char) * 10);
	vars->fd_in = open("fd_in", O_RDWR);
	read(vars->fd_in, &buf, 8); // write a function for size
	close(vars->fd_in);
	printf("buf: %s\n", buf);
	vars->fd_out = open(file, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	write(vars->fd_out, buf, 8);
	close(vars->fd_out);
}

// void	input(t_struct *vars, char *file)
// {

// }