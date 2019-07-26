/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:51:16 by akalombo          #+#    #+#             */
/*   Updated: 2019/07/26 21:30:15 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"
#include <stdio.h>//remember to remove

//last thought ... to get string that will store all the file/dir names and then split using str split .... then sort the list in lexicographical order ... then display from the ** that contains the files


//method will be used to sort the names of the functions lexicographically
void insert_sort()
{

	return;
}

//this functions will mimic the ls command without the any flags
int 				no_flags(int argc, struct dirent *files, DIR *mydir)
{
	int tot = 0;
	if (argc == 1)
	{
		int i = 0;
		int l = 0;;
		while ((files = readdir(mydir)) != NULL)
		{
			//will not display any hidden folders
			if (files->d_name[0] != '.')
			{
				i = 0;
				while (files->d_name[i])
				{
					l += files->d_name[i];
					//printf("%c/", files->d_name[i]);
					i++;
				}
				ft_putstr(files->d_name);
				ft_putchar('\t');
				tot++;
			}
		}
		return (tot);
	}
	return (0);
}

//this method will mimic the ls commnad with the -a flag
int					flag_hidden(int argc, char *argv,struct dirent *files, DIR *mydir)
{
	int tot = 0;
	if (argc == 2 && argv[0] == POTENTIAL_FLAG && argv[1] == HIDDEN_FILES)
	{
		int i = 0;
		int l = 0;
		while ((files = readdir(mydir)) != NULL)
		{
			i = 0;
			while (files->d_name[i])
			{
				l += files->d_name[i];
				i++;
			}
			//desplaying all folders including hidden folders
			ft_putstr(files->d_name);
			ft_putchar('\t');
			tot++;
		}
		return (tot);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int i;
	DIR *mydir;
	struct dirent *files;
	struct dirent *count;
	mydir = opendir(".");
	no_flags(argc, files, mydir);
	flag_hidden(argc, argv[1], files, mydir);
	ft_putnbr(i);
	closedir(mydir);
	return (SUCCESS);
}
