/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walktree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 22:23:18 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/09 22:23:21 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//method that will be used to get the list of dir in thet curr dir
char **get_dir(char **str, char *path)
{
    char **dir;
    int len;
    int i;
    int j;

    i = 0;
    j = 0;
    len = count_dir(str);
    dir = (char **)malloc(sizeof(char *) * len + 1);
    dir[len + 1] = NULL;
    while (str[j])
    {

        if (ft_strcmp(str[j], ".") != 0 && get_nLinks(get_path(path, str[j])) != 1 && ft_strcmp(str[j], "..") != 0)
        {
            dir[i] = ft_strdup(str[j]);
            i++;
        }
        j++;
    }
    return (dir);
}

//method will be used to get the paths of the files in subdir
char *get_path(char *folder, char *content)
{
    char *fullpath;
    char *add;
    DIR *check;

    if (folder && content)
    {
        check = opendir(folder);
        if (!check)
            return NULL;

        fullpath = ft_strjoin(folder, "/");
        add = fullpath;
        fullpath = ft_strjoin(fullpath, content);
        free(add);
        return (fullpath);
    }
    return NULL;
}

// method will be used to walk the directory tree
// will display the content of all the directories that have been walked
// void walktree(char *fullpath, char **str)
void walktree(char *fullpath, char **dirs)
{
    int i;
    char *child;
    DIR *mydir;
    char **content;
    struct dirent *files;

    child = ft_strdup(fullpath);
    mydir = opendir(child);
    if (!mydir)
        printf("fail to open\n");
    content = get_content(count(files, mydir, child), child);
    if (child && content)
        dirs = get_dir(content, child);
    i = 0;
    if (ft_strlen(child) > 0)
        printf("%s :\n", child);
    while (dirs[i])
    {
        if (ft_strlen(dirs[i]) > 0)
            child = get_path(fullpath, dirs[i]);
        if (ft_strlen(dirs[i]) > 0)
            walktree(child, &dirs[i]);
        i++;
    }
}