/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_isalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:10:27 by kyolee            #+#    #+#             */
/*   Updated: 2022/10/04 16:29:32 by yichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	else
		return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (8);
	else
		return (0);
}
