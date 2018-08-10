/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:58:09 by thou              #+#    #+#             */
/*   Updated: 2018/08/10 02:16:38 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	ft_background(t_env *e)
{
	int		i;

	i = -1;
	while (++i < HEIGHT * WIDTH)
		*(unsigned int*)(e->data + i * 4) = 0x343434;
}

void	ft_resault(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 130, 115, BLUE, e->p1);
	mlx_string_put(e->mlx, e->win, 420, 115, RED, e->p2);
	mlx_string_put(e->mlx, e->win, 135, 130, BLUE, ft_itoa(e->aws[0]));
	mlx_string_put(e->mlx, e->win, 425, 130, RED, ft_itoa(e->aws[1]));
}

void	ft_draw_grille(int x, int y, t_env *e)
{
	int		w;
	int		i;
	int		j;

	w = e->y > e->x ? 600 / e->y : 600 / e->x;
	j = 1;
	while (++j < w)
	{
		i = 1;
		while (++i < w)
		{
			*(unsigned int*)(e->data + (y * w + j + 200) * 4 * WIDTH + x * w * 4 + i * 4) = e->color;
		}
	}
}

void	ft_draw_map(t_env *e)
{
	int		i;
	int		j;

	e->aws[0] = 0;
	e->aws[1] = 0;
	i = -1;
	while (++i < e->y)
	{
		j = -1;
		while (++j < e->x)
		{
			e->color = WHITE;
			if (e->tab[i][j] == 'o' || e->tab[i][j] == 'O')
			{
				e->aws[0]++;
				e->color = BLUE;
			}
			else if (e->tab[i][j] == 'x' || e->tab[i][j] == 'X')
			{
				e->aws[1]++;
				e->color = RED;
			}
			ft_draw_grille(j, i, e);
		}
	}
}

int		ft_loop_key(t_env *e)
{
	char	*str;

	if (e->pause == 0)
	{
		e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sl, &e->ed);
		ft_read(e);
		ft_background(e);
		ft_draw_map(e);
		ft_bar(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_put_image_to_window(e->mlx, e->win, e->img2, 0, 0);
		mlx_destroy_image(e->mlx, e->img);
		e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		ft_resault(e);
	}
	else if (e->pause == 1)
	{
		str = "PAUSE";
		mlx_string_put(e->mlx, e->win, (WIDTH / 4) - 10, (HEIGHT / 2) - 10, 0x0fffff, str);
	}
	return (0);
}
