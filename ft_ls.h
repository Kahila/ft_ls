/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:38:54 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/13 10:52:15 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include "libft_/libft.h"
#include <unistd.h>
#include <time.h>     //working with the time and the ctime functions
#include <dirent.h>   //working with the opendir, readdir and closedir functions
#include <sys/stat.h> //working with the stat function and lstat functions
#include <grp.h>
#include <sys/types.h> //
#include <pwd.h>       //working with the passwd struct;
#include <uuid/uuid.h> //working with the uuid_t data type
#include <sys/xattr.h> //working with the listaxttr and the getxattr functions
#include <stdlib.h>    //working with the malloc, exit and free functions
#include <string.h>    //working with the strerror function
#include <stdio.h>     //working with the perror function
#include <errno.h>
#include <stdio.h> //remember to remove
#define POTENTIAL_FLAG '-'
#define HIDDEN_FILES 'a'
#define FILE_DETAILS 'l'
#define RECURSIVE_LS 'R'
#define SORT_LAST_MODI 't'
#define SORT_REV_LEXO 'r'
enum statusCodes
{
    SUCCESS,
    VALID_FLAG,
    INVALID_FLAG = -1,
    IS_FILE,
    IS_FOLDER,
    FAILED,
    FAILED_TO_READ_FILE_INFO
};
typedef struct s_flags
{
    int l;
    int a;
    int r;
    int t;
    int R;
} t_flags;

typedef struct s_list
{
    int nLinks;
    int dirORfile;
    int nBytes;
    char *last_modified;
    char *user;
    char *group;
    char *fileName;
    char *permits;
    struct s_list *next;
    struct s_list *prev;
} t_list;
char *get_path(char *folder, char *content);
int check_flags(int argc, char **argv, t_flags *flags);
//char **get_dir(t_list *lst, char *folder, t_list *head)
//char **get_dir(char **str);
char *permits(char *file);
char **flag_t(char **str, char *);
char **rev(char **content);
char *user(char *);
char *group(char *);
char **get_content(int tot, char *folder, t_flags flags);
char *last_mod(char *);
char *get_flags(int argc, char **argv);
char **bubble_sort(char **str);
char **sort_first(char **str);
void saveData(int, char **, t_list *, char *full_path);
void flag_l(t_list *lst, t_list *head);
void revers_flag(int argc, char **content);
void no_flags(int argc, char **content);
void hidden_flag(int argc, char **content, char *argv);
int count(struct dirent *files, DIR *mydir, char *folder);
void file_info(char **content, char *argv);
void flag_al(t_list *lst, t_list *head);
void flag_a(t_list *lst, t_list *head);
void no_flag(t_list *lst, t_list *head);
void flag_r(t_list *lst, t_list *head);
void walktree(char *fullpath, char **, t_flags flags);
int get_nLinks(char *content);
//int count_dir(t_list *lst, t_list *head, char *folder);
int count_dir(char **str);
int is_file(int nlinks);
int valid_flag(int argc, char **argv);
//int get_nLinks(char *content);
int tot_leng(char **argv);
#endif
