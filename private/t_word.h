/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_word.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:54:58 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 06:16:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WORD_H
# define T_WORD_H

# include <stddef.h>

typedef struct s_word	t_word;

struct s_word
{
	char const	*str;
	size_t		len;
	t_word		*next;
};

void	word_print(t_word const *const node)
		__attribute__((nonnull));

t_word	*word_new(char const *str, size_t const len)
		__attribute__((nonnull (1)));

#endif
