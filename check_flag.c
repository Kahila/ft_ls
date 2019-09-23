/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 22:34:14 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/09 22:34:45 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//method that will be used to split the path and the file
char *split_path(char *dir)
{
	int i;
	int j;
	int stop;
	char *path;

	j = i = 0;
	i = ft_strlen(dir);
	while (dir[i] != '/')
		i--;
	stop = i--;
	path = (char *)malloc(sizeof(char) * (i + 1));
	path[i + 1] = '\0';
	i = 0;
	while (j != stop)
	{
		path[j] = dir[i];
		i++;
		j++;
	}
	return (path);
}

//method that will be used to dertermine the flags passed
int check_flags(int argc, char **argv, t_flags *flags)
{
    int i;
    int j;

    j = i = 1;
    while (argv[j])
    {
        if (argv[j][0] != '-')
            return (INVALID_FLAG);
        i = 1;
        while (argv[j][i])
        {
            if (argv[j][i] == 'a')
                flags->a = 1;
            else if (argv[j][i] == 'l')
                flags->l = 1;
            else if (argv[j][i] == 't')
                flags->t = 1;
            else if (argv[j][i] == 'r')
                flags->r = 1;
            else if (argv[j][i] == 'R')
                flags->R = 1;
            else if (argv[j][i] != 'a' || argv[j][i] != 'r' || argv[j][i] != 't' || argv[j][i] != 'l' || argv[j][i] != 'R')
                return (INVALID_FLAG);
            i++;
        }
        j++;
    }
    return (VALID_FLAG);
}