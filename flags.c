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
void                flag_l(t_list *lst, t_list *head)
{
    while(lst != head)
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
        lst = lst->prev;
     }
}
