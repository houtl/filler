/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:34:49 by thou              #+#    #+#             */
/*   Updated: 2018/08/09 16:55:05 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"



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
