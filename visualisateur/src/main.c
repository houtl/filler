/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:34:49 by thou              #+#    #+#             */
/*   Updated: 2018/08/10 02:18:05 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	ft_bar(t_env *e)
{
	int		i;
	int		j;

	i = 169;
	while (++i < 189)
	{
		j = 99;
		while (++j < 500)
		{
			e->color = j < (e->aws[0] * 400 / (e->aws[1] + e->aws[0]) + 100) ? BLUE : RED;
			*(unsigned int*)(e->data + i * 4 * WIDTH + j * 4) = e->color;
		}
	}
}

int		ft_key(int key, t_env *e)
{
	if (key == KEY_ESC)
		exit(1);
	ft_loop_key(e);
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

void	ft_init(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "FILLER");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img2 = mlx_xpm_file_to_image(e->mlx, "title.xpm", &e->x, &e->y);
	e->pause = 0;
	e->tab = NULL;
	e->x = 0;
	e->y = 0;
}

int		main(void)
{
	t_env	e;

	ft_init(&e);
	mlx_hook(e.win, 2, 2, ft_key, &e);
	mlx_mouse_hook(e.win, ft_mouse, &e);
	ft_loop_key(&e);
	mlx_loop_hook(e.mlx, ft_loop_key, &e);
	free(e.tab);
	mlx_loop(e.mlx);
	return (0);
}
