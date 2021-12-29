/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lorem_generator.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:44:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 08:58:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOREM_GENERATOR_H
# define LOREM_GENERATOR_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 65536
# endif

# include "t_word_lst.h"

int	generate(t_word_lst *const database, t_opt *const opt, size_t const maxlen)
	__attribute__((nonnull));
int	load(t_word_lst *const words, t_opt *const opt)
	__attribute__((nonnull));
int	organize(t_word_lst *const words, t_word_lst **const database,
		size_t const maxlen)
	__attribute__((nonnull));

#endif
