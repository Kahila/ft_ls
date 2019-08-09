/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:51:16 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/09 12:31:07 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"
#include <stdio.h>//remember to remove

//this fuction will be used to sort 
char 				**bubble_sort(char **str)
{
	int j;
	int i;
	i = 0;
	char *tmp = str[0];

	while(str[i]){
		j = 0;
		while(str[j]){
			if (ft_strcmp(str[i], str[j]) < 0){
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

// //method that will be used to desplay the file names in reverse
// void				revers_flag(int argc, char **content)
// {
// 	int i;

// 	if (argc == 1)
// 	{
// 		i = 0;
// 		while (content[i])
// 		{
// 			if (content[i][0] != '.')
// 			{
// 				ft_putstr(content[i]);
// 				ft_putchar('\t');
// 			}
// 			i++;
// 		}
// 	}
// 	return;
// }

// //method will be used desplay the content within the directory without a flag
// void				no_flags(int argc, char **content)
// {
// 	int i;

// 	if (argc == 1)
// 	{
// 		i = 0;
// 		while (content[i])
// 		{
// 			//printf("\n>>>%d\n", i);
// 			if (content[i][0] != '.')
// 			{
// 				ft_putstr(content[i]);
// 				ft_putchar('\t');
// 			}
// 			i++;
// 		}
// 	}
// 	return;
// }

// //this method will display all files including hidden ones
// void				hidden_flag(int argc, char **content, char *argv)
// {
// 	int i;

// 	if (argc > 1 && argv[0] == POTENTIAL_FLAG && argv[1] == HIDDEN_FILES)
// 	{
// 		i = 0;
// 		while (content[i])
// 		{
// 			ft_putstr(content[i]);
// 			ft_putchar('\t');
// 			i++;
// 		}
// 	}
// 	return;
// }

// //last thought working on the permisions 
// //this method will be used for the -l flag
// void			file_info(char **content, char *argv)
// {
// 	struct stat buff;
// 	int i;
// 	if (argv[0] == '-' && argv[1] == 'l')
// 	{
// 	i = 0;
// 	int size;
// 	while (content[i])
// 	{
// 		stat(content[i], &buff);
// 		if ((size = buff.st_nlink) > 1)
// 			{
// 				//printf("in here\n");
// 				ft_putstr("d ->");
// 				ft_putstr(content[i]);
// 			}
// 			else
// 			{
// 				ft_putstr("- ->");
// 				ft_putstr(content[i]);
// 			}
			
// 			printf("\n");
// 		i++;
// 	}
// 	}
// }

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
	printf("at the end count_content tota = %d\n", tot);
	get_content(tot, argc, argv);
}

int main(int argc, char **argv)
{
	printf("here main\n");
	DIR *mydir;
	struct dirent *files=NULL;
	mydir = opendir(".");
	//struct stat buff;
	mydir = opendir(".");
	count_content(files, mydir, argc,argv[1]);
	//closedir(mydir);
	//int i = stat("libft", &buff);
	//time_t *curr_time;
	//int j = buff.st_mode;
	//printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n%ld\n%d\n",time(curr_time), j);
	return (SUCCESS);
}
