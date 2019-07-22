/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadesi <smadesi@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:55:02 by smadesi           #+#    #+#             */
/*   Updated: 2019/07/22 11:47:32 by smadesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <dirent.h>

typedef struct	s_ls_flags
{
	int			f_a;
	int			f_R;
	int			f_l;
	int			f_r;
	int			f_t;
}				t_ls_flags;

void init_flags(t_ls_flags *flags)
{
	flags->f_a = 0;
	flags->f_R = 0;
	flags->f_l = 0;
	flags->f_r = 0;
	flags->f_t = 0;
}

int		check_flags(char *s, t_ls_flags *fs)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = "aRrtl";
	while (s[++i])
	{

	}

}

void	ft_ls(char **str)
{
	t_ls_flags	flags;
	int		i;

	i = 0;
	init_flags(&flags);
	while (str[++i])
	{
		if (str[i][0] == '-' && ft_isprint(str[i][1])) {
			if(!check_flags(str[i], &flags))
			{
				printf("you suck\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	// DIR				*p_dir;
	// struct dirent	*dep;

	// p_dir = opendir(".");
	// if (!p_dir) {
	// 	perror("Could not open dir");
	// 	exit(EXIT_FAILURE);
	// 	// ft_putstr_fd("")
	// }

	// while ((dep = readdir(p_dir)))
	// {
	// printf("---> %s\n", dep->d_name);

	// }


	// closedir(p_dir);
}


int main(int ac, char *av[])
{
	ft_ls(av);
	// while (1)
	// {
	// 	/* code */
	// }

	// init_flags(&flags);
	return 0;
}
