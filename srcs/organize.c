/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:41:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 09:05:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "t_word_lst.h"

int	organize(t_word_lst *const words, t_word_lst **const database,
	size_t const maxlen)
{
	t_word	*curr;
	t_word	*next;

	*database = malloc(maxlen * sizeof(t_word_lst));
	if (!*database)
		return (EXIT_FAILURE);
	memset(*database, 0, maxlen * sizeof(t_word_lst));
	curr = words->head;
	while (curr)
	{
		next = curr->next;
		curr->next = NULL;
		word_lst_push_back(*database + curr->len - 1, curr);
		curr = next;
	}
	memset(words, 0, sizeof(t_word_lst));
	return (EXIT_SUCCESS);
}
