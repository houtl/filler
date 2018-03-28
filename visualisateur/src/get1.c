/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:41:56 by thou              #+#    #+#             */
/*   Updated: 2018/03/28 00:47:09 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	get_piecesize(t_env *e, char **str)
{
	int		i;

	if (e->piece)
		free_piece(e);
	i = -1;
	while (ft_isdigit(str[0][++i]) == 0);
	e->yp = ft_atoi(*str + i);
	while (ft_isdigit(str[0][++i]) == 1);
	e->xp = ft_atoi(*str + i);
	e->flag = 2;
}

void	get_piece(t_env *e, char **str)
{
	int		i;
	int		j;

	e->piece = (char**)malloc(sizeof(char*) * (e->yp + 1));
	i = -1;
	while (++i < e->yp)
	{
		free(*str);
		get_next_line(0, str);
		e->piece[i] = (char*)malloc(sizeof(char) * (e->xp + 1));
		j = -1;
		while (++j < e->xp)
			e->piece[i][j] = str[0][j];
		e->piece[i][j] = 0;
	}
	e->piece[i] = NULL;
	free(*str);
	get_next_line(0, str);
}
