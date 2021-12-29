/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_enable_outfile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:10:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 02:52:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_opt.h"

void	opt_enable_outfile(t_opt *const opt, char const *val)
{
	opt->flagfield |= (1 << 4);
	opt->outfile = val;
}
