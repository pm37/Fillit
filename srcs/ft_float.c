/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:40:35 by pimichau          #+#    #+#             */
/*   Updated: 2019/01/03 12:25:15 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_y(float f)
{
	return ((int)((f * 10) - ((int)f * 10)));
}

int		get_x(float f)
{
	return ((int)(f));
}

float	set_x(int x)
{
	return ((float)(x));
}

float	set_y(int y)
{
	return (((float)y / 10));
}
