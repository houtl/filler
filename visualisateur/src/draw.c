/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:58:09 by thou              #+#    #+#             */
/*   Updated: 2018/08/07 02:14:20 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	ft_draw_title(t_env *e)
{
	int		w;
	int		h;

	e->img2 = mlx_xpm_file_to_image(e->mlx, "title.xpm", &w, &h);
	e->data = mlx_get_data_addr(e->img2, &e->bpp, &e->sl, &e->ed);
}

void	ft_draw(t_env *e)
{
	ft_background(e);
	ft_menu(e);
	ft_score(e);
	ft_map(e);
}

int		ft_loop_key(t_env *e)
{
	char	*str;

	if (e->pause == 0)
	{
		e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sl, &e->ed);
		ft_read(e);
		ft_draw(e);
//		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_put_image_to_window(e->mlx, e->win, e->img2, 0, 0);
		mlx_destroy_image(e->mlx, e->img);
		e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		ft_resault(e);
		ft_putendl("aaaaaa");
	}
	else if (e->pause == 1)
	{
		str = "PAUSE";
		mlx_string_put(e->mlx, e->win, (WIDTH / 4) - 10, (HEIGHT / 2) - 10, 0x0fffff, str);
	}
	return (0);
}
