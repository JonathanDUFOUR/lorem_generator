/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 02:03:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 03:18:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_opt.h"

static void	__print_flagfield(t_opt *const opt)
{
	printf("%20s:\n", "opt->flagfield");
	printf("\t%20s: %i\n", "help", !!(opt->flagfield & (1 << 0)));
	printf("\t%20s: %i\n", "byte count", !!(opt->flagfield & (1 << 1)));
	printf("\t%20s: %i\n", "word count", !!(opt->flagfield & (1 << 2)));
	printf("\t%20s: %i\n", "infile", !!(opt->flagfield & (1 << 3)));
	printf("\t%20s: %i\n", "outfile", !!(opt->flagfield & (1 << 4)));
}

void	opt_print(t_opt *const opt)
{
	if (1)
		printf("%20s: %p\n", "opt", opt);
	if (1)
		__print_flagfield(opt);
	if (1)
		printf("%20s: %zu\n", "opt->bytemin", opt->bytemin);
	if (1)
		printf("%20s: %zu\n", "opt->bytemax", opt->bytemax);
	if (1)
		printf("%20s: %zu\n", "opt->wordmin", opt->wordmin);
	if (1)
		printf("%20s: %zu\n", "opt->wordmax", opt->wordmax);
	if (1)
		printf("%20s: %zu\n", "opt->lenmin", opt->lenmin);
	if (1)
		printf("%20s: %zu\n", "opt->lenmax", opt->lenmax);
	if (1)
		printf("%20s: %zu\n", "opt->colwidth", opt->colwidth);
	if (1)
		printf("%20s: %s\n", "opt->infile", opt->infile);
	if (1)
		printf("%20s: %s\n", "opt->outfile", opt->outfile);
}
