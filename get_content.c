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
int count_(char *folder)
{
	int tot = 0;
	struct dirent *files;
	DIR *mydir; 

	mydir = opendir(folder);
	while ((files = readdir(mydir)) != NULL)
		tot++;
	//closedir(mydir);
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

//method that will be used to get the content within a folder
char **save_(char *folder)
{
	int tot;
	char **content;
	int j = 0;
	DIR *mydir2;
	struct dirent *files2;

	mydir2 = opendir(folder);
	if (mydir2)
		tot = count_(folder);
	else
		return NULL;
	content = (char **)malloc(sizeof(char *) * (tot));
	while ((files2 = readdir(mydir2)) != NULL)
	{
		//printf("....here\n");
		content[j] = ft_strdup(files2->d_name);
		//printf(".....after\n");
		j++;
	}
	content[tot] = NULL;
	closedir(mydir2);
	return (content);
}

//this method will be used to get the names of the files/folders
char **get_content(int tot, char *folder, t_flags flags)
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
	if (flags.t == 1)
		content = flag_t(content, folder);
	if (flags.r == 1)
		content = rev(content);
	if (flags.l == 1 && flags.a != 1)
		saveData(tot, content, lst, folder);
	if (flags.l == 1 && flags.a == 1)
		saveData((tot + 1000000), content, lst, folder);

	return (content);
}