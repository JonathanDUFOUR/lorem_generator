/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:58:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 03:14:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "t_word_lst.h"

static t_word	*__gen_one(t_word_lst *const database, size_t const maxlen)
{
	t_word	*curr;
	size_t	i;
	size_t	j;

	i = (size_t)rand() % maxlen;
	while (!database[i].size)
		i = (size_t)rand() % maxlen;
	j = (size_t)rand() % database[i].size;
	curr = database[i].head;
	while (j--)
		curr = curr->next;
	return (curr);
}

static void	__truncate(char const *str, t_opt *const opt, size_t *const col,
	FILE *stream)
{
	size_t	prefix_len;
	size_t	suffix_len;

	prefix_len = (opt->colwidth - *col) - 1;
	suffix_len = strlen(str) - prefix_len;
	fprintf(stream, "%.*s\\\n", (int)prefix_len, str);
	if (suffix_len >= opt->colwidth)
	{
		*col = 0;
		__truncate(str + prefix_len, opt, col, stream);
	}
	else
	{
		*col = suffix_len;
		fprintf(stream, "%s", str + prefix_len);
	}
}

static void	__print_and_update(char const *str, size_t *const col,
	size_t const newcol, FILE *stream)
{
	fprintf(stream, "%s", str);
	*col = newcol;
}

void	gen_word(t_word_lst *const database, t_opt *const opt,
	size_t const maxlen, FILE *stream)
{
	t_word	*curr;
	size_t	col;
	size_t	cnt;

	col = 0;
	cnt = (size_t)rand() % (opt->wordmax - opt->wordmin + 1) + opt->wordmin;
	while (cnt--)
	{
		curr = __gen_one(database, maxlen);
		if (col + curr->len >= opt->colwidth)
			__truncate(curr->str, opt, &col, stream);
		else
			__print_and_update(curr->str, &col, col + curr->len, stream);
		if (col + 1 == opt->colwidth)
			__print_and_update("\\\n", &col, 0, stream);
		if (col + 1 < opt->colwidth && cnt)
			__print_and_update(" ", &col, col + 1, stream);
	}
	fputc('\n', stream);
}
