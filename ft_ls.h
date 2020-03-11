/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 09:00:03 by smadesi           #+#    #+#             */
/*   Updated: 2020/03/11 09:00:07 by smadesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include <dirent.h>
#include <errno.h>
#include <grp.h>
#include <limits.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_ls_flags {
    int PARAM_A;
    int PARAM_R;
    int PARAM_L;
    int PARAM_r;
    int PARAM_T;
} t_ls_flags;

void init_flags(t_ls_flags *flags);
void set_flags(char c, t_ls_flags **fs);
void remove_trailing_slash(char **s);
void path_handler(char *path, t_ls_flags *fs);
void ls_processer(char **s, t_ls_flags *flags);
int check_flags(char *s, t_ls_flags *fs);
void ft_ls(char **str);
void my_err(const char *err_string, int line);
void cprint(char *name, mode_t st_mode);
void display_attribute(char *name);
void displayR_attribute(char *name);
void display_single(char *name);
void displayR_single(char *name);
void display(char **name, int count);
void display_dir(char *path);

#endif