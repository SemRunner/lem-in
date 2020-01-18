/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_draw.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:41:48 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/26 19:16:30 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_DRAW_H
# define TERMINAL_DRAW_H

# include "libft.h"

# define HOME() 					ft_printf("\033[H")
# define CLRSCR()					ft_printf("\033[2J")
# define SETCOLOR(color)			ft_printf("\033[%dm", color)
# define GOTOXY(x,y)				ft_printf("\033[%d;%dH", y, x)
# define GOTOINLINE(x)				ft_printf("\033[%d`", x)
# define RESET_COLOR()				ft_printf("\033[0m")
# define SET_DISP_ATTRIB(color)		ft_printf("\033[%dm", color)

# define RESET		0
# define BRIGHT		1
# define DIM		2
# define UNDERSCORE	3
# define BLINK		4
# define REVERSE	5
# define HIDDEN		6

# define F_RED		31
# define F_GREEN	32
# define F_YELLOW	33
# define F_BLUE		34
# define F_MAGENTA	35
# define F_CYAN		36
# define F_WHITE	37

# define B_RED		41
# define B_GREEN	42
# define B_YELLOW	43
# define B_BLUE		44
# define B_MAGENTA	45
# define B_CYAN		46
# define B_WHITE	47

#endif
