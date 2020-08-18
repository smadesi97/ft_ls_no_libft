#include "../includes/ft_ls.h"

void init_flags(t_ls_flags *flags) {
    flags->f_a = 0;
    flags->f_R = 0;
    flags->f_l = 0;
    flags->f_r = 0;
    flags->f_t = 0;
}

void set_flags(char c, t_ls_flags **fs) {
    if (c == 'a')
        (*fs)->f_a = 1;
    else if (c == 'R')
        (*fs)->f_R = 1;
    else if (c == 't')
        (*fs)->f_t = 1;
    else if (c == 'r')
        (*fs)->f_r = 1;
    else if (c == 'l')
        (*fs)->f_l = 1;
}