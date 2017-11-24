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

char		*ft_strsub(char const *s, unsigned int start, size_t len);

int		is_valid(char *res)
{
    int		i;    // шаги по термино
    int		dot;
    int		hash;
    int     count_hash;
    
    i = 0;
    dot = 0;
    hash = 0;
    count_hash = 0;
    while (res[i] == '.' || res[i] == '#' || res[i] == '\n')
    {
        if (res[i] == '#')
            if (res[i + 1] == '#' || res[i - 1] == '#' || res[i + 5] == '#' ||  res[i - 5] == '#')
                count_hash++;
        if (res[i] == '#')
            hash++;
        if (res[i] == '.')
            dot++;
        i++;
    }
    if (hash == 4 && dot == 12 && count_hash == 4) 
        return (1);
    return (0);
}

int		read_all(int fd)
{
    char	buf[545];
    int 	red;       // число считаных байт
    int 	n;         // шаг для обрезки термино по 21
    int     i;         // номер термино при отображении
    int     res_val;   

   	red = read(fd, &buf, 545);
	if (red == -1 || red < 20 || red > 545 || red % 21 != 20)
		return(0);
	buf[red] = '\n';
	n = 0;
    i = 1;
    res_val = 1;
	while (n <= red - n + 1)
	{	
        n = n + 21;
        res_val *= is_valid(ft_strsub(buf, n - 21, n));
        i++;
	}
    return (res_val);
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
        {
            printf("******************\n");
            printf("** main - VALID **\n");
            printf("******************\n");
        }
        else
        {
            printf("******************\n");
            printf("** main - ERROR **\n");
            printf("******************\n");
        }
    }
    else
    {
        printf("***********************************\n");
        printf("** the tetriminos is unavailable **\n");
        printf("***********************************\n");
    }
    return (0);
}



