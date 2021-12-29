/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_lst_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 05:30:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 05:40:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_word_lst.h"

int	word_lst_add_back(t_word_lst *const words, char const *str,
	size_t const len)
{
	t_word *const	node = word_new(str, len);

	if (!node)
		return (EXIT_FAILURE);
	word_lst_push_back(words, node);
	return (EXIT_SUCCESS);
}
