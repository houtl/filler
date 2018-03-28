/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:23:03 by thou              #+#    #+#             */
/*   Updated: 2018/03/28 01:54:24 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	ft_put_pixel_to_image(t_env *e, int y, int x, int color)
{
	if (x >= 0 && x < e->x && y >= 0 && y < e->y)
		*(unsigned int*)(e->data + (x * (e->bpp)) + (y * e->sl)) = color;
}

void	ft_put_color(t_env *e, int y, int x, int color)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			ft_put_pixel_to_image(e, (y * 10 + i), (x * 10 + j), color);
	}
}

void	ft_graphic(t_env *e)
{
	int		i;
	int		j;
	int		color;

	i = -1;
	while (++i < e->y)
	{
		j = -1;
		while(++j < e->x)
		{
			if (e->tab[i][j] == 'O')
				color = RED;
			else if (e->tab[i][j] == 'X')
				color = BLUE;
			else
				color = WHITE;
			ft_put_color(e, i, j, color);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	e->flag = 1;
}

void	init_mlx(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		ft_error("mlx_init error");
	if (!(e->win = mlx_new_window(e->mlx, e->x * 10, e->y * 10 + 10, "FILLER")))
		ft_error("mlx_new_window error");
	e->img = mlx_new_image(e->mlx, e->x, e->y);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sl, &e->ed);
	if (e->data == NULL)
		ft_error("GET_DATA ERROR");
	e->bpp /= 8;
}
