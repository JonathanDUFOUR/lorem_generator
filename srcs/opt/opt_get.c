/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:36:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 03:03:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lookup_opt.h"

static int	__c_get(t_opt *const opt, char const *av)
{
	char const	*val = av + 1;
	int			i;

	i = 0;
	while (g_enabler[i].fct && (!g_enabler[i].c || *av != g_enabler[i].c))
		++i;
	if (!g_enabler[i].fct || (g_enabler[i].needval && (*val != '=' || !*++val)))
		return (EXIT_FAILURE);
	g_enabler[i].fct(opt, val);
	return (EXIT_SUCCESS);
}

static int	__str_get(t_opt *const opt, char const *av)
{
	char	*val;
	int		i;

	val = strchr(av, '=');
	if (val)
		*val = 0;
	i = 0;
	while (g_enabler[i].fct && strcmp(av, g_enabler[i].str))
		++i;
	if (!g_enabler[i].fct)
		return (EXIT_FAILURE);
	if (g_enabler[i].needval && (!val || !*++val))
		return (EXIT_FAILURE);
	g_enabler[i].fct(opt, val);
	return (EXIT_SUCCESS);
}

int	opt_get(t_opt *const opt, char const **av)
{
	while (*av)
	{
		if (**av != '-')
			return (EXIT_SUCCESS);
		++*av;
		if (**av == '-')
		{
			if (__str_get(opt, ++*av))
				return (EXIT_FAILURE);
		}
		else if (__c_get(opt, *av))
			return (EXIT_FAILURE);
		++av;
	}
	return (EXIT_SUCCESS);
}
