/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:40:35 by pimichau          #+#    #+#             */
/*   Updated: 2019/01/03 11:44:58 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		GET_Y(float f)
{
	return ((int)((f * 10) - ((int)f * 10)));
}

int		GET_X(float f)
{
	return ((int)(f));
}

float	SET_X(int x)
{
	return((float)(x));
}

float	SET_Y(int y)
{
	return(((float)y / 10));
}
