/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:49:00 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/13 11:41:09 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//this method will count the amount of content within the ./
int count(struct dirent *files, DIR *mydir, char *folder)
{
	int tot = 0;

	while ((files = readdir(mydir)) != NULL)
		tot++;
	//get_content(tot, folder);
	return tot;
}

//method that will be used to count the number of dir's in the curr working dir
int count_dir(char **str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], ".") != 0 && get_nLinks(str[i]) != 1 && ft_strcmp(str[i], "..") != 0)
			j++;
		i++;
	}
	return (j);
}

//this method will be used to get the names of the files/folders
char **get_content(int tot, char *folder)
{
	char **content;
	int j = 0;
	static t_list *lst;
	DIR *mydir2;
	struct dirent *files2;
	mydir2 = opendir(folder);
	content = (char **)malloc(sizeof(char *) * (tot));
	while ((files2 = readdir(mydir2)) != NULL)
	{
		content[j] = ft_strdup(files2->d_name);
		j++;
	}
	content[tot] = NULL;
	closedir(mydir2);
	content = bubble_sort(content);
	// int i = 0;
	// while (content[i])
	// {
	// 	printf("%s\n", content[i]);
	// 	i++;
	// }
	//saveData(tot, content, lst, folder);
	//get_dir(content);
	//content = flag_t(content, folder);
	//content = sort_first(content);
	return (content);
}