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

//method that will be used to display the content
void print_content(char **content)
{
	int i;

	i = 0;
	while (content[i])
	{
		ft_putstr(content[i]);
		ft_putchar('\n');
		i++;
	}
}

int main(int argc, char **argv)
{
	DIR *mydir;
	char **content;
	int tot;
	char **dirs;
	struct dirent *files;
	char *folder = ft_strdup(argv[1]);
	mydir = opendir(folder);
	if (!mydir)
		printf("fail to open\n");
	tot = count(files, mydir, folder);
	content = get_content(tot, folder);
	print_content(content);
	//walktree(folder, dirs);
	//closedir(mydir);
	return (SUCCESS);
}