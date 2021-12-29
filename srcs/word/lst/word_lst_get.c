/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_lst_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 04:03:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 06:52:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ft_string.h"
#include "t_word_lst.h"

static int	__process(t_word_lst *const words, char const *line,
	size_t const len)
{
	char	*str;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (EXIT_FAILURE);
	str[len] = 0;
	memcpy(str, line, len);
	if (word_lst_add_back(words, str, len))
	{
		ft_memdel(&str);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	__parse_line(t_word_lst *const words, t_opt *const opt, char *line)
{
	char	*ptr;

	while (isspace(*line))
		++line;
	ptr = line;
	while (*ptr)
	{
		if (isspace(*ptr))
		{
			if ((size_t)(ptr - line) >= opt->lenmin
				&& (size_t)(ptr - line) <= opt->lenmax
				&& __process(words, line, ptr - line))
				return (EXIT_FAILURE);
			while (isspace(*ptr))
				++ptr;
			line = ptr;
		}
		else
			++ptr;
	}
	return (EXIT_SUCCESS);
}

static int	__failure(t_word_lst *const words, char *line, char const *func)
{
	word_lst_clear(words);
	ft_memdel(&line);
	perror(func);
	return (EXIT_FAILURE);
}

int	word_lst_get(t_word_lst *const words, t_opt *const opt, FILE *stream)
{
	char	*line;
	size_t	n;
	ssize_t	gl;

	line = NULL;
	n = 0;
	gl = getline(&line, &n, stream);
	while (gl > 0)
	{
		if (__parse_line(words, opt, line))
			return (__failure(words, line, __func__));
		ft_memdel(&line);
		gl = getline(&line, &n, stream);
	}
	if (gl == -1 && errno)
		return (__failure(words, line, __func__));
	ft_memdel(&line);
	return (EXIT_SUCCESS);
}
