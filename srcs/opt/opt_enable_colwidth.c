/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_enable_colwidth.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:14:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 02:29:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "t_opt.h"

void	opt_enable_colwidth(t_opt *const opt, char const *val)
{
	opt->colwidth = ft_atosize(val);
}
