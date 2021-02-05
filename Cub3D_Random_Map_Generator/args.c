#include "generator.h"

static inline void	helper(void)
{
	printf("usage : ./generator [args]\n");
	printf("args :\n");
	printf("-h : Usage/help\n");
	printf("-x[size] : Map x size\n");
	printf("-y[size] : Map y size\n");
	printf("-n[xpos] : Player x initial position\n");
	printf("-m[ypos] : Player y initial position\n");
	printf("-w[char] : Wall char\n");
	printf("-b[char] : Blanc char\n");
	printf("-p[char] : Player char\n");
	printf("-f[path] : Output file (STDOUT if none chosen)\n");
	printf("-e[num][char][rate] : Entity (Num : Between 0 and 9)\n");
	exit(0);
}

static inline void	process_entity(t_gen *map, char *s)
{
	if (strlen(s) < 3)
		return ;
	if (s[0] < '0' || s[0] > '9')
		return ;
	map->e[s[0] - '0'].c = s[1];
	map->e[s[0] - '0'].p = atoi(s + 2);
}

static inline void	parameters(t_gen *map, char *s)
{
	if (!strncmp(s, "-h", 2))
		helper();
	else if (!strncmp(s, "-x", 2))
		map->x = atoi(s + 2);
	else if (!strncmp(s, "-y", 2))
		map->y = atoi(s + 2);
	else if (!strncmp(s, "-w", 2))
		map->wall = s[2];
	else if (!strncmp(s, "-b", 2))
		map->blank = s[2];
	else if (!strncmp(s, "-n", 2))
		map->px = atoi(s + 2);
	else if (!strncmp(s, "-m", 2))
		map->py = atoi(s + 2);
	else if (!strncmp(s, "-p", 2))
		map->player = s[2];
	else if (!strncmp(s, "-f", 2))
		map->fd = open(s + 2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (!strncmp(s, "-e", 2))
		process_entity(map, s + 2);
}

void	process_args(t_gen *map, int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		parameters(map, av[i]);
}