/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:28:25 by yichoi           #+#    #+#             */
/*   Updated: 2022/10/04 16:28:25 by yichoi          ###   ########.fr       */
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
