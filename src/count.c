/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 16:45:11 by thou              #+#    #+#             */
/*   Updated: 2018/01/03 15:33:24 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern int fd;

void	ft_reset(t_env *e, int x, int y)
{
	int		i;
	int		j;

	j = -1;
	while (++j < e->yp)
	{
		i = -1;
		while (++i < e->xp)
		{
			if (e->piece[j][i] == '*')
				e->tab[e->aws[0] + j][e->aws[1] + i] = '.';
		}
	}
	e->tab[y][x] = e->p1;
}

void	ft_rempli(t_env *e)
{
	int		i;
	int		j;

	j = -1;
	while (++j < e->yp)
	{
		i = -1;
		while (++i < e->xp)
		{
			if (e->piece[j][i] == '*')
				e->tab[e->aws[0] + j][e->aws[1] + i] = e->p1;
		}
	}
}

int		ft_countcol(t_env *e)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	j = -1;
	while (++j < e->y)
	{
		i = -1;
		while (++i < e->x)
		{
			if (e->tmp[j][i] == e->p1)
			{
				if (i - 1 > 0 && e->tmp[j][i - 1] == e->p2)
					n++;
				if (i + 1 < e->x && e->tmp[j][i + 1] == e->p2)
					n++;
				if (j - 1 > 0 && e->tmp[j - 1][i] == e->p2)
					n++;
				if (j + 1 < e->y && e->tmp[j + 1][i] == e->p2)
					n++;
			}
		}
	}
	return (n);
}

int		ft_countdis(t_env *e)
{
	int		x;
	int		y;
	int		max;

	max = -1;
	y = -1;
	while (++y < e->y)
	{
		x = -1;
		while (++x < e->x)
		{
			if (e->tab[y][x] == e->p1)
			{
			if (e->x0 < e->x / 2)
				max = (x + y) > max ? (x + y) : max;
			else
				max = ((e->x + e->y) - (x + y)) > max ? ((e->x + e->y) - (x + y)) : max;
			}dprintf(fd, "%d\n", max);
		 }
	}
	return (max);
}
