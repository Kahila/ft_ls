/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:38:54 by akalombo          #+#    #+#             */
/*   Updated: 2019/07/24 13:30:23 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include "libft/libft.h"
#include <unistd.h>
#include <time.h>      //working with the time and the ctime functions
#include <dirent.h>    //working with the opendir, readdir and closedir functions
#include <sys/stat.h>  //working with the stat function and lstat functions
#include <sys/types.h> //
#include <pwd.h>       //working with the passwd struct;
#include <uuid/uuid.h> //working with the uuid_t data type
#include <sys/xattr.h> //working with the listaxttr and the getxattr functions
#include <stdlib.h>    //working with the malloc, exit and free functions
#include <stdio.h>     //working with the perror function
#include <string.h>    //working with the strerror function
enum output
{
    SUCCESS,
    FAILED = -1
};
#endif