/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:41:56 by thou              #+#    #+#             */
/*   Updated: 2018/03/27 18:03:18 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	get_piecesize(t_env *e, char **str)
{
	int		i;

	i = -1;
	while (ft_isdigit(str[++i]) == 0);
	e->xp = ft_atoi(str + i);
	while (ft_isdigit(str[++i]) == 1);
	e->yp = ft_atoi(str + i);
	e->flag = 2;
}

void	get_piece(t_env *e, char **str)
{
	int		i;
	int		j;

	if (e->piece)
		free_piece(e);
	e->piece = (char**)malloc(sizeof(char*) * (e->py + 1));
	i = -1;
	while (++i < e->yp)
	{
		free(*str);
		get_next_line(0, str);
		e->piece[i] = (char*)malloc(sizeof(char) * (e->px + 1));
		j = -1;
		while (++j < e->xp)
			e->piece[i][j] = str[j];
	}
}
