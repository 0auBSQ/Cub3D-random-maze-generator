#include "generator.h"

static inline void	free_map(t_gen *map)
{
	for (int i = 0; i < map->x; i++)
		free(map->map[i]);
	free(map->map);
}

static inline void	allocate_map(t_gen *map)
{
	if (!(map->map = (char**)malloc(sizeof(char*) * map->x)))
		exit(printf("broken malloc\n"));
	for (int i = 0; i < map->x; i++)
		if (!(map->map[i] = (char*)malloc(sizeof(char) * map->y + 1)))
			exit(printf("broken malloc\n"));
}

static inline void	init_map(t_gen *map, size_t s)
{
	bzero(map, s);
	map->x = 11;
	map->y = 11;
	map->px = 1;
	map->py = 1;
	map->fd = 1;
	map->wall = '1';
	map->blank = '0';
	map->player = 'N';
}

static inline void	printm(t_gen *map)
{
	dprintf(map->fd, "R 1200 780\nNO ./tex/north.xpm\nSO ./tex/south.xpm\nWE ./tex/west.xpm\nEA ./tex/east.xpm\nS ./tex/sprite.xpm\nF 220,100,0\nC 225,30,0\n");
	for (int j = 0; j < map->x; j++)
		dprintf(map->fd, "%s\n", map->map[j]);
}

static inline void	wolf_head(t_gen *map)
{
	dprintf(map->fd, "validmap\n%d\n%d\n", map->x, map->y);
}

int	main(int argc, char **argv)
{
	t_gen	map;

	init_map(&map, sizeof(map));
	process_args(&map, argc, argv);
	if (map.x < 4 || map.y < 4)
		return (printf("Minimum size : 4x4\n"));
	if (map.px < 1 || map.py < 1 || map.px > map.x - 2 || map.py > map.y - 2)
		return (printf("Player is out of bounds\n"));
	if (map.wall == map.blank)
		return (printf("Wall and blank can't be the same char\n"));
	allocate_map(&map);
	if (WOLF_3D == 1)
		wolf_head(&map);
	build_map(&map);
	printm(&map);
	free_map(&map);
	return (0);
}