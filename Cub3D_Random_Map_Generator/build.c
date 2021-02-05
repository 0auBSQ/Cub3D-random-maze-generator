#include "generator.h"

static inline void	init_map(t_gen *map)
{
	for (int i = 0; i < map->y; i++)
		for (int j = 0; j < map->x; j++)
			map->map[j][i] = map->blank;
}

static inline void	compute_borders(t_gen *map)
{
	for (int i = 0; i < map->y; i++)
	{
		map->map[0][i] = map->wall;
		map->map[map->x - 1][i] = map->wall;
	}
	for (int j = 0; j < map->x; j++)
	{
		map->map[j][0] = map->wall;
		map->map[j][map->y - 1] = map->wall;
	}
}

static inline void	seed_walls(t_gen *map, int i, int j)
{
	if (!((int)rand() % WALL_FREQUENCY))
		map->map[j - 1][i] = map->wall;
	if (!((int)rand() % WALL_FREQUENCY))
		map->map[j + 1][i] = map->wall;
	if (!((int)rand() % WALL_FREQUENCY))
		map->map[j][i - 1] = map->wall;
	if (!((int)rand() % WALL_FREQUENCY))
		map->map[j][i + 1] = map->wall;
}

static inline void	compute_pillars(t_gen *map)
{
	for (int i = 1; i < map->y - 1; i++)
		for (int j = 1; j < map->x - 1; j++)
			if (i % 2 == 0 && j % 2 == 0)
			{
				map->map[j][i] = map->wall;
				seed_walls(map, i, j);
			}
}

static inline void	uncarve(t_gen *map, int i, int j)
{
	int		tmp;

	while (map->map[j - 1][i] == map->wall && map->map[j + 1][i] == map->wall 
		&& map->map[j][i - 1] == map->wall && map->map[j][i + 1] == map->wall)
		{
			tmp = (int)rand() % 4;
			if (tmp == 0 && j - 1 > 0)
				map->map[j - 1][i] = map->blank;
			else if (tmp == 1 && j + 1 < map->x - 1)
				map->map[j + 1][i] = map->blank;
			else if (tmp == 2 && i - 1 > 0)
				map->map[j][i - 1] = map->blank;
			else if (i + 1 < map->y - 1)
				map->map[j][i + 1] = map->blank;
		}
}

static inline void	unlock_map(t_gen *map)
{
	for (int i = 1; i < map->y - 1; i++)
		for (int j = 1; j < map->x - 1; j++)
			if (map->map[j][i] == map->blank)
				uncarve(map, i, j);
}

static inline void	carve_rooms(t_gen *map)
{
	for (int i = 1; i < map->y - 1; i++)
		for (int j = 1; j < map->x - 1; j++)
			if ((int)rand() % 10 < ROOM_FREQUENCY)
				map->map[j][i] = map->blank;
}

static inline void	place_player(t_gen *map)
{
	map->map[map->px][map->py] = map->player;
}

static inline int	score_get(t_gen *map, int i, int j)
{
	int		s;

	s = (int)rand() % 100;
	if (map->map[j][i] == map->wall)
		s += ((int)rand() % 800) + 1;
	if (map->map[j - 1][i] == map->wall || map->map[j + 1][i] == map->wall 
		|| map->map[j][i - 1] == map->wall || map->map[j][i + 1] == map->wall)
		s += ((int)rand() % 250) + 1;
	return (s);
}

static inline void	rng_entity(t_gen *map, t_entity *z)
{
	for (int i = 1; i < map->y - 1; i++)
		for (int j = 1; j < map->x - 1; j++)
			if (z->p > score_get(map, i, j))
				map->map[j][i] = z->c;
}

static inline void	place_entities(t_gen *map)
{
	for (int i = 0; i < ENTITY_NB; i++)
		if (map->e[i].c != 0)
			rng_entity(map, &map->e[i]);
}

void	build_map(t_gen *map)
{
	srand(time(NULL));
	init_map(map);
	compute_borders(map);
	compute_pillars(map);
	unlock_map(map);
	carve_rooms(map);
	place_entities(map);
	place_player(map);
}