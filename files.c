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
	ft_putstr(permits(dir));
	ft_putchar('\t');
	ft_putnbr(get_nLinks(content));
	ft_putchar('\t');
	ft_putstr(user(dir));
	ft_putchar('\t');
	ft_putstr(group(dir));
	ft_putchar('\t');
	ft_putnbr(nBytes(dir));
	ft_putchar('\t');
	ft_putstr(last_mod(dir));
	ft_putstr(dir);
	ft_putchar('\n');
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
		free(path);
	}
	else
	{
		ft_putstr("ls: ");
		ft_putstr(dirs);
		ft_putstr(" : No such file or directory\n");
	}
}