/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 22:24:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 00:18:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_opt.h"

void	opt_init(t_opt *const opt)
{
	opt->flagfield = DEFAULT_FLAGFIELD;
	opt->bytemin = DEFAULT_BYTECNT_MIN;
	opt->bytemax = DEFAULT_BYTECNT_MAX;
	opt->wordmin = DEFAULT_WORDCNT_MIN;
	opt->wordmax = DEFAULT_WORDCNT_MAX;
	opt->lenmin = DEFAULT_WORDLEN_MIN;
	opt->lenmax = DEFAULT_WORDLEN_MAX;
	opt->colwidth = DEFAULT_COLWIDTH;
	opt->infile = NULL;
	opt->outfile = NULL;
}
