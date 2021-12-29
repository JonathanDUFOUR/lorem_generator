/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_enable_lenmax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:13:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 02:33:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "t_opt.h"

void	opt_enable_lenmax(t_opt *const opt, char const *val)
{
	opt->lenmax = ft_atosize(val);
}
