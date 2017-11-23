/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:02:27 by ozharko           #+#    #+#             */
/*   Updated: 2017/11/17 12:02:28 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void		*ft_memcpy_fil(void *dst, const void *src, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);



int		is_term(char *res, int term)
{
    int		i;
    int		hash;
    int 	count_hash;
    
    i = 0;
    count_hash = 0;
    hash = term * 4;
    printf("how much hash %d\n", hash );
    while (res[i])
    {
        if (res[i] == '#')
            if (res[i + 1] == '#' || res[i - 1] == '#' || res[i + 5] == '#' ||  res[i - 5] == '#')
            {
                count_hash++;
                printf("count_hash = %d\n", count_hash);
                printf("valid hash %d\n", i );
                // нет проверки через два \n\n 
            }  
        i++;
    }
    if (hash == count_hash)
    {
        printf("how much hash %d\n", hash );
        printf("how much count_hash %d\n", count_hash );
        printf("return res == is_term =\n%s\n", res );
        return (1);
    }
    printf("E R R R R R R O O O O R\n");
    return (0);
}

int		is_valid(char *res)
{
    int		i;
    int		dot;
    int		hash;
    int		term;
    
    i = 0;
    dot = 0;
    hash = 0;
    while (res[i] == '.' || res[i] == '#' || res[i] == '\n')
    {
        
        if (res[i] == '#')
            hash++;
        if (res[i] == '.')
            dot++;
        i++;
    }

    term = (i + 1) / 21 ;

    if (res[i] == '\0' && hash == 4 * term && dot == 12 * term)
    {
        ///////////
        return ((is_term(res, term)) ? 1 : 0);
    }
    else
        res = 0;
    printf("return res == is_valid =\n%s\n", res );
    return (0);
}


int		read_all(int fd)
{
    char	buf[545];
    char  	*term;
    int 	red;
    int 	n;


   	red = read(fd, &buf, 545);
	printf("\n\nчто выводит буфер \n%s", buf); // просмотрели что входит через буфер;

	if (red == -1 || red < 20 || red > 545 || red % 21 != 20)
		return(printf("\nE R R O R ! ! !\n"));

	printf("\n\nred = %d\n", red);

	buf[red] = '\n';

	term = ft_strsub(buf, 0, 21);
	printf("1. TERMINO\n%s\n", term);
	n = 0;
	while (n < red - n + 1)
	{	
		n = n + 21;
		term = ft_strsub(buf, n, n*2);
		printf("2. TERMINO\n%s\n", term);
	}
       return ((is_valid(buf)) ? 1 : 0);
    
}

int			main(int argc, char **argv)
{
    int     valid;
    int     fd;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        valid = read_all(fd);
        if (valid == 1)
            printf("\nVALID\n");
        else
            printf("\nERROR");
    }
    else
        printf("the tetriminos is unavailable");
    return (0);
}



