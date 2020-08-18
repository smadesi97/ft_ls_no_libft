#include "../libft/includes/libft.h"

void remove_trailing_slash(char **s) {
    int i;
    char *ss;

    ss = *s;
    i = -1;
    while (ss[++i])
        if (ss[i] == '/' && (!ft_isprint(ss[i + 1]) || ss[i + 1] == '/'))
            ss[i] = '\0';
    *s = ss;
}