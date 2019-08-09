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

//this method will be used to get the names of the files/folders
void			get_content(int tot, int argc, char *argv)
{
	static char **content;
	static int j = 0;
	DIR *mydir;
	struct dirent *files;
	//struct dirent *count;
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
//	no_flags(argc, content);
//	hidden_flag(argc, content, argv);
//	file_info(content, argv);
    content = bubble_sort(content);
	saveData(tot, content);
	content[tot + 1] = NULL;
	return;
}
