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

#include "ft_ls.h"

void init_flags(t_ls_flags *flags) {
    flags->PARAM_A = 0;
    flags->PARAM_R = 0;
    flags->PARAM_L = 0;
    flags->PARAM_r = 0;
    flags->PARAM_T = 0;
}

void set_flags(char c, t_ls_flags **fs) {
    if (c == 'a')
        (*fs)->PARAM_A = 1;
    else if (c == 'R')
        (*fs)->PARAM_R = 1;
    else if (c == 't')
        (*fs)->PARAM_T = 1;
    else if (c == 'r')
        (*fs)->PARAM_r = 1;
    else if (c == 'l')
        (*fs)->PARAM_L = 1;
}

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

void path_handler(char *path, t_ls_flags *fs) {
    DIR *p_dir;
    struct dirent *ped;
    char *new_dir;

    remove_trailing_slash(&path);
    // new_dir = path;
    p_dir = opendir(path);
    if (!p_dir) {
        perror("Could not open");
        exit(EXIT_FAILURE);
    }
    while ((ped = readdir(p_dir))) {
        if ((!strcmp(ped->d_name, ".") || !strcmp(ped->d_name, "..")))
            continue;
        else if (!ft_strncmp(ped->d_name, ".", 1) && fs->PARAM_A)
            continue;
        ft_putstr(ped->d_name);
        ft_putchar('\t');
    }
    ft_putchar('\n');

    if (fs->PARAM_R) {
        closedir(p_dir);
        p_dir = opendir(path);
        while ((ped = readdir(p_dir))) {
            if (!strcmp(ped->d_name, ".") || !strcmp(ped->d_name, ".."))
                continue;
            else if (!ft_strncmp(ped->d_name, ".", 1) && !fs->PARAM_A)
                continue;
            else {
                if (ped->d_type == 4) {
                    new_dir = ft_strjoin(path, "/");
                    new_dir = ft_strjoin(new_dir, ped->d_name);
                    printf("\n+++> %s\n", new_dir);
                    path_handler(new_dir, fs);
                    free(new_dir);
                }
            }
        }
    }
}
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

int check_flags(char *s, t_ls_flags *fs) {
    int i;
    size_t j;
    char *s2;
    int count;

    i = 0;
    j = -1;
    count = 0;
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

void ft_ls(char **str) {
    t_ls_flags flags;
    int i;

    i = 0;
    init_flags(&flags);
    while (str[++i]) {
        if (str[i][0] == '-' && ft_isprint(str[i][1])) {
            if (!check_flags(str[i], &flags))
                exit(EXIT_FAILURE);
        }
    }
    ls_processer(str, &flags);
}