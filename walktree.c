/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walktree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 22:23:18 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/09 22:23:21 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//method that will be used to get the list of dir in thet curr dir
char **get_dir(t_list *lst, char *folder, t_list *head)
{
    char **dir;
    int len;
    int i;

    i = 0;
    len = count_dir(lst, head, folder);
    dir = (char **)malloc(sizeof(char *) * len + 1);
    dir[len + 1] = NULL;
    while (i < len)
    {
        if (lst->dirORfile == IS_FOLDER)
        {
            dir[i] = ft_strdup(lst->fileName);
            i++;
        }
        lst = lst->prev;
    }
    return (dir);
}

//method will be used to get the paths of the files in subdir

//method will be used to walk the directory tree
//will display the content of all the directories that have been walked
