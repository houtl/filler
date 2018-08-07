/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 01:07:53 by thou              #+#    #+#             */
/*   Updated: 2018/08/07 02:31:34 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

int		ft_key(t_env *e)
{
	e->test = 0;
	return (0);
}

int		ft_mouse(int key, int x, int y, t_env *e)
{
	if (key == 1)
	{
		if (e->pause == 0)
			e->pause = 1;
		else if (e->pause == 1)
			e->pause = 0;
	}
	ft_loop_key(e);
	return (0);
	x=0;
	y=0;
}
