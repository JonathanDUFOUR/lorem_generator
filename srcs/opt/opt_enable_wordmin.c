/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_enable_wordmin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:11:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 02:38:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "t_opt.h"

void	opt_enable_wordmin(t_opt *const opt, char const *val)
{
	opt->flagfield &= ~(1 << 1);
	opt->flagfield |= (1 << 2);
	opt->wordmin = ft_atosize(val);
}
