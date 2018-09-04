/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_str.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:20:54 by eferrand          #+#    #+#             */
/*   Updated: 2018/03/19 15:46:47 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STR
# define T_STR
# include "libft.h"

typedef struct					s_this
{
	int							id;
	struct s_this				*next;
	struct s_str				*_this;
}								t_this;

t_this	*allClasses;

typedef struct					s_str
{
	char						*str;
	struct s_str				*addr;
	int							(*strlen)();
	void						(*lower)();
	void						(*upper)();
	char						(*stradd)(char *);
	char						(*addstr)(char *);
	void						(*print)();
}								t_str;

t_str							init_str(t_str *neo);
void							delete_str(t_str *old);
void							str_lower();
void							str_upper();
void							str_add(char *add);
void							add_str(char *add);
void							str_print();

/*
** replace carac / pattern
** split
** compter occurence carac / chaine
** suppr carac
*/
#endif
