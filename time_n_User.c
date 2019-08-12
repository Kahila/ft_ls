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
    struct passwd *ID;

    // content = ft_strjoin("libft/", content);
    i = stat(content, &buff);
    ID = getpwuid(buff.st_uid);
    if (ID != NULL)
        return (ft_strdup(ID->pw_name));
    else
        return (ft_itoa(buff.st_uid));
}

//method that will be used to get the group to which file/dir belongs
char        *group(char *content)
{
    struct stat buff;
    int i;
    struct group *ID;

    i = stat(content, &buff);
    ID = getgrgid(buff.st_gid);
    return (ID->gr_name);
}