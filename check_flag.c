/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 22:34:14 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/09 22:34:45 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//method will be used to check if the given flag is valid or not
int             valid_flag(int argc, char **argv)
{
    int i;
    int j;

    if (argc > 1)
    {
        i = 1;
        while(argv[i])
        {
            j = 1;
            while(argv[i][j])
            {
                if (argv[i][0] != '-')
                    return (INVALID_FLAG);
                if (argv[i][j] != 'r' || argv[i][j] != 't' || argv[i][j] != 'a' || argv[i][j] != 'l' || argv[i][j] != 'R')
                    return (INVALID_FLAG);
                j++;
            }
            i++;
        }
    }
    return (VALID_FLAG);
}

//method that will be used to get the total length of all the flags added
int             tot_leng(char **argv)
{
    int size;
    int i;

    i = 1;
    while (argv[i])
    {
        size += ft_strlen(argv[i]);
        size--;
        i++;
    }
    return (size);
}

//method that will be used to check which flag has been passed
char            *get_flags(int argc, char **argv)
{
    char *flags;
    int i;
    int j;
    int k;

    i = 1;
    k = 0;
    if (argc == 1)
        return (NULL);
    flags = (char*)malloc(sizeof(char)* tot_leng(argv) + 1);
    while(argv[i])
    {
        j = 1;
        while(argv[i][j])
        {
            flags[k] = argv[i][j];
            j++;
            k++;
        }
        i++;
    }
    flags[k] = '\0';
    return (flags);
}