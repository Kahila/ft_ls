/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:51:16 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/13 11:50:35 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"
#include <stdio.h> //remember to remove

//method that will be used to get files that are not folders
int num_files(int argc, char **argv)
{
	int count;
	int i;
	DIR *mydir;

	i = 1;
	count = 0;
	while (argv[i] && argc > 1)
	{
		mydir = opendir(argv[i]);
		if (!mydir)
		{
			if (argv[i][0] != '-')
				count++;
		}
		else
			closedir(mydir);
		i++;
	}
	return (count);
}

//method that will be used o find the number of dirs passed to the program
int num_dir(int argc, char **argv)
{
	int count;
	int i;
	DIR *mydir;

	i = 0;
	count = 0;
	while (argv[i])
	{
		mydir = opendir(argv[i]);
		if (mydir)
		{
			count++;
			closedir(mydir);
		}
		i++;
	}
	return (count);
}

//method that will be used to save the other files that are not folders
char **save_files(int argc, char **argv, t_flags flags)
{
	int tot;
	char **dir;
	DIR *mydir;
	int i;
	int j;

	tot = num_files(argc, argv);
	if (tot > 0)
		dir = (char **)malloc(sizeof(char *) * (tot));
	dir[tot] = NULL;
	i = 0;
	j = 1;
	while (j < argc)
	{
		mydir = opendir(argv[j]);
		if (!mydir)
		{
			if (argv[j][0] != '-')
			{
				dir[i] = argv[j];
				i++;
			}
		}
		else
			closedir(mydir);

		j++;
	}
	dir = bubble_sort(dir);
	return (dir);
}

int main(int argc, char **argv)
{
	char **content;
	t_flags flags;
	int tot;
	char **dirs;
	char **sFiles;
	int i;
	struct dirent *files;

	tot = check_flags(argc, argv, &flags);
	int s = 0;
	if ((num_files(argc, argv)) > 0)
	{
		sFiles = save_files(argc, argv,flags);
		content = save_(".");
		valid_file(content, sFiles, flags);
	}
	if (tot == INVALID_FLAG)
		dirs = save_dirs(argc, argv);
	if ((num_dir(argc, argv)) == 0 && tot == INVALID_FLAG)
		return (INVALID_FLAG);
	else if ((tot = num_dir(argc, argv)) == 0)
		ft_ls(".", files, flags, content);
	else
	{
		i = 0;
		while (i < tot)
		{
			ft_putchar('\n');
			ft_ls(dirs[i], files, flags, content);
			ft_putchar('\n');
			i++;
		}
	}
	while(1 == 1)
	{

	}
	return (SUCCESS);
}