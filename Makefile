# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 21:24:13 by jodufour          #+#    #+#              #
#    Updated: 2021/12/29 02:39:46 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC				=	clang -c
LINK			=	clang
MKDIR			=	mkdir -p
RM				=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME			=	generator

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR			=	srcs/
OBJ_DIR			=	objs/
PRV_DIR			=	private/

FT_IO_DIR		=	libft_io/
FT_IO_INC_DIR	=	include/
FT_IO_INC_DIR	:=	${addprefix ${FT_IO_DIR}, ${FT_IO_INC_DIR}}

#######################################
#              LIBRARIES              #
#######################################
FT_IO_A			=	libft_io.a
FT_IO_A			:=	${addprefix ${FT_IO_DIR}, ${FT_IO_A}}

######################################
#            SOURCE FILES            #
######################################
SRC				=	\
					${addprefix opt/,			\
						opt_enable_bytemax.c	\
						opt_enable_bytemin.c	\
						opt_enable_colwidth.c	\
						opt_enable_help.c		\
						opt_enable_infile.c		\
						opt_enable_lenmax.c		\
						opt_enable_lenmin.c		\
						opt_enable_outfile.c	\
						opt_enable_wordmax.c	\
						opt_enable_wordmin.c	\
						opt_get.c				\
						opt_init.c				\
						opt_print.c				\
					}							\
					generate.c					\
					main.c

######################################
#            OBJECT FILES            #
######################################
OBJ				=	${SRC:.c=.o}
OBJ				:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP				=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS			=	-Wall -Wextra #-Werror
CFLAGS			+=	-MMD -MP
CFLAGS			+=	-I${PRV_DIR}
CFLAGS			+=	-I${FT_IO_INC_DIR}

LDFLAGS			=	-L${FT_IO_DIR} -lft_io

ifeq (${DEBUG}, 1)
	CFLAGS		+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}: ${OBJ} ${FT_IO_A}
	${LINK} ${OBJ} ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} ${CFLAGS} $< ${OUTPUT_OPTION}

${FT_IO_A}:
	${MAKE} ${@F} -C ${@D}

clean:
	${RM} ${OBJ_DIR} ${NAME}

fclean:
	${RM} ${OBJ_DIR} ${NAME}
	${MAKE} $@ -C ${FT_IO_DIR}

re: clean all

fre: fclean all

-include /home/jodufour/Templates/mk_files/coffee.mk
-include /home/jodufour/Templates/mk_files/norm.mk

.PHONY:	all clean fclean re
