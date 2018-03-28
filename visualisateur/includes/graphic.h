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
# include "mlx.h"

# define WHITE		0xFFFFFF
# define BLUE		0x0901F7
# define BLUE_C		0x015BF7
# define SKY		0x01B5F7
# define LAGON		0x33AB9B
# define WGREEN		0x01F79D
# define RAZER		0x01F74B
# define LIMON		0xADF701
# define YELLOW		0xEFF701
# define ORANGE		0xF78C01
# define RED		0xFE4D01
# define BACKGROUND	0x4C1B1B

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
	int				bpp;
	int				sl;
	int				ed;
}					t_env;

/*
** main.c
*/

void				ft_error(char *str);

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
void				free_tab(t_env *e);

/*
** mlx.c
*/

void				init_mlx(t_env *e);
void				ft_graphic(t_env *e);

#endif
