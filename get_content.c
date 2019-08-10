/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:49:00 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/09 16:49:03 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ls.h"

//this method will count the amount of content within the ./
void			count_content(struct dirent *files, DIR *mydir)
{
	int tot = 0;
	while ((files = readdir(mydir)) != NULL)
	{
		tot++;
	}
	get_content(tot, files, mydir);
}

//this method will be used to get the names of the files/folders
void			get_content(int tot, struct dirent *files, DIR *mydir)
{
	char **content;
	int j = 0;
    static t_list *lst;
	 DIR *mydir2;
		struct dirent *files2;
	mydir2 = opendir(".");
	content = (char **)malloc(sizeof(char *) * (tot + 1));
	int i = 0;
	int l = 0;
	while ((files2 = readdir(mydir2)) != NULL)
	{
	//	printf("%s here\n", files2->d_name);
		content[j] = ft_strdup(files2->d_name);
        j++;
	}
	closedir(mydir2);
    content = bubble_sort(content);
	saveData(tot, content, lst);
	content[tot + 1] = NULL;
	return;
}