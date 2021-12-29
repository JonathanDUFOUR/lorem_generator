/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_opt.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:48:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 02:05:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_OPT_H
# define LOOKUP_OPT_H

# include <stdbool.h>
# include "t_opt.h"

typedef void				(*t_fct)(t_opt *const opt, char const *val);
typedef struct s_enabler	t_enabler;

struct s_enabler
{
	char const	c;
	char const	*str;
	t_fct const	fct;
	bool const	needval;
};

void	opt_enable_help(t_opt *const opt, char const *val)
		__attribute__((nonnull (1)));
void	opt_enable_infile(t_opt *const opt, char const *val)
		__attribute__((nonnull));
void	opt_enable_outfile(t_opt *const opt, char const *val)
		__attribute__((nonnull));
void	opt_enable_bytemin(t_opt *const opt, char const *val)
		__attribute__((nonnull));
void	opt_enable_bytemax(t_opt *const opt, char const *val)
		__attribute__((nonnull));
void	opt_enable_wordmin(t_opt *const opt, char const *val)
		__attribute__((nonnull));
void	opt_enable_wordmax(t_opt *const opt, char const *val)
		__attribute__((nonnull));
void	opt_enable_lenmin(t_opt *const opt, char const *val)
		__attribute__((nonnull));
void	opt_enable_lenmax(t_opt *const opt, char const *val)
		__attribute__((nonnull));
void	opt_enable_colwidth(t_opt *const opt, char const *val)
		__attribute__((nonnull));

static t_enabler const		g_enabler[] = {
{'h', "help", opt_enable_help, false},
{'i', "infile", opt_enable_infile, true},
{'o', "outfile", opt_enable_outfile, true},
{0, "bytemin", opt_enable_bytemin, true},
{0, "bytemax", opt_enable_bytemax, true},
{0, "wordmin", opt_enable_wordmin, true},
{0, "wordmax", opt_enable_wordmax, true},
{0, "lenmin", opt_enable_lenmin, true},
{0, "lenmax", opt_enable_lenmax, true},
{0, "colwidth", opt_enable_colwidth, true},
{0}
};

#endif
