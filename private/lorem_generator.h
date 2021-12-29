/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lorem_generator.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:44:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 04:14:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOREM_GENERATOR_H
# define LOREM_GENERATOR_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE 65536
# endif

# include "t_opt.h"

int	generate(t_opt *const opt)
	__attribute__((nonnull));

#endif
