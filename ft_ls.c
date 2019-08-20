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

int main(int argc, char **argv)
{
	DIR *mydir;
	struct dirent *files;

	char *folder = ft_strdup("./");
	mydir = opendir(folder);
	if (!mydir)
		printf("fail to open\n");
	count_content(files, mydir, folder);
	closedir(mydir);
	return (SUCCESS);
}
