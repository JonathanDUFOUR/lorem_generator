/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:48:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 07:47:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OPT_H
# define T_OPT_H

# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include "t_int.h"

# define DEFAULT_FLAGFIELD 0
# define DEFAULT_BYTECNT_MIN 0
# define DEFAULT_BYTECNT_MAX SIZE_MAX
# define DEFAULT_WORDCNT_MIN 0
# define DEFAULT_WORDCNT_MAX SIZE_MAX
# define DEFAULT_WORDLEN_MIN 0
# define DEFAULT_WORDLEN_MAX SIZE_MAX
# define DEFAULT_COLWIDTH 80

typedef struct s_opt	t_opt;

/*
	Flagfield:
		1 << 0 - Help
		1 << 1 - Byte count
		1 << 2 - Word count
		1 << 3 - Infile
		1 << 4 - Outfile
*/
struct s_opt
{
	uint8_t		flagfield;
	size_t		bytemin;
	size_t		bytemax;
	size_t		wordmin;
	size_t		wordmax;
	size_t		lenmin;
	size_t		lenmax;
	size_t		colwidth;
	char const	*infile;
	char const	*outfile;
};

int		opt_check(t_opt *const opt)
		__attribute__((nonnull));
int		opt_get(t_opt *const opt, char const **av)
		__attribute__((nonnull));

void	opt_init(t_opt *const opt)
		__attribute__((nonnull));
void	opt_print(t_opt *const opt)
		__attribute__((nonnull));

#endif
