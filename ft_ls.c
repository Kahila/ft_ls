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
void print_content(char **content, t_flags *flags, int count)
{
	int i;

	if (flags->r == 1)
		i = count - 1;
	else
		i = 0;
	while (count-- != 0)
	{
		if (flags->a == 1 && content[i][0] == '.')
		{
			ft_putstr(content[i]);
			ft_putchar('\n');
		}
		else if (content[i][0] != '.')
		{
			ft_putstr(content[i]);
			ft_putchar('\n');
		}
		if (flags->r == 1)
			i--;
		else
			i++;
	}
}

int main(int argc, char **argv)
{
	DIR *mydir;
	char **content;
	t_flags flags;
	int tot;
	char **dirs;
	struct dirent *files;
	char *folder = ft_strdup(".");
	mydir = opendir(folder);
	tot = check_flags(argc, argv, &flags);
	if (!mydir)
		printf("fail to open\n");
	tot = count(files, mydir, folder);
	content = get_content(tot, folder, flags);
	print_content(content, &flags, tot);
	//walktree(folder, dirs);
	closedir(mydir);
	return (SUCCESS);
}