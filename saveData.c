/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:18:49 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/09 16:18:51 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ls.h" 

//this method will be used to get the number of links for each file/folder
int             get_nLinks(char *content)
{
    int i;
    int nlinks;
    struct stat buff;
    i = stat(content, &buff);
    nlinks = buff.st_nlink;
    return (nlinks);
}

//this method will tell if a file is a folder or not
int             is_file(int nlinks)
{
    if (nlinks == 1)
        return (IS_FILE);
    else
        return (IS_FOLDER);
}

//method that will be used to get the number of bytes per file/dir
int             nBytes(char *content)
{
    int Bytes;
    int i;
    struct stat buff;
    i = stat(content, &buff);
    Bytes = buff.st_size;
    return (Bytes);
}

//working with lists
//storing all the data about the file within the lst node
void            saveData(int numFiles,char  **content, t_list *lst)
{
    t_list head;
    int i;

    i = 0;
    head.next = (t_list*)&head;
    head.prev = (t_list*)&head;
    while(i < numFiles)
    {
        lst = (t_list *)malloc(sizeof(t_list));
        lst->fileName = content[i];
        lst->nLinks = get_nLinks(content[i]);
        lst->dirORfile = is_file(lst->nLinks);
        lst->nBytes = nBytes(content[i]);
        lst->last_modified = last_mod(content[i]);
       //lst->user = user(content[i]);
        lst->group = group(content[i]);
        lst->next = head.next;
        head.next = lst;
        lst->prev = &head;
        lst->next->prev = lst;
        i++;
    }
    lst = head.prev;
    while(lst != &head)
    {
       printf("%s \t\t%s\t\t%s\t\t%d\n", lst->fileName, lst->last_modified, lst->group, lst->nBytes);
       lst = lst->prev;
     }
}