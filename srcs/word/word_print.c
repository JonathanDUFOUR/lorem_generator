/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 06:11:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 06:15:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_word.h"

void	word_print(t_word const	*const node)
{
	if (1)
		printf("%20s: %p\n", "node", node);
	if (1)
		printf("%20s: %s\n", "node->str", node->str);
	if (1)
		printf("%20s: %zu\n", "node->len", node->len);
	if (1)
		printf("%20s: %p\n", "node->next", node->next);
}
