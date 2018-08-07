/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:26:58 by thou              #+#    #+#             */
/*   Updated: 2018/08/07 01:33:37 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	ft_background(t_env *e)
{
	int		i;

	i = -1;
	while (++i < HEIGHT * WIDTH)
		*(unsigned int*)(e->data + i) = 0x343434;
}

void	ft_menu(t_env *e)
{
	e->test = 0;
}

void	ft_score(t_env *e)
{
	e->test = 0;
}

void	ft_map(t_env *e)
{
	e->test = 0;
}

void	ft_resault(t_env *e)
{
	e->test = 0;
}
