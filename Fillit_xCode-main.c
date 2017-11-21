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
#include <stdio.h>
#include "libfil.h"


char		*is_term(char *res, int term)
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
            if (res[i + 1] == '#' || res[i + 5] == '#' || res[i - 1] == '#' || res[i - 5] == '#')
            {
                count_hash++;
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
        return (res);
    }
    return (0);
}

char		*is_valid(char *res)
{
    int		i;
    int		dot;
    int		hash;
    int		term;
    
    i = 0;
    dot = 0;
    hash = 0;
    printf("res == %s\n\n\n\n\n\n", res);//////////////////////////////////////////////
    while (res[i] == '.' || res[i] == '#' || res[i] == '\n')
    {
        
        if (res[i] == '#')
            hash++;
        if (res[i] == '.')
            dot++;
        i++;
    }
    printf("\nСколько i %d\n", i);//////////////////////////////////////////////////////
    printf("\nСколько hash %d\n", hash);
    printf("Сколько dot %d\n", dot);
    term = (i + 1) / 21 ;
    printf("Сколько фигур %d\n", term);
    printf("Сколько фигур %d\n", term);
    if (res[i] == '\0' && hash == 4 * term && dot == 12 * term)
        is_term(res, term);///////////
    else
        res = 0;
    printf("return res == is_valid =\n%s\n", res );
    return (res);
}


char		*read_all(int fd)
{
    char	buf[1];
    char    all[572];
    char	*res;
    int		i;
    int     count;
    
    i = 0;
    while(read(fd, &buf, 1))
    {
        all[i] = *buf;
        i++;
        printf("%s", buf); // просмотрели что входит через буфер;
    }
    printf("%d\n", i);
    res = (char *)malloc(i);
    ft_memcpy_fil(res, all, i + 1);
    // printf("%s\n", res); // просмотрели что выдает res; ?
    is_valid(res);

    printf("return res == read_all =\n%s\n", res);
    printf("read_all show adress res = \n%p\n", res);

    return (res);
    
}

// char 		*read_term(int fd)
// {
//     char	*input;
    
//     input = read_all(fd);
//     printf("return input == read_term =\n%s\n", input);
//     return (input);
// }


int			main(int argc, char **argv)
{
    char	*input;
    int     fd;
    int     i; ///delet test i

    i = 0;
    input = 0;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        input = read_all(fd);
        // while (i < 100)
        // {

            printf("MAINNNNNN show adress input = \n%s\n", input);
            printf("read_all show adress input = \n%p\n", input);
            // write(1, &input, 1);
            // input++;
        //     i++;
        // }
    }
    else
        printf("the tetriminos is invalid");
    return (0);
}



