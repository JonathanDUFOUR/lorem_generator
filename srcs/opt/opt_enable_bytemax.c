/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_enable_bytemax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:09:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 02:36:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "t_opt.h"

void	opt_enable_bytemax(t_opt *const opt, char const *val)
{
	opt->flagfield &= ~(1 << 2);
	opt->flagfield |= (1 << 1);
	opt->bytemax = ft_atosize(val);
}
