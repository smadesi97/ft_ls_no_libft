#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"

int validate_flags(char *s, t_ls_flags *fs) {
    int i;
    size_t j;
    char *s2;
    // int count;

    i = 0;
    j = -1;
    // count = 0;
    s2 = "aRrtl";
    while (s[++i]) {
        while (s2[++j])
            if (s[i] == s2[j]) {
                set_flags(s[i], &fs);
                break;
            }
        if (ft_strlen(s2) == j) {
            ft_putstr_fd("ls: invalid option -- \'", 2);
            ft_putchar_fd(s[i], 2);
            ft_putstr_fd("\'\n", 2);
            return (0);
        }
        j = -1;
    }
    return 1;
}