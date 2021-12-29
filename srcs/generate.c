/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:59:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 03:22:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "t_opt.h"

static int	__init_fd(t_opt *const opt, int *const fd_in, int *const fd_out)
{
	*fd_in = 0;
	if (opt->flagfield & (1 << 3))
		*fd_in = open(opt->infile, O_RDONLY);
	if (*fd_in == -1)
	{
		perror(__func__);
		return (EXIT_FAILURE);
	}
	*fd_out = 1;
	if (opt->flagfield & (1 << 4))
		*fd_out = open(opt->outfile, O_WRONLY | O_CREAT, 0644);
	if (*fd_out == -1)
	{
		perror(__func__);
		if (*fd_in > 0 && close(*fd_in))
			perror(__func__);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	__clear_fd(int *const fd_in, int *const fd_out)
{
	int	ret;

	ret = EXIT_SUCCESS;
	if (*fd_in > 0 && close(*fd_in))
	{
		perror(__func__);
		ret = EXIT_FAILURE;
	}
	if (*fd_out > 0 && close(*fd_out))
	{
		perror(__func__);
		ret = EXIT_FAILURE;
	}
	return (ret);
}

int	generate(t_opt *const opt)
{
	int	fd_in;
	int	fd_out;

	opt_print(opt);
	if (__init_fd(opt, &fd_in, &fd_out))
		return (EXIT_FAILURE);
	if (__clear_fd(&fd_in, &fd_out))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
