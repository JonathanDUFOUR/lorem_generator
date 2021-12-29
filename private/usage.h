/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 02:01:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 02:01:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USAGE_H
# define USAGE_H "\
Description:\n\
	Generate a lorem ipsum using a word database and apply formating on it.\n\
	The word database is loaded at the beginning of the program.\n\
	By default, the program reads from stdin to create the database,\n\
	write on stdout the generated lorem ipsum, and format it into 80 columns.\n\
\n\
Usage:\n\
	./generator [Options]\n\
\n\
Options:\n\
	-h --help\n\
		Output a short usage manual on stdout\n\
\n\
	-i=file --infile=file\n\
		Read from the given `file` instead of stdin\n\
\n\
	-o=file --outfile=file\n\
		Write in the given `file` instead of stdout\n\
\n\
	--bytemin=N\n\
		Format the output to have at least `N` bytes\n\
\n\
	--bytemax=N\n\
		Format the output to have no more than `N` bytes\n\
\n\
	--wordmin=N\n\
		Format the output to have at least `N` words\n\
\n\
	--wordmax=N\n\
		Format the output to have no more than `N` words\n\
\n\
	--lenmin=N\n\
		Format the output to have words containing at least `N` bytes\n\
\n\
	--lenmax=N\n\
		Format the output to have words containing no more than `N` bytes\n\
\n\
	--colwidth=width\n\
		Format the output into lines no larger than `width` columns\n\
"
#endif
