/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_word_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 04:53:54 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 06:16:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WORD_LST_H
# define T_WORD_LST_H

# include <stdio.h>
# include "t_opt.h"
# include "t_word.h"

typedef struct s_word_lst	t_word_lst;

struct s_word_lst
{
	t_word	*head;
	t_word	*tail;
	size_t	size;
};

int		word_lst_add_back(t_word_lst *const words, char const *str,
			size_t const len)
		__attribute__((nonnull (1, 2)));
int		word_lst_get(t_word_lst *const words, t_opt *const opt, FILE *stream)
		__attribute__((nonnull));

void	word_lst_clear(t_word_lst *const words)
		__attribute__((nonnull));
void	word_lst_print(t_word_lst const *const words)
		__attribute__((nonnull));
void	word_lst_push_back(t_word_lst *const words, t_word *const node)
		__attribute__((nonnull));

#endif
