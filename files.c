/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:58:43 by akalombo          #+#    #+#             */
/*   Updated: 2019/09/18 11:58:46 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

//last action ... saving the file within the path

//method that will be used to split the path and the file
char *split_path(char *dir)
{
	int i;
	int j;
	int stop;
	char *path;

	j = i = 0;
	// while (dir[i])
	// 	i++;
	i = ft_strlen(dir);
	while (dir[i] != '/')
		i--;
	stop = i--;
	path = (char *)malloc(sizeof(char) * (i + 1));
	path[i + 1] = '\0';
	i = 0;
	while (j != stop)
	{
		path[j] = dir[i];
		i++;
		j++;
	}
	//printf("#####path = %s\n", path);
	return (path);
}

//method will check if the passed strings have paths
int path_(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

// //method that will get the path
// char *split_file(char *dir)
// {
// 	int i;
// 	int j;
// 	int tot;
// 	char *new;

// 	tot = j = i = 0;
// 	while (dir[i])
// 		i++;
// 	i--;
// 	while (dir[i] != '/')
// 	{
// 		tot++;
// 		i--;
// 	}
// 	printf(">>>>>>>>>>here tot = %d\n", tot);
// 	new = (char *)malloc(sizeof(char) * (tot));
// 	new[tot] = '\0';
// 	printf("j = %d\n", j);
// 	i++;
// 	while (j < tot)
// 	{
// 		//printf("here in\n");
// 		new[j] = dir[i];
// 		printf("(%c)\n", new[j]);
// 		i++;
// 		j++;
// 		printf("save path\n");
// 	}
// 	printf("file == %s\n", new);
// }

//this method will be used to check for single files passed from other dirs
void pathed_file(char *dirs)
{
	if (path_(dirs))
	{
		char *path;
		char *file;
		char **content;

		path = split_path(dirs);
		file = ft_strrchr(dirs, '/');
		//split_file(dirs);
		file++;
		printf("==== %s\n", file);
		printf(">>>>>%s\n", path);
		//content = save_(path);
	}
	ft_putstr("ls: ");
	ft_putstr(dirs);
	ft_putstr(" : No such file or directory\n");
}
