# Cub3D random maze generator

## Important informations

- This generator was initialy made for my Wolf3D project, some features are now useless for the new Cub3D project.
- Therefore, this generator only builds rectangle closen maps.
- I currently don't plan to improve this program, but feel free to do a pull request if you have some interesting ideas.
- This project is old (made in 2019, when I started to learn C).
- I don't take any responsibility for any damage or loss while using this generator.

## Usage

### Compilation

```
make
```

### Usage

- Using the `libmapgen.a` library, create a t_gen variable :

```
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
```

Manually define the wanted parameters and allocate your map, then call the following function :

```
void	build_map(t_gen *map)
```

Which will fill your map.

- Using the `generator` executable :

```
./generator
```

Will generate a sample 11x11 valid maze.

```
./generator -h
```

Will display a basic usage.

```
./generator -e0240
```

The -e0240 flag here will generate a sample 11x11 valid maze with a reasonable amout of sprites.
Use -e02(frequency) for Cub3D, (frequency : 10 : low amount of sprites, 40 : moderate amount of sprites, 100 : high amount of sprites)

- Few interesting parameters combinaisons 

```
./generator -e0240 -x25 -y80
```

Big rectangular map with a moderate amount of sprites. 

```
./generator -e02100 -x40 -y40 -n20 -m20
```

Medium squared map with a high amount of sprites.

```
./generator -e0210 -x3000 -y3000 -n1200 -m2400
```

Huge 3000x3000 squared map with a low amount of sprites to test your program's robustness and performances.