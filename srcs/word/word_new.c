/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 05:31:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 05:34:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_word.h"

t_word	*word_new(char const *str, size_t const len)
{
	t_word	*node;

	node = malloc(sizeof(t_word));
	if (!node)
		return (NULL);
	node->str = str;
	node->len = len;
	node->next = NULL;
	return (node);
}
