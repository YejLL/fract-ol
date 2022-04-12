/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:19:08 by yejlee            #+#    #+#             */
/*   Updated: 2022/04/12 17:43:26 by yejlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0)
		return (0);
	while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0' && x < n - 1)
	{
		if (s1[x] != s2[x])
			break ;
		x++;
	}
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	else
		return (1);
}

double	ft_atof(char *s, int sign, double nbr, double div)
{
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		nbr = nbr * 10.0 + (*s - '0');
		s++;
	}
	if (*s == '.')
		s++;
	if (!ft_isdigit(*s))
		ft_error_inputs();
	while (ft_isdigit(*s))
	{
		nbr = nbr * 10.0 + (*s - '0');
		div *= 10.0;
		s++;
	}
	if (*s && !ft_isdigit(*s))
		ft_error_inputs();
	return (nbr * sign / div);
}

void	ft_destroy(t_fractol *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img->img_ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	free(ptr->img);
	free(ptr->mlx_ptr);
	free(ptr);
	exit(0);
}

int	click_cross(int button, t_fractol *ptr)
{
	(void)ptr;
	exit(0);
}
