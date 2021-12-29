/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_enable_wordmax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:12:18 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 02:35:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "t_opt.h"

void	opt_enable_wordmax(t_opt *const opt, char const *val)
{
	opt->flagfield &= ~(1 << 1);
	opt->flagfield |= (1 << 2);
	opt->wordmax = ft_atosize(val);
}
