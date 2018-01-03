/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 01:43:20 by thou              #+#    #+#             */
/*   Updated: 2018/01/03 13:13:30 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fd = 0;

int		ft_check(t_env *e)
{
	int		j;
	int		i;
	int		z;

	z = 0;
	j = -1;
	while (++j < e->yp)
	{
		i = -1;
		while (++i < e->xp)
		{
			if (e->piece[j][i] == '*')
			{
				if (e->aws[0] + j < 0 || e->aws[0] + j >= e->y ||
						e->aws[1] + i < 0 || e->aws[1] + i >= e->x)
					return (0);
				if (e->tab[e->aws[0] + j][e->aws[1] + i] == e->p2)
					return (0);
				if (e->tab[e->aws[0] + j][e->aws[1] + i] == e->p1)
					z++;
			}
		}
	}
	return (z == 1 ? 1 : 0);
}

int		ft_poser(t_env *e, int x, int y)
{
	int		j;
	int		i;
	int		maxcol;
	int		maxdis;

	j = -1;
	while (++j < e->yp)
	{
		i = -1;
		while (++i < e->xp)
		{
			if (e->piece[j][i] == '*')
			{
				e->aws[0] = y - j;
				e->aws[1] = x - i;
				if (ft_check(e) == 1)
				{
					e->tmp = e->tab;
					ft_rempli(e);
					maxcol = ft_countcol(e);
					if (maxcol <= 0 && e->maxcol <= 0)
					{
						maxdis = ft_countdis(e);

						if (maxdis >= e->maxdis)
						{
							e->maxdis = maxdis;
							e->as[0] = y - j;
							e->as[1] = x - i;
						}
					}
					else
					{
						if (maxcol >= e->maxcol)
						{
							e->maxcol = maxcol;
							e->as[0] = y - j;
							e->as[1] = x - i;
						}
					}
					ft_reset(e, x, y);
				}
			}
		}
	}
	return (0);
}

void	solve(t_env *e)
{
	int		y;
	int		x;

	e->maxcol = -1;
	e->maxdis = -1;
	y = -1;
	while (++y < e->y)
	{
		x = -1;
		while (++x < e->x)
			if (e->tab[y][x] == e->p1)
				ft_poser(e, x, y);
	}
	ft_printf("%d %d\n", e->as[0], e->as[1]);
}

int main()
{
	char	*line;
	t_env	e;

	e.flag = 0;
	e.aws = (int*)malloc(sizeof(int) * 2);
	fd = open("/dev/ttys001", O_WRONLY);
	while (get_next_line(0, &line))
	{
		if (ft_strncmp("$$$ exec p", line, 10) == 0)
			get_player(&e, &line);
		if (ft_strncmp("Plateau ", line, 8) == 0)
			get_plateau(&e, &line);
		e.flag == 1 ? get_tab(&e, &line) : 0;
		ft_strncmp("Piece", line, 5) == 0 ? get_piecesize(&e, &line) : 0;
		e.flag == 2 ? get_piece(&e, &line) : 0;
		e.flag == 3 ? solve(&e) : 0;
	}
	return (0);
}
