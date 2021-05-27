#include "includes/minirt.h"

int main()
{
	t_params	vars;

	vars.mlx = mlx_init();
	t_vector	*sphere_center = new_vector(3, 2, -32);
	t_sphere	*sphere = new_sphere(sphere_center, 6);
	t_vector	*camera_position = new_vector(0, 0, 0);
	t_vector	*camera_direction = new_vector(0, 0, -1);
	t_camera	*camera = new_camera(camera_position, camera_direction, 50);
	t_scene		*scene = new_scene(camera, sphere);
	scene->width = 800;
	scene->hight = 600;
	vars.window = mlx_new_window(vars.mlx, scene->width, scene->hight, "SPHERE "
															   "TEST");
	raytracing(vars.mlx, vars.window, scene);
	mlx_key_hook(vars.window, esc_exit, &vars);
	mlx_hook(vars.window, 17, 0, ft_exit, &vars);
	//free_scene(scene);
	mlx_loop(vars.mlx);
	return 0;
}
