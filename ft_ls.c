/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:51:16 by akalombo          #+#    #+#             */
/*   Updated: 2019/07/31 14:41:13 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"
#include <stdio.h>//remember to remove

//this fuction will be used to sort 
char 				**bubble_sort(char **str)
{
	int i;
	int j;
	i = 0;
	char *tmp = str[0];

	while(str[i]){
		j = 0;
		while(str[j]){
			if (strcmp(str[i], str[j]) < 0){
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

//method that will be used to desplay the file names in reverse
void				revers_flag(int argc, char **content)
{
	int i;

	if (argc == 1)
	{
		i = 0;
		while (content[i])
		{
			if (content[i][0] != '.')
			{
				ft_putstr(content[i]);
				ft_putchar('\t');
			}
			i++;
		}
	}
	return;
}

//method will be used desplay the content within the directory without a flag
void				no_flags(int argc, char **content)
{
	int i;

	if (argc == 1)
	{
		i = 0;
		while (content[i])
		{
			if (content[i][0] != '.')
			{
				ft_putstr(content[i]);
				ft_putchar('\t');
			}
			i++;
		}
	}
	return;
}

//this method will display all files including hidden ones
void				hidden_flag(int argc, char **content, char *argv)
{
	int i;

	if (argc > 1 && argv[0] == POTENTIAL_FLAG && argv[1] == HIDDEN_FILES)
	{
		i = 0;
		while (content[i])
		{
			ft_putstr(content[i]);
			ft_putchar('\t');
			i++;
		}
	}
	return;
}

//this method will save all the ontent names which will be sorted
void			get_content(int tot, int argc, char *argv)
{
	static char **content;
	static int j = 0;
	DIR *mydir;
	struct dirent *files;
	struct dirent *count;
	mydir = opendir(".");
	content = (char **)malloc(sizeof(char *) * (tot + 1));
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
		content[j] = ft_strdup(files->d_name);
		j++;
	}
	closedir(mydir);
	content = bubble_sort(content);
	no_flags(argc, content);
	hidden_flag(argc, content, argv);
	content[tot + 1] = NULL;
	return;
}

//this method will count the amount of content within the ./
void			count_content(struct dirent *files, DIR *mydir, int argc, char *argv)
{
	int tot = 0;
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
		tot++;
	}
	get_content(tot, argc, argv);
}

int main(int argc, char **argv)
{
	DIR *mydir;
	struct dirent *files;
	struct dirent *count;
	
	mydir = opendir(".");
	count_content(files, mydir, argc,argv[1]);
	closedir(mydir);
	return (SUCCESS);
}