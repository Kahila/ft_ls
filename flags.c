/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 08:24:51 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/14 08:25:13 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//this method will be used to handle the flags
void flag_l(t_list *lst, t_list *head)
{
    int hidden;

    hidden = 1;
    while (lst != head)
    {
        // if (lst->fileName[0] != '.')
        {
            ft_putstr(lst->permits);
            ft_putchar('\t');
            ft_putnbr(lst->nLinks);
            ft_putchar('\t');
            ft_putstr(lst->user);
            ft_putchar('\t');
            ft_putstr(lst->group);
            ft_putchar('\t');
            ft_putnbr(lst->nBytes);
            ft_putchar('\t');
            ft_putstr(lst->last_modified);
            ft_putchar('\t');
            ft_putstr(lst->fileName);
            ft_putchar('\n');
        }
        lst = lst->prev;
    }
}

//method that will be used to show the fidden files
void flag_a(t_list *lst, t_list *head)
{
    while (lst != head)
    {
        ft_putstr(lst->fileName);
        ft_putchar('\n');
        lst = lst->prev;
    }
}

//method will be used to display the list when no flags are passed
void no_flag(t_list *lst, t_list *head)
{
    int i;

    i = 0;
    while (lst != head)
    {
        if (lst->fileName[i] != '.')
        {
            ft_putstr(lst->fileName);
            ft_putchar('\n');
        }
        i++;
        lst = lst->prev;
    }
}

//method will be used to dislay list in reverse
void flag_r(t_list *lst, t_list *head)
{
    int i;

    i = 0;
    while (lst != head)
    {
        if (lst->fileName[i] != '.')
        {
            ft_putstr(lst->fileName);
            ft_putchar('\n');
        }
        i++;
        lst = lst->next;
    }
}
//method from Mosima
// void print_rec(char *dir, char *ops)
// {
//     char **files;
//     char **dirs;
//     char *tempdir;
//     char **temp2;
//     ​
//         files = get_filenames(dir, (ft_strchr(ops, 'a')) ? 'a' : '-');
//     dirs = get_dirnames(dir, (ft_strchr(ops, 'a')) ? 'a' : '-');
//     temp2 = dirs;
//     sort_print(&files, &dirs, dir, ops);
//     if (dirs)
//         while (*dirs)
//         {
//             tempdir = ft_strjoin(dir, *dirs++);
//             print_rec(tempdir, ops);
//             free(tempdir);
//         }
//     if (temp2)
//         strstr_del(&temp2);
//     if (files)
//         strstr_del(&files);
// }