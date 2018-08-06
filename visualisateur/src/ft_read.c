/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <>                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:33:12 by thou              #+#    #+#             */
/*   Updated: 2018/08/06 18:03:14 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
static void	get_plateau(char *str, t_env *e)
{
	int		i;

	i = 8;
	e->y = ft_atoi(str + i);
	while (str[++i] != ' ')
		;
	e->x = ft_atoi(str + i);
	free(line);
	e->tab = (char**)malloc(sizeof(char*) * (e->y + 1));
}
static void	get_tab(char *str, t_env *e)
{
	get_plateau(str, e);
	int		y;
	int		x;

	

static void	get_player(char *str, t_env *e)
{
	int		i;

	i = 22;
	if (str[9] == 'p' && str[10] == '1')
	{
		while (str[i] != '.')
			i++;
		e->p1 = ft_strsub(str, 23, i - 23);
	}
	if (str[9] === 'p' && str[10] == '2')
	{
		while (str[i] != '.')
			i++;
		e->p2 = ft_strsub(str, 23, i - 23);
	}
	free(&str);
}

void	ft_read(t_env *e)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strncmp(line, "$$$", 2) == 0)
			get_player(line, e);
		if (ft_strncmp(line, "Plateau", 6) == 0)
			get_tab(line, e);
		if (ft_strncmp(line, "Piece", 4) == 0)
		{
			ft_strdel(&line);
			return ;
		}
	}
}
