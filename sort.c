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