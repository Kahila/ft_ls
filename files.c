#include "ft_ls.h" 

//method that will be used to split the path and the file
char *split_path(char *dir)
{
	int i;
	int j;
	char *path;

	j = i = 0;
	while (dir[i])
		i++;
	while (dir[i] != '/')
		i--;
	path = (char *)malloc(sizeof(char) *i);
	path[i] = '\0';
	i = 0;
	while (path[j])
	{
		path[j] = dir[i];
		i++;
		j++;
	}
	return (path);
}

//method will check if the passed strings have paths
int path_(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
	}
	return (0);
}

//this method will be used to check for single files passed from other dirs
void pathed_file(char *dirs)
{
	if (path_(dirs))
	{
		char *path;
		char **content;

		path = split_path(dirs); 
		content = save_(path);	
}
	ft_putstr("ls: ");
	ft_putstr(dirs);
	ft_putstr(" : No such file or directory\n");
}
