#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

void path_handler(char *path, t_ls_flags *fs)
{
    DIR *p_dir;
    struct dirent *ped;

    remove_trailing_slash(&path);
    // new_dir = path;
    p_dir = opendir(path);
    if (!p_dir)
    {
        perror("Could not open");
        exit(EXIT_FAILURE);
    }
    if (!fs->f_R && !fs->f_l && !fs->f_t && !fs->f_a && !fs->f_r)
    {
        while ((ped = readdir(p_dir)))
        {
            if ((!strcmp(ped->d_name, ".") || !strcmp(ped->d_name, "..")))
                continue;
            if (!ft_strncmp(ped->d_name, ".", 1))
                continue;
            ft_putstr(ped->d_name);
            ft_putchar('\t');
        }
        ft_putchar('\n');
    }

    if (fs->f_R)
    {
        while ((ped = readdir(p_dir)))
        {
            if ((!strcmp(ped->d_name, ".") || !strcmp(ped->d_name, "..")))
                continue;
            else if (!ft_strncmp(ped->d_name, ".", 1) && fs->f_a)
                continue;
            ft_putstr(ped->d_name);
            ft_putchar('\t');
        }
        dash_R(p_dir, fs, path);
    }
    else if (fs->f_a)
    {
        dash_a(p_dir, path, fs);
    }
    else if (fs->f_t)
    {
        dash_t(p_dir, path);
    }
    else if (fs->f_l)
    {
        dash_l(p_dir, fs, path);
    }
}