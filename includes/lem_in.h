/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#             */
/*   Updated: 2020/07/18 19:32:39 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

# define Q_SIZE 	100000000
# define MAX_ARR	1000000
# define INF 		2000000000
# define HASH_SIZE 	10
# define MODUL		1999

typedef struct	s_map
{
	char		**rooms;
	int			*rooms_hash;
	char		**rooms_list;
	int			rooms_ind;
	char		*ants_str;
	char		**links;
	int			links_ind;
	char		**links_sp;
	int			links_sp_ind;
	int			q_rooms;
	int			ants;
	int			started;
	int			q_path;
	int			maxflow;
	int			*len_path;
	int			*ants_moving;
	int			*ants_path;
	int			*print_ants_in_path;
	int			*max_ants_in_path;
	int			**paths;
	int			**tab_init;
	int			**tab;
	int			good[2];
	int			new_line;
	int			init_2;
	int			pow2[HASH_SIZE];
	char		color;
}				t_map;

typedef struct	s_bfs
{
	int			queue[Q_SIZE];
	int			front;
	int			len;
	int			used[MAX_ARR];
	int			parent[MAX_ARR];
}				t_bfs;

void			count_ants(t_map *m, char *line);
void			rooms(t_map *m, char *line);
void			links(t_map *m, char *line);
void			links_sp(t_map *m, char *link1, char *link2);

void			add_rooms(t_map *m);
void			create_tab(t_map *m);
int				solution(t_map *m);

int				double_xy(t_map *m);
int				double_links(t_map *m);
int				is_room(t_map *m, char *str);

char			*join_str(char *s1, char *s2, int clean);
void			free_array(char **array, t_map *m, int error);
int				room_index(t_map *m, char *room_name);

void			result(t_map *m);
void			exit_func(t_map *m, int error);

int				line_with_room(t_map *m, char *line);

void			push_back(t_bfs *q, int i);
int				pop_front(t_bfs *q);

void			bfs(t_map *m, t_bfs *b, int v);
void			create_paths(t_map *m);
void			save_path(t_map *m, t_bfs *b, int i);
void			print_paths(t_map *m);
void			print_usage(void);

void			distribute_ants(t_map *m);
int				hash(t_map *m, char *s);
void			set_pow2(t_map *m);
int				*ft_arrintnew(size_t size);
int				*ft_memset_int(int *b, int c, size_t len);

void			add_rooms2(t_map *m);
int				double_xy2(t_map *m, char *rooms_i, char *rooms_j);
int				double_links2(t_map *m, char *links_i, char *links_j);
int				line_with_room2(t_map *m, char *line, char *str);

#endif
