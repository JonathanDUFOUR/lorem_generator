/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_enable_bytemin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:07:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 02:36:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "t_opt.h"

void	opt_enable_bytemin(t_opt *const opt, char const *val)
{
	opt->flagfield &= ~(1 << 2);
	opt->flagfield |= (1 << 1);
	opt->bytemin = ft_atosize(val);
}
