#include "cub3d.h"

void	raycasting(t_game *game, t_ray *ray)
{
	int		x;
	double	cam_x;

	draw_ceiling_floor(game);
	game->player.plane_x = -game->player.dir_y * 0.6;
	game->player.plane_y = game->player.dir_x * 0.6;
	x = -1;
	while (++x < WIDTH)
	{
		cam_x = 2 * x / (double)WIDTH - 1;
		ray->ray_dir_x = game->player.dir_x + game->player.plane_x * cam_x;
		ray->ray_dir_y = game->player.dir_y + game->player.plane_y * cam_x;
		ray->map_x = (int)game->player.pos_x;
		ray->map_y = (int)game->player.pos_y;
		ray->side_dist_x = 0;
		ray->side_dist_y = 0;
		find_direction(game, ray);
		dda(game, ray);
		if (ray->side == 0)
			ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
		else
			ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
		low_high_pixel(ray);
		draw_line(game, ray, x);
	}
}

void	find_direction(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = INT_MAX;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = INT_MAX;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	dda(t_game *game, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map->grid[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	low_high_pixel(t_ray *ray)
{
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}
