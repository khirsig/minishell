/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:23:04 by khirsig           #+#    #+#             */
/*   Updated: 2021/11/27 12:39:35 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

int	runbltin(t_pipex *p_strct, char **cmd, int cmdnbr)
{
	p_strct->data->is_child = FALSE;
	if (cmdnbr == 0)
		return (bltin_cd(p_strct, cmd));
	if (cmdnbr == 1)
		bltin_exit(p_strct, cmd);
	if (cmdnbr == 2)
		bltin_pikachu(p_strct);
	if (cmdnbr == 3)
		bltin_pwd(p_strct, cmd);
	if (cmdnbr == 4)
		bltin_echo(p_strct, cmd);
	if (cmdnbr == 5)
		bltin_env(p_strct, cmd);
	if (cmdnbr == 6)
		bltin_unset(p_strct, cmd);
	if (cmdnbr == 7)
		return (bltin_export(p_strct, cmd));
	return (0);
}
