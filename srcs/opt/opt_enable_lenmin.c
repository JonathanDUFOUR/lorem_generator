/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_enable_lenmin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:13:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 02:33:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "t_opt.h"

void	opt_enable_lenmin(t_opt *const opt, char const *val)
{
	opt->lenmin = ft_atosize(val);
}
