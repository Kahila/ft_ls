/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:18:49 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/13 11:51:20 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//this method will be used to get the number of links for each file/folder
int get_nLinks(char *content)
{
    int i;
    int nlinks;
    struct stat buff;
    i = stat(content, &buff);
    nlinks = buff.st_nlink;
    return (nlinks);
}

//this method will tell if a file is a folder or not
int is_file(int nlinks)
{
    if (nlinks == 1)
        return (IS_FILE);
    else
        return (IS_FOLDER);
}

//method that will be used to get the number of bytes per file/dir
int nBytes(char *content)
{
    int Bytes;
    int i;
    struct stat buff;
    i = stat(content, &buff);
    Bytes = buff.st_size;
    return (Bytes);
}

//method that will be used to free the linked list
// void _free(t_list **lst, t_list *head)
// {
//    while (*lst != head)
//     {
//             //free(lst->permits);
//             //free(lst->user);
//             //free(lst->group);
//             //free(lst->nBytes);
//             //free(lst->last_modified);
//             //free(lst->fileName);
//         *lst = *lst->prev;
//     }
// }

//working with lists
//storing all the data about the file within the lst node
void saveData(int i, char **content, t_list *lst, char *folder)
{
    char *full_path;
    t_list head;
    int hidden;
    int numFiles;
    t_list tmp;

    if ((numFiles = i - 1000000) >= 0)
        hidden = HIDDEN_FILES;
    else
    {
        numFiles = i;
        hidden = 0;
    }
    i = 0;
    head.next = (t_list *)&head;
    head.prev = (t_list *)&head;
    while (i < numFiles && content[i])
    {
        full_path = get_path(folder, content[i]);
        lst = ft_memalloc(sizeof(t_list));
        lst->fileName = content[i];
        lst->nLinks = get_nLinks(full_path);
        lst->dirORfile = is_file(lst->nLinks);
        lst->nBytes = nBytes(full_path);
        lst->last_modified = last_mod(full_path);
        lst->user = ft_strdup(user(full_path));
        lst->group = ft_strdup(group(full_path));
        lst->next = head.next;
        lst->permits = permits(full_path);
        head.next = lst;
        lst->prev = &head;
        lst->next->prev = lst;
        i++;
    }
    tmp = head;
    if (hidden == HIDDEN_FILES)
        flag_al(head.prev, &head);
    else
        flag_l(head.prev, &head);
    //_free(lst, &tmp);
    free(lst);
}
