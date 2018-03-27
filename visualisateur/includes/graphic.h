/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:50:11 by thou              #+#    #+#             */
/*   Updated: 2018/01/12 18:21:30 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "libft.h"

typedef struct		s_env
{
	char			*p1;
	char			*p2;
	int				x;
	int				y;
	int				xp;
	int				yp;
	char			**tab;
	char			**piece;
	int				flag;
	int				aws[2];
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				sl;
	int				ed;
}					t_env;

/*
** get.c
*/

void				get_player_name(t_env *e, char **str);
void				get_plateau(t_env *e, char **str);
void				get_tab(t_env *e, char **str);
void				get_put(t_env *e, char **str);

/*
** get1.c
*/

void				get_piecesize(t_env *e, char **str);
void				get_piece(t_env *e, char **str);

/*
** free.c
*/

void				free_piece(t_env *e);

#endif
