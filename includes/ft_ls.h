/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadesi <smadesi@42.fr>                     +#+  +:+       +#+        */
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
#include "../libft/includes/libft.h"

typedef struct s_ls_flags
{
    int f_a;
    int f_R;
    int f_l;
    int f_r;
    int f_t;
} t_ls_flags;

void init_flags(t_ls_flags *flags);
void set_flags(char c, t_ls_flags **fs);
void remove_trailing_slash(char **s);
void path_handler(char *path, t_ls_flags *fs);
void ls_processer(char **s, t_ls_flags *flags);
int check_flags(char *s, t_ls_flags *fs);
int validate_flags(char *s, t_ls_flags *fs);
void ft_ls(char **str);
void dash_R(DIR *p_dir, t_ls_flags *fs, char *path);
void dash_a(DIR *p_dir, char *path, t_ls_flags *fs);
void dash_t(DIR *p_dir, char *path);
void dash_l(DIR *p_dir, t_ls_flags *fs, char *path);

#endif