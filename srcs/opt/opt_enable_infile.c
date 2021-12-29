/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_enable_infile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:10:04 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 02:31:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_opt.h"

void	opt_enable_infile(t_opt *const opt, char const *val)
{
	opt->flagfield |= (1 << 3);
	opt->infile = val;
}
