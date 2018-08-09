/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <>                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:33:12 by thou              #+#    #+#             */
/*   Updated: 2018/08/09 17:40:14 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
static void	get_plateau(t_env *e, char *str)
{
	int		i;

	i = 8;
	e->y = ft_atoi(str + i);
	while (str[++i] != ' ')
		;
	e->x = ft_atoi(str + i);
	free(str);
	e->tab = (char**)malloc(sizeof(char*) * (e->y + 1));
}
static void	get_tab(t_env *e, char *str)
{
	int		y;

	get_plateau(e, str);
	get_next_line(0, &str);
	free(str);
	y = -1;
	while (++y < e->y)
	{
		get_next_line(0, &str);
		e->tab[y] = ft_strdup(str + 4);
		ft_strdel(&str);
	}
}

static void	get_player(t_env *e, char *str)
{
	int		i;

	i = 22;
	if (str[9] == 'p' && str[10] == '1')
	{
		while (str[i] != '.')
			i++;
		e->p1 = ft_strsub(str, 23, i - 23);
	}
	if (str[9] == 'p' && str[10] == '2')
	{
		while (str[i] != '.')
			i++;
		e->p2 = ft_strsub(str, 23, i - 23);
	}
	free(str);
}

void	ft_read(t_env *e)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strncmp(line, "$$$", 2) == 0)
			get_player(e, line);
		else if (ft_strncmp(line, "Plateau", 6) == 0)
			get_tab(e, line);
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			ft_strdel(&line);
			return ;
		}
		else
			free(line);
	}
}
