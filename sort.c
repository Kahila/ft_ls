/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 23:30:56 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/09 23:31:00 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

//this method will be used to arrange the files befor sorting them
char				**sort_first(char **str)
{
	int j;
	int i;
	i = 0;
	char *tmp = str[0];
	struct stat buff1;
	struct stat buff2;
	while(str[i]){
		j = 0;
		while(str[j]){
			if (ft_strcmp(last_mod(str[i]), last_mod(str[j])) > 0)
			{
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

//this method will sort the files accoring to the last modified
char				**flag_t(char **str, char *folder)
{
	int j;
	int i;
	i = 0;
	char *tmp = str[0];
	str = sort_first(str);
	struct stat buff1;
	struct stat buff2;
	while(str[i]){
		j = 0;
		stat(get_path(folder, str[i]), &buff1);
		while(str[j]){
			stat(get_path(folder, str[j]), &buff2);
			if (buff2.st_mtime < buff1.st_mtime)
			{
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