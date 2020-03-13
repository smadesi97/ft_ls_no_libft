#include "ft_ls.h"

int main(int ac, char *av[]) {
    int i = 0;
    t_ls_flags *data;
    if (!(data = (t_ls_flags *)malloc(sizeof(t_ls_flags))))
        return 0;
    if (ac > 1)
        ft_putstr("It's a flag");
    else {
        ft_ls(av);
    }
    return 0;
}