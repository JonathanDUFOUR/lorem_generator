/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_byte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:58:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 05:42:35 by jodufour         ###   ########.fr       */
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

static void	__truncate(char const *str, t_opt *const opt,
	size_t *const *const colcnt, FILE *stream)
{
	size_t	prefix_len;
	size_t	suffix_len;

	prefix_len = (opt->colwidth - *colcnt[0]) - 1;
	if (prefix_len > *colcnt[1])
		prefix_len = *colcnt[1];
	suffix_len = strlen(str) - prefix_len;
	*colcnt[1] -= fprintf(stream, "%.*s", (int)prefix_len, str);
	if (!*colcnt[1])
		return ;
	fprintf(stream, "\\\n");
	if (suffix_len >= opt->colwidth)
	{
		*colcnt[0] = 0;
		__truncate(str + prefix_len, opt, colcnt, stream);
	}
	else
	{
		*colcnt[0] = suffix_len;
		*colcnt[1] -= fprintf(stream, "%s", str + prefix_len);
	}
}

static size_t	__print_and_update(char const *str, size_t *const col,
	size_t const newcol, FILE *stream)
{
	*col = newcol;
	return (fprintf(stream, "%s", str));
}

void	gen_byte(t_word_lst *const database, t_opt *const opt,
	size_t const maxlen, FILE *stream)
{
	t_word	*curr;
	size_t	col;
	size_t	cnt;

	col = 0;
	cnt = (size_t)rand() % (opt->bytemax - opt->bytemin + 1) + opt->bytemin - 1;
	while (cnt)
	{
		curr = __gen_one(database, maxlen);
		if (col + curr->len >= opt->colwidth || curr->len > cnt)
			__truncate(curr->str, opt, (size_t *[]){&col, &cnt}, stream);
		else
			cnt -= __print_and_update(curr->str, &col, col + curr->len, stream);
		if (col + 1 == opt->colwidth)
			__print_and_update("\\\n", &col, 0, stream);
		if (col + 1 < opt->colwidth && cnt)
			cnt -= __print_and_update(" ", &col, col + 1, stream);
	}
	fputc('\n', stream);
}
