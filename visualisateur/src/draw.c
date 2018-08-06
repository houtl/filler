/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:58:09 by thou              #+#    #+#             */
/*   Updated: 2018/08/06 10:39:48 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_draw_title(t_env *e)
{
	int		w;
	int		h;

	e->img = mlx_xpm_file_to_image(e->mlx, "title.xpm", &n, &r);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sl, &e->ed);
}

void	ft_loop_key(t_env *e)
{
	
