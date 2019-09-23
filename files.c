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

//method that will be used to split the path and the file
char *split_path(char *dir)
{
	int i;
	int j;
	int stop;
	char *path;

	j = i = 0;
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

//method that will be used to handle the -l flag on single files
void	_lFlag(char *content, char *dir)
{
	printf("%s\t", permits(dir));
	printf("%d\t", get_nLinks(content));
	printf("%s\t", user(content));
	printf("%s\t", group(dir));
	printf("%d\t", nBytes(dir));
	printf("%s\t", last_mod(dir));
	printf("%s\n", dir);
}

//method that will be used to check if the file is within the passed folder
void in_path(char *dir, char **content, char *file, t_flags flags)
{
	int i;
	int found;

	i = 0;
	while (content[i])
	{
		found = ft_strcmp(content[i], file);
		if (found == 0)
		{
			if (flags.l)
				_lFlag(content[i], dir);
			else
				ft_putstr(dir);
			ft_putchar('\n');
			return;
		}
		i++;
	}
			ft_putstr("ls: ");
			ft_putstr(dir);
			ft_putstr(" : No such file or directory\n");
}

//this method will be used to check for single files passed from other dirs
void pathed_file(char *dirs, t_flags flags)
{
	if (path_(dirs))
	{
		char *path;
		char *file;
		char **content;

		path = split_path(dirs);
		file = ft_strrchr(dirs, '/');
		file++;
		content = save_(path);
		in_path(dirs,content, file, flags);
	}
	else
	{
		ft_putstr("ls: ");
		ft_putstr(dirs);
		ft_putstr(" : No such file or directory\n");
	}
}