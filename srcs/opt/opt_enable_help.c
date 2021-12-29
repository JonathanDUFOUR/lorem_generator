/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_enable_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:05:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 01:50:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_opt.h"

void	opt_enable_help(t_opt *const opt, char const *val
	__attribute__((unused)))
{
	opt->flagfield |= (1 << 0);
}
