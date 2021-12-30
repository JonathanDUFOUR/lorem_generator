/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 07:41:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 02:43:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_opt.h"

int	opt_check(t_opt *const opt)
{
	if (opt->colwidth < 2
		|| opt->lenmax < opt->lenmin
		|| (opt->flagfield & (1 << 1) && opt->bytemax < opt->bytemin)
		|| (opt->flagfield & (1 << 2) && opt->wordmax < opt->wordmin))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
