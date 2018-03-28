/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <thou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:34:49 by thou              #+#    #+#             */
/*   Updated: 2018/03/28 03:10:52 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

int		main(void)
{
	char	*line;
	t_env	e;

	e.flag = 0;
	e.piece = NULL;
	e.tab = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strncmp("$$$ exec p", line, 10) == 0)
			get_player_name(&e, &line);
		if (ft_strncmp("Plateau ", line, 8) == 0 && e.flag == 0)
		{
			get_plateau(&e, &line);
			init_mlx(&e);
		}
		e.flag == 1 ? get_tab(&e, &line) : 0;
		ft_strncmp("Piece", line, 5) == 0 ? get_piecesize(&e, &line) : 0;
		e.flag == 2 ? get_piece(&e, &line) : 0;
		if (ft_strncmp("<got (", line, 6) == 0)
			get_put(&e, &line);
		e.flag == 3 ? ft_graphic(&e) : 0;
		if (ft_strncmp("==", line, 2) == 0)
			mlx_loop(e.mlx);
		free(line);
	}
	return (0);
}
