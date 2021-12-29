/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_lst_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 04:49:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 06:03:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "t_word_lst.h"

void	word_lst_clear(t_word_lst *const words)
{
	t_word	*next;

	while (words->head)
	{
		next = words->head->next;
		free((void *)words->head->str);
		memset(words->head, 0, sizeof(t_word));
		free((void *)words->head);
		words->head = next;
	}
	words->tail = NULL;
	words->size = 0;
}
