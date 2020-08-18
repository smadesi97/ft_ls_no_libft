#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

void dash_t(DIR *p_dir, char *path)
{
    struct dirent *dir;
    p_dir = opendir(path); //set path to directory
    if (p_dir)
    {
        while ((dir = readdir(p_dir)) != NULL)
        {
            //exclude "." and ".."
            if (ft_strncmp(dir->d_name, ".", 1) == 0)
            {
                continue;
            }
            // printf("%s\n", dir->d_name);
            ft_putstr(dir->d_name);
            ft_putchar('\n');
            // getFileCreationTime(dir->d_name);
        }
        closedir(p_dir);
    }
}