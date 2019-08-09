/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timepProps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:10:20 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/09 18:10:24 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ls.h"

//method that will be used to get the date the file was last modified
char             *last_mod(char *content)
{
    time_t month_mod;
    char *ti;
    char *lastMode;
    int i;
    int j;

    lastMode = (char*)malloc(sizeof(char) * 12);
    struct stat buff;
    i = stat(content, &buff);
    month_mod = buff.st_mtime;
    ti = ctime(&month_mod);//ctime will return a string of the epoch time pasted
    i = 4;
    j = 0;
    while(i <= 15)
    {
        lastMode[j] = ti[i];
        i++;
        j++;
    }
    lastMode[12] = '\0';
    return (lastMode);
}

//method that will be used to determine the user to which file belongs
char        *user(char *content)
{
    struct stat buff;
    int i;
    uid_t j;
    struct passwd *ID;

    i = stat(content, &buff);
    j = buff.st_uid;
    ID = getpwuid(j);
    return (ID->pw_name);
}

//method that will be used to get the group to which file/dir belongs
char        *group(char *content)
{
    struct stat buff;
    int i;
    gid_t j;
    struct group *ID;

    i = stat(content, &buff);
    j = buff.st_gid;
    ID = getgrgid(j);
    return (ID->gr_name);
}