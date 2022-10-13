/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cleaners.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:29:26 by sumsong           #+#    #+#             */
/*   Updated: 2022/10/04 16:29:26 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_2d(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	str = NULL;
}

void	free_tree(t_node *node)
{
	if (!node)
		return ;
	if (node->type == T_HEREDOC)
		unlink(node->right->content);
	free_tree(node->left);
	free_tree(node->right);
	if (node->content)
		free(node->content);
	free(node);
}

void	cleaner(char *str, t_struct *ds, t_token *token)
{
	if (str)
		free(str);
	if (ds && ds->root_node)
	{
		free_tree(ds->root_node);
		ds->root_node = NULL;
	}
	if (ds && ds->head_token)
	{
		ft_lstclear(&(ds->head_token));
		ds->head_token = NULL;
	}
	if (token)
		ft_lstclear(&token);
}
