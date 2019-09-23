/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:33:13 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/13 11:49:41 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//this method will be used to get the permisions for the user.group and other
char            *permits(char *file)
{
    struct stat buff;
    int i;
    char *str;

    if ((stat(file, &buff) < 0))
    {
            return (NULL);
    }
    i = stat(file, &buff);
    str = ft_memalloc(sizeof(char)*10);
    S_ISDIR(buff.st_mode) ? str[0] = 'd' : (str[0] = '-');
    (buff.st_mode & S_IRUSR) ? str[1] = 'r' : (str[1] = '-');
    (buff.st_mode & S_IWUSR) ? str[2] = 'w' : (str[2] = '-');
    (buff.st_mode & S_IXUSR) ? str[3] = 'x' : (str[3] = '-');
    (buff.st_mode & S_IRGRP) ? str[4] = 'r' : (str[4] = '-');
    (buff.st_mode & S_IWGRP) ? str[5] = 'w' : (str[5] = '-');
    (buff.st_mode & S_IXGRP) ? str[6] = 'x' : (str[6] = '-');
    (buff.st_mode & S_IROTH) ? str[7] = 'r' : (str[7] = '-');
    (buff.st_mode & S_IWOTH) ? str[8] = 'w' : (str[8] = '-');
    (buff.st_mode & S_IXOTH) ? str[9] = 'x' : (str[9] = '-');
    str[10] = '\0';
    return (str);
}
