#ifndef GENERATOR_H
# define GENERATOR_H

# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define WALL_FREQUENCY 4
# define ROOM_FREQUENCY 2
# define WOLF_3D 0
# define ENTITY_NB 10

typedef struct		s_entity
{
	char			c;
	int				p;
}					t_entity;

typedef struct		s_gen
{
	char			**map;
	int				x;
	int				y;
	char			wall;
	char			blank;
	char			player;
	int				px;
	int				py;
	int				fd;
	t_entity		e[ENTITY_NB];
}					t_gen;

void	build_map(t_gen *map);
void	process_args(t_gen *map, int ac, char **av);

#endif