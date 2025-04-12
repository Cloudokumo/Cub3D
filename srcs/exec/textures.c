#include "cub3d.h"

void	draw_ceiling_floor(t_game *game)
{
	int	x;
	int	y;
	int	color;

	color = (game->map->ceiling_color.r << 16)
		| (game->map->ceiling_color.g << 8) | (game->map->ceiling_color.b);
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
			my_mlx_pixel_put(&game->mlx, x++, y, color);
		y++;
	}
	color = (game->map->floor_color.r << 16)
		| (game->map->floor_color.g << 8) | (game->map->floor_color.b);
	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			my_mlx_pixel_put(&game->mlx, x++, y, color);
		y++;
	}
}

static int	get_texture_number(t_ray *ray, t_game *game)
{
	(void)game;
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (1);
		else
			return (0);
	}
}

static void	get_wall_x(t_game *game, t_draw *draw, t_ray *ray)
{
	if (ray->side == 0)
		draw->wall_x = game->player.pos_y + ray->perp_wall_dist
			* ray->ray_dir_y;
	else
		draw->wall_x = game->player.pos_x + ray->perp_wall_dist
			* ray->ray_dir_x;
	draw->wall_x -= floor(draw->wall_x);
	draw->tex_x = (int)(draw->wall_x * game->textures[draw->tex_index].width);
	if (draw->tex_x < 0)
		draw->tex_x = 0;
	if (draw->tex_x > game->textures[draw->tex_index].width)
		draw->tex_x = game->textures[draw->tex_index].width - 1;
	if (ray->side == 0 && ray->ray_dir_x > 0)
		draw->tex_x = game->textures[draw->tex_index].width - draw->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		draw->tex_x = game->textures[draw->tex_index].width - draw->tex_x - 1;
	draw->tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2)
		* draw->step;
}

static void	draw_pixels(t_game *game, t_draw *draw, t_ray *ray, int x)
{
	while (draw->y < ray->draw_end)
	{
		draw->tex_y = (int)draw->tex_pos
			& (game->textures[draw->tex_index].height - 1);
		draw->tex_pos += draw->step;
		draw->offset = (draw->tex_y
				* game->textures[draw->tex_index].line_length + draw->tex_x
				* (game->textures[draw->tex_index].bits_per_pixel / 8));
		draw->color = *(unsigned int *)(game->textures[draw->tex_index].addr
				+ draw->offset);
		if (ray->side == 1)
			draw->color = (draw->color >> 1) & 8355711;
		if (draw->y >= 0 && draw->y < HEIGHT && x >= 0 && x < WIDTH)
			*(unsigned int *)(game->mlx.addr + (draw->y * game->mlx.line_length
						+ x * game->mlx.bits_per_pixel / 8)) = draw->color;
		draw->y++;
	}
}

void	draw_line(t_game *game, t_ray *ray, int x)
{
	t_draw	draw;

	draw.tex_x = 0;
	draw.tex_index = get_texture_number(ray, game);
	draw.step = 1.0 * game->textures[draw.tex_index].height / ray->line_height;
	get_wall_x(game, &draw, ray);
	draw.y = ray->draw_start;
	draw_pixels(game, &draw, ray, x);
}

// open_texture_file(game, draw.tex_index);