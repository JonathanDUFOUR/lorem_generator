/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:25:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 03:16:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "lorem_generator.h"
#include "t_opt.h"
#include "usage.h"

int	main(int const ac __attribute__((unused)), char const **av)
{
	t_opt	opt;

	opt_init(&opt);
	if (opt_get(&opt, av + 1))
	{
		fprintf(stderr, "Error: invalid option\n");
		return (EXIT_FAILURE);
	}
	if (opt.flagfield & (1 << 0))
		printf(USAGE_H);
	else if (generate(&opt))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
