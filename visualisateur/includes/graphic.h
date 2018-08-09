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
# include "key.h"

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
# define WIDTH		1200
# define HEIGHT		600

typedef struct		s_env
{
	int				pause;
	void			*mlx;
	void			*win;
	void			*img;
	void			*img2;
	char			*data;
	char			*data2;
	int				bpp;
	int				sl;
	int				ed;
	int				test;
	char			*p1;
	char			*p2;
	int				x;
	int				y;
	char			**tab;
	int				aws[2];
	int				color;
}					t_env;

/*
** main.c
*/


/*
** ft_read.c
*/

void				ft_read(t_env *e);

/*
** draw.c
*/

void				ft_draw(t_env *e);
int					ft_loop_key(t_env *e);

/*
** draw2.c
*/

void				ft_background(t_env *e);
void				ft_menu(t_env *e);
void				ft_score(t_env *e);
void				ft_map(t_env *e);
void				ft_resault(t_env *e);

/*
** key.c
*/

int					ft_key(int key, t_env *e);
int					ft_mouse(int key, int x, int y, t_env *e);

#endif
