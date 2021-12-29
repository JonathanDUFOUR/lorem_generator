/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_word.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:54:58 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/28 21:55:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WORD_H
# define T_WORD_H

# include <stddef.h>

typedef struct s_word	t_word;

struct s_word
{
	char	*str;
	size_t	len;
};

#endif
