#ifndef MINIRT_H
#define MINIRT_H

#include <algorithm>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

//Struct Couleurs
typedef struct	s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

//struct vecteur 3d
typedef struct	s_vec3d
{
	double	x;
	double	y;
	double	z;
}				t_vec3d;

//struct rt
typedef struct	s_ray
{
	t_vec3d	start;
	t_vec3d	dir;
}				t_ray;

//struct camera
typedef struct	s_cam
{
	t_vec3d	pos;
	t_vec3d	orientation;
	t_vec3d	right;
	t_vec3d	up;
	t_vec3d	forward;
}				t_cam;

//Struct lumiere globale de la scene
typedef struct	s_ambient
{
	double	rate;
	t_rgb	color;
}				t_ambient;

//Struct lumiere ajoute
typedef struct	s_light
{
	t_vec3d	pos;
	t_rgb	color;
	double	rate;
	s_light	*next;
}				t_light;

// Struct Objets

typedef enum	e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}				t_obj_type;

typedef struct	s_sphere
{
	t_vec3d	center;
	double	diameter;
	double	radius;
}				t_sphere;

typedef struct	s_plane
{
	t_vec3d	point;
	t_vec3d	normal;
}				t_plane;

typedef struct	s_cylinder
{
	t_vec3d	center;
	t_vec3d	axis;
	double	diameter;
	double	radius;
	double	height;
}				t_cylinder;

typedef struct	s_obj
{
	t_obj_type		type;
	void			*data;
	t_rgb			colors;
	struct s_obj	*next;
}				t_obj;

typedef struct	s_reflect
{
	int		flag;
	double	dist;
	t_vec3d	point;
	t_vec3d	nrml;
	t_obj	*obj;
}				t_reflect;

typedef struct	s_scene
{
	t_ambient	ambient;
	t_light		*light;
	t_cam		cam;
	t_obj		*obj;
}				t_scene;

//MLX

typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;

//struct globale
typedef struct	s_minirt
{
	t_scene	scene;
	t_mlx	mlx;
	int		width;
	int		height;
}				t_minirt;

#endif
