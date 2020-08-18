/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadesi <smadesi@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:55:02 by smadesi           #+#    #+#             */
/*   Updated: 2020/03/11 09:40:59 by smadesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

void ls_processer(char **s, t_ls_flags *flags) {
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[++i]) {
        if (s[i][0] == '-' && ft_isprint(s[i][1]))
            continue;
        else {
            path_handler(s[i], flags);
            count++;
        }
    }
    if (!count)
        path_handler(".", flags);
}

/** ft_ls  equvalant to ls command*/
void ft_ls(char **str) {
    t_ls_flags flags;
    int i;

    i = 0;
    init_flags(&flags);
    while (str[++i]) {
        if (str[i][0] == '-' && ft_isprint(str[i][1])) {
            if (!validate_flags(str[i], &flags))
                exit(EXIT_FAILURE);
        }
    }
    ls_processer(str, &flags);
}

int main(int argc, char **argv){    
    // int i = 0;
    (void)argc;
    t_ls_flags *data;
    if (!(data = (t_ls_flags *)malloc(sizeof(t_ls_flags))))
        return 0;
    ft_ls(argv);
    
    return 0;
}