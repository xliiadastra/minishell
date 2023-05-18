/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_case2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:29:15 by yichoi           #+#    #+#             */
/*   Updated: 2022/10/04 16:29:15 by yichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	case_new_word(t_token_info *info)
{
	info->start_idx = info->cur_idx;
	info->token_type = T_WORD;
}

int	is_case_token_syntax_error(t_token_info *info)
{
	if (info->sin_quoted || info->dou_quoted || info->double_piped)
	{
		printf("ERROR: syntax error!\n");
		set_or_get_status(SYNTAX_ERROR);
		cleaner(NULL, NULL, info->token_list);
		return (1);
	}
	return (0);
}
