/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:33:13 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/13 11:49:41 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//this method will be used to get the permisions for the user.group and other
char            *permits(char *file)
{
    struct stat buff;
    int i;
    char *str;

    if ((stat(file, &buff) < 0))
    {
            return (NULL);
    }
    i = stat(file, &buff);
    str = ft_memalloc(sizeof(char)*10);
    S_ISDIR(buff.st_mode) ? str[0] = 'd' : (str[0] = '-');
    (buff.st_mode & S_IRUSR) ? str[1] = 'r' : (str[1] = '-');
    (buff.st_mode & S_IWUSR) ? str[2] = 'w' : (str[2] = '-');
    (buff.st_mode & S_IXUSR) ? str[3] = 'x' : (str[3] = '-');
    (buff.st_mode & S_IRGRP) ? str[4] = 'r' : (str[4] = '-');
    (buff.st_mode & S_IWGRP) ? str[5] = 'w' : (str[5] = '-');
    (buff.st_mode & S_IXGRP) ? str[6] = 'x' : (str[6] = '-');
    (buff.st_mode & S_IROTH) ? str[7] = 'r' : (str[7] = '-');
    (buff.st_mode & S_IWOTH) ? str[8] = 'w' : (str[8] = '-');
    (buff.st_mode & S_IXOTH) ? str[9] = 'x' : (str[9] = '-');
    str[10] = '\0';
    return (str);
}

//method that will be used to save the dirs passed to programe
char **save_dirs(int argc, char **argv)
{
	int tot;
	char **dir;
	DIR *mydir;
	int i;
	int j;

	tot = num_dir(argc, argv);
	dir = (char **)malloc(sizeof(char *) * (tot));
	dir[tot] = NULL;
	i = 0;
	j = 1;
	while (j <= argc)
	{
		mydir = opendir(argv[j]);
		if (mydir)
		{
			dir[i] = argv[j];
			i++;
		}
		j++;
	}
	return (dir);
}

//method that will loop through each folder
void ft_ls(char *folder, struct dirent *files, t_flags flags, char **content)
{
	DIR *mydir;
	int tot;

	mydir = opendir(folder);
	if (!mydir)
		printf("fail to open\n");
	tot = count(files, mydir, folder);
	content = get_content(tot, folder, flags);
	print_content(content, &flags);
	closedir(mydir);
}

//method that will be used to check if the parsed file is a folder or not
void valid_file(char **content, char **args, t_flags flags)
{
	int i;
	int j;
	int found;

	found = i = 0;
	while (args[i])
	{
		j = 0;
		while (content[j])
		{
			//printf(">>>%s\n", content[j]);
			if ((ft_strcmp(args[i], content[j])) == 0)
			{
				ft_putstr(args[i]);
				ft_putchar('\n');
				found = 1;
			}
			j++;
		}
		if (found == 0)
		{
			pathed_file(args[i], flags);
		}
		i++;
	}
}