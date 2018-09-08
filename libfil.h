#ifndef LIBFIL_H
# define LIBFIL_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_figure
{
	unsigned short int *data;
	int x_size;
	int y_size;
  char letter;
	struct s_figure *next;
	struct s_figure *previous;
} t_figure;

typedef struct s_solution
{
	t_figure *figure;
	struct s_solution *next;
	struct s_solution *previous;
	int x;
	int y;
} t_solution;

char    *ft_strsub(char const *s, size_t start, size_t len);
void    ft_putchar(char c);
void    ft_putstr(char *s);
int     ft_pow(int x, int power);
t_figure     *read_all(int fd);
t_figure	*new_figure_element(char letter);
t_solution *new_solution_element(t_figure *figure, int x, int y);
void    ft_print_bits(unsigned short int     bit);
void    show_map(t_solution *solution, t_figure *figure, int map_size);
void	change_figure(t_figure *head_figure);
int sqrtabove(int n);
int check_figure(int * map, t_figure* figure, int x, int y, int m_length);
void insert_figure(int * map, t_figure* figure, int x, int y);
void delete_figure(int *map, t_solution *putted_figure);
int *increase_map(int *map, int m_length);
int calc_map_size(t_figure *figures);
int proc_fgrs(int *map, int m_length, t_figure *figure, t_solution **solution);

#endif
