/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:58:09 by thou              #+#    #+#             */
/*   Updated: 2018/08/09 17:49:18 by thou             ###   ########.fr       */
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
	e->test = 1;
}
void	ft_draw_grille(int x, int y, t_env *e)
{
	int		w;
	int		i;
	int		j;

	w = e->y > e->x ? 600 / e->y : 600 / e->x;
	j = -1;
	while (++j < w)
	{
		i = -1;
		while (++i < w)
		{
			*(unsigned int*)(e->data + (y + j) * 4 * w *WIDTH + (x + i) * 4 * w) = e->color;
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
		ft_putchar(e->tab[0][0]);
		j = -1;
		while (++j < e->x)
		{
			ft_putendl(e->tab[1]);
			ft_putchar(e->tab[i][j]);
			ft_putchar(e->tab[0][0]);
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
			else
				e->color = WHITE;
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
