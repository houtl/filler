/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:50:11 by thou              #+#    #+#             */
/*   Updated: 2018/01/12 17:04:08 by thou             ###   ########.fr       */
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
}					t_env;

void				get_player_name(t_env *e, char **str);
void				get_plateau(t_env *e, char **str);
void				get_piecesize(t_env *e, char **str);
void				get_tab(t_env *e, char **str);
void				get_piece(t_env *e, char **str);

#endif
