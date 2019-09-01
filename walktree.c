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
    //printf("here\n");
    len = count_dir(str);
    dir = (char **)malloc(sizeof(char *) * len + 1);
    dir[len + 1] = NULL;
    while (str[j])
    {

        if (ft_strcmp(str[j], ".") != 0 && get_nLinks(get_path(path, str[j])) != 1 && ft_strcmp(str[j], "..") != 0)
        {
            dir[i] = ft_strdup(str[j]);
            //printf(">>>>%s   %d\n\n", dir[i], get_nLinks(get_path(path, str[j])));
            i++;
        }
        j++;
    }
    //printf("....%d\n", i);
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
        //fullpath = ft_strjoin(fullpath, "/");
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
    int i; //= 0;
    //char **dirs;
    char *child;
    DIR *mydir;
    char **content;
    int tot;
    struct dirent *files;
    child = ft_strdup(fullpath);
    //char *folder = ft_strdup(child);
    mydir = opendir(child);
    if (!mydir)
        printf("fail to open\n");
    tot = count_content(files, mydir, child);
    //char **new = get_path(fullpath);
    //new = (fullpath, content);
    // printf("%s\n", new[i]);
    //printf(">>>%s\n", *dirs++);
    //get_path(child, dirs[i]);
    content = get_content(tot, child);
    if (child && content)
        dirs = get_dir(content, child); // replace get_dir with a function gives you list of directories in fullpath dir
    //printf("total  = %d\n", tot);
    // int c = 0;
    // int s = count_dir(content);
    // while (content[c])
    // {
    //     printf("%s\n", content[c]);
    //     c++;
    // }
    i = 0;
    // while (dirs[i])
    // {
    //printf("~~~~~~~~~~~~~~~~~~~~~~~here~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    //if (child[ft_strlen(child) - 1] != '/')
    // printf(">>>|dir[%d] = |%s| >>> path = |%s|\n", i, dirs[i], child);
    //get_content(tot, child);
    //printf("\n>>>>>|%s == %d|<<<<<<<<", child, i);
    //if (dirs[i])
    // {
    // if (child[ft_strlen(child) - 1] != '/')
    printf(">>>>>>>%s\n", child);
    // if (child[ft_strlen(child) - 1] != '/')
    //closedir(mydir);
    // printf("")
    while (dirs[i])
    {
        //printf(".....%zu....\n", ft_strlen(dirs[i]));
        if (ft_strlen(dirs[i]) > 0)
        {
            child = get_path(fullpath, dirs[i]);
        }
        //printf(".....i = %d..... tot = %d........\n", i, s - 1);
        printf("here outside\n");
        if (ft_strlen(dirs[i]) > 0)
        {
            walktree(child, &dirs[i]);
            printf("here loop\n");
        }
        i++;
        //printf("at end.....\n");
    }
    //}
    //printf("-======================================================-\n");
    //i++;
    //}
    //closedir(mydir);
    return;
}