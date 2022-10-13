/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:28:25 by sumsong           #+#    #+#             */
/*   Updated: 2022/10/04 16:28:25 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pwd(char **args)
{
	char	path[PATH_MAX];

	(void)args;
	if (getcwd(path, PATH_MAX) == NULL)
	{
		set_or_get_status(errno);
		return ;
	}
	printf("%s\n", path);
	set_or_get_status(0);
}
