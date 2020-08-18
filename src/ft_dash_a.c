#include "../includes/ft_ls.h"

void    dash_a(DIR *p_dir, char *path, t_ls_flags *fs) {
    struct dirent *ped;
    struct stat mystat;

    fs->f_a = 1;

    //char buf[512];
    p_dir = opendir(path);
    while ((ped = readdir(p_dir)) != NULL) {
        stat(ped->d_name, &mystat);
        // printf("%lld", mystat.st_size);
        // printf("%s\n", ped->d_name);
        ft_putstr(ped->d_name);
        ft_putchar('\n');

    }
    closedir(p_dir);
}