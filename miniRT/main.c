#include "includes/minirt.h"

int main()
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	t_vector	*sphere_center = new_vector(3, 2, -32);
	t_sphere	*sphere = new_sphere(sphere_center, 6);
	t_vector	*camera_position = new_vector(0, 0, 0);
	t_vector	*camera_direction = new_vector(0, 0, -1);
	t_camera	*camera = new_camera(camera_position, camera_direction, 70);
	t_scene		*scene = new_scene(camera, sphere);
	scene->width = 800;
	scene->hight = 600;
	window = mlx_new_window(mlx, scene->width, scene->hight, "SPHERE TEST");
	raytracing(mlx, window, scene);
	//free_scene(scene);
	mlx_loop(mlx);
	return 0;
}
