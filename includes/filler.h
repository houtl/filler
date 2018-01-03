/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 01:44:12 by thou              #+#    #+#             */
/*   Updated: 2018/01/03 13:45:38 by thou             ###   ########.fr       */
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
	int				x0;
	char			**tab;
	char			**tmp;
	char			**piece;
	int				flag;
	int				*aws;
	int				as[2];
	int				maxcol;
	int				maxdis;
}					t_env;

void	ft_reset(t_env *e, int x, int y);
void	ft_rempli(t_env *e);
int		ft_countcol(t_env *e);
int		ft_countdis(t_env *e);
int		ft_poser(t_env *e, int x, int y);
void	free_tab(t_env *e);
void	free_piece(t_env *e);
void	get_plateau(t_env *e, char **str);
void	get_player(t_env *e, char **str);
void	get_piecesize(t_env *e, char **str);
void	get_tab(t_env *e, char **str);
void	get_piece(t_env *e, char **str);

#endif
