/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_lst_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 06:09:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 06:14:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_word_lst.h"

void	word_lst_print(t_word_lst const *const words)
{
	t_word const	*curr = words->head;

	if (1)
		printf("%20s: %p\n", "words", words);
	if (1)
		printf("%20s: %p\n", "words->head", words->head);
	if (1)
		printf("%20s: %p\n", "words->tail", words->tail);
	if (1)
		printf("%20s: %zu\n", "words->size", words->size);
	while (curr)
	{
		word_print(curr);
		curr = curr->next;
	}
}
