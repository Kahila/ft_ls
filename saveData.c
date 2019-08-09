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
//working with lists
void            saveData(int numFiles,char  **content)
{
    t_list *lst;
    t_list head;
    int i;

    i = 0;
    head.next = (t_list*)&head;
    head.prev = (t_list*)&head;
    while(i < numFiles)
    {
        lst = malloc(sizeof(t_list));
        lst->fileName = content[i];
        lst->nLinks = i;
        lst->dirORfile = i;
        lst->nBytes = i;
        lst->user = "user";
        lst->group = "group";
        lst->next = head.next;
        head.next = lst;
        lst->prev = &head;
        lst->next->prev = lst;
        i++;
    }
}
