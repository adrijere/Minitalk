##
## Makefile for 102chiffrement in /home/mathon_j/rendu/102chiffrement
## 
## Made by Jeremy Mathon
## Login   <mathon_j@epitech.net>
## 
## Started on  Mon Nov 25 15:37:45 2013 Jeremy Mathon
## Last update Wed Mar 19 11:45:00 2014 Jérémy MATHON
##

SRCS	=		./server/src/main.c \
			./server/src/my_putchar.c \
			./server/src/my_getnbr.c \
			./server/src/my_put_nbr.c \
			./server/src/my_putstr.c

SRCS2	=		./client/src/main.c \
			./client/src/my_putchar.c \
			./client/src/my_malloc.c \
			./client/src/my_getnbr.c \
			./client/src/my_putstr.c \
			./client/src/my_put_nbr.c

CC	=		gcc

NAME	=		server/server

NAME2	=		client/client

OBJS	=		$(SRCS:.c=.o)

OBJS2	=		$(SRCS2:.c=.o)

all:			$(NAME) $(NAME2)

$(NAME):		$(OBJS)
			$(CC) -g -o $(NAME) $(SRCS) $(CFLAGS)

$(NAME2):		$(OBJS2)
			$(CC) -g -o $(NAME2) $(SRCS2) $(CFLAGS)

clean:
			rm -rvf $(OBJS)
			rm -rvf $(OBJS2)

fclean:			clean
			rm -rvf $(NAME)
			rm -rvf $(NAME2)

re:			fclean all

check-syntax:
			$(CC) -o /dev/null $(CFLAGS) -S $(CHK_SOURCES)

.PHONY:			all clean fclean re
