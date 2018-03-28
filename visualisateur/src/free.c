/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:57:35 by thou              #+#    #+#             */
/*   Updated: 2018/03/28 02:00:10 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void		free_piece(t_env *e)
{
	int i;

	i = -1;
	while (++i < e->yp)
		free(e->piece[i]);
	free(e->piece);
}

void		free_tab(t_env *e)
{
	int	i;

	i = -1;
	while (++i < e->y)
		free(e->tab[i]);
	free(e->tab);
}
