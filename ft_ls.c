/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:51:16 by akalombo          #+#    #+#             */
/*   Updated: 2019/07/24 13:10:49 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int no_flags(int argc, struct dirent *files, DIR *mydir)
{
	if (argc == 1)
	{
		while ((files = readdir(mydir)) != NULL)
		{
			if (files->d_name[0] != '.')
			{
				ft_putstr(files->d_name);
				ft_putchar('\t');
			}
		}
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	DIR *mydir;
	struct dirent *files;
	mydir = opendir(".");
	no_flags(argc, files, mydir);
	closedir(mydir);
	return (0);
}
