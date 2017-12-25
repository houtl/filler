/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 01:44:12 by thou              #+#    #+#             */
/*   Updated: 2017/12/25 21:36:25 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct		s_env
{
	char			p1;
	char			p2;
	int				x;
	int				y;
	int				xp;
	int				yp;
	char			**tab;
	char			**piece;
	int				flag;
	int				*aws;
}					t_env;

void	get_plateau(t_env *e, char **str);
void	get_player(t_env *e, char **str);
void	get_piecesize(t_env *e, char **str);
void	get_tab(t_env *e, char **str);
void	get_piece(t_env *e, char **str);

#endif
