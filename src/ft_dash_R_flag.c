#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

void dash_R(DIR *p_dir, t_ls_flags *fs, char *path)
{
    char *new_dir;
    struct dirent *ped;
    closedir(p_dir);
    p_dir = opendir(path);
    while ((ped = readdir(p_dir)))
    {
        if (!strcmp(ped->d_name, ".") || !strcmp(ped->d_name, ".."))
            continue;
        else if (!ft_strncmp(ped->d_name, ".", 1) && !fs->f_a)
            continue;
        else
        {
            if (ped->d_type == 4)
            {
                new_dir = ft_strjoin(path, "/");
                new_dir = ft_strjoin(new_dir, ped->d_name);
                // ft_putchar('\n');
                ft_printf("\n ==> %s\n", new_dir);
                // ft_putstr(new_dir);
                // ft_putstr_fd(" \n =====> \'", 2);
                path_handler(new_dir, fs);
                free(new_dir);
                ft_putchar('\n');
            }
        }
    }
}