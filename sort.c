/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 23:30:56 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/09 23:31:00 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char **rev(char **content)
{
	char **str;

	int i = 0;
	int j = 0;

	while (content[j])
		j++;
	str = (char **)malloc(sizeof(char *) * (j));
	str[j] = NULL;
	j--;
	while (j >= 0)
	{
		str[i] = (content[j]);
		j--;
		i++;
	}
	free(content);
	return (str);
}

//this fuction will be used to sort
char **bubble_sort(char **str)
{
	int j;
	int i;
	i = 0;
	char *tmp = str[0];
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) < 0)
			{
				tmp = str[j];
				str[j] = str[i];
				str[i] = tmp;
			}
			j++;
		}
		i++;
	}
	return (str);
}

//this method will be used to arrange the files befor sorting them
char **sort_first(char **str)
{
	int j;
	int i;

	i = 1;
	char *tmp = str[0];
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (ft_strcmp(last_mod(str[i]), last_mod(str[j])) > 0)
			{
				tmp = str[j];
				str[j] = str[i];
				str[i] = tmp;
			}
			j++;
		}
		i++;
	}
	return (str);
}

//method will be used to get the full path of file
char *_path(char *folder, char *content)
{
    char *fullpath;
	char *here;
    char *add;
    DIR *check;

    if (content)
    {
        fullpath = ft_strjoin(folder, "/");
        add = fullpath;
		if (fullpath)
			free(fullpath);
		here = add;
        here = ft_strjoin(add, content);
		free(add);
        return (here);
    }
    return NULL;
}

//this method will sort the files accoring to the last modified
char **flag_t(char **str, char *folder)
{
	int j;
	int i;
	char *tmp;
	struct stat buff1;
	struct stat buff2;

	i = 0;
	//sort_first(str);//fix this function
	while (str[i])
	{
		j = 1;
		stat(_path(folder, str[i]), &buff1);
		while (str[j])
		{
			stat(_path(folder, str[j]), &buff2);
			if (buff2.st_mtime == buff1.st_mtime)
			{
				if (buff2.st_mtimespec.tv_nsec < buff1.st_mtimespec.tv_nsec)
				{
					tmp = str[j];
					str[j] = str[i];
					str[i] = tmp;
				}
			}
			j++;
		}
		i++;
	}
	return (str);
}