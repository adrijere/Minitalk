/*
** client.h for client in /home/mathon_j/rendu/PSU_2013_minitalk/client/include
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Mon Mar 10 17:59:36 2014 Jérémy MATHON
** Last update Wed Mar 19 11:46:19 2014 Jérémy MATHON
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include	<sys/types.h>
# include	<unistd.h>
# include	<stdlib.h>

void		my_putchar(char c);
void		my_putstr(char *str);
int		main(int ac, char **av);
int		my_put_nbr(int nb);
int		my_getnbr(char *str);
void		*my_malloc(size_t size);

#endif /* !CLIENT_H_ */
