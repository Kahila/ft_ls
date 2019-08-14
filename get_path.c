/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:57:54 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/12 09:58:37 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//this method will be used to get the full path
//the path will be passed to the stat function
const char            *get_path(char *folder, char *content)
{
    char *fullpath;

    fullpath = ft_strjoin(folder, content);
    return (fullpath);
}