/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_lst_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 05:40:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 05:42:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_word_lst.h"

void	word_lst_push_back(t_word_lst *const words, t_word *const node)
{
	if (!words->size)
		words->head = node;
	else
		words->tail->next = node;
	words->tail = node;
	++words->size;
}
