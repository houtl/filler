/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 01:43:20 by thou              #+#    #+#             */
/*   Updated: 2017/12/25 05:13:16 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int main()
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open("./test", O_RDONLY);
	while (i < 10)
	{
		if (get_next_line(0, &line) > 0) 
			ft_putstr_fd(line, fd);
	ft_putstr_fd("good", fd);
		i++;
	}
	ft_putstr_fd("good", fd);
	ft_putstr("18 32\n");
	ft_putstr_fd("good", fd);
	close(fd);
}
