/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:34:49 by thou              #+#    #+#             */
/*   Updated: 2018/03/27 18:25:04 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	get_put(t_env e, char **str)
{
	char	c;
	int		i;
	int		j;

	i = 11;
	c = str[0][6];
	e->aws[0] = ft_atoi(str[0] + 11);
	while (ft_isnb(str[0][i]))
		i++;
	while (!ft_isnb(str[0][i]))
		i++;
	e->aws[1] = ft_atoi(str[0] + i);
	j = 0;
	while (++j < e->yp)
	{
		i = 0;
		while (++i < e->xp)
			if (e->piece[j][i] = '*')
				e->tab[e->aws[0] + j][e->aws[1] + i] = c;
	}
}

int		main(void)
{
	char	*line;
	t_env	e;

	e.flag = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strncmp("$$$ exec p", line, 10) == 0)
			get_player_name(&e, &line);
		if (ft_strncmp("Plateau ", line, 8) == 0 && e.flag == 0)
		{
			get_plateau(&e, line);
			init_mlx(&e);
		}
		e.flag == 1 ? get_tab(&e, &line) : 0;
		ft_strncmp("Piece", line, 5) == 0 ? get_piecesize(&e, &line) : 0;
		e.flag == 2 ? get_piece(&e, &line) : 0;
		if (ft_strncmp("<got (", line, 6) == 0)
			get_put(&e, &line);
		e.flag == 3 ? ft_graphic(&e) : 0;
		free(line);
	}
	return (0);
}
