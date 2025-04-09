#include "cub3d.h"

// int init_game(t_game *game, t_map *map)
// {
//     game->map = map;
//     game->mlx.mlx = mlx_init();
//     if (!game->mlx.mlx)
//         return (1);
//     game->mlx.win_width = 1024;
//     game->mlx.win_height = 768;
//     game->mlx.win = mlx_new_window(game->mlx.mlx, game->mlx.win_width, 
//                                   game->mlx.win_height, "cub3D");
//     if (!game->mlx.win)
//         return (1);
//     game->mlx.img = mlx_new_image(game->mlx.mlx, game->mlx.win_width, 
//                                  game->mlx.win_height);
//     if (!game->mlx.img)
//         return (1);
//     game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bits_per_pixel,
//                                       &game->mlx.line_length, &game->mlx.endian);
//     init_player(game);
//     if (load_textures(game) != 0)
//         return (1);
//     ft_memset(game->keys, 0, sizeof(game->keys));
//     return (0);
// }

// void init_player(t_game *game)
// {
//     int x;
//     int y;
    
//     y = 0;
//     while (y < game->map->height)
//     {
//         x = 0;
//         while (x < game->map->width && game->map->grid[y][x])
//         {
//             if (ft_strchr("NSEW", game->map->grid[y][x]))
//             {
//                 game->player.pos_x = x + 0.5;
//                 game->player.pos_y = y + 0.5;
//                 if (game->map->grid[y][x] == 'N')
//                 {
//                     game->player.dir_x = 0;
//                     game->player.dir_y = -1;
//                     game->player.plane_x = 0.66;
//                     game->player.plane_y = 0;
//                 }
//                 else if (game->map->grid[y][x] == 'S')
//                 {
//                     game->player.dir_x = 0;
//                     game->player.dir_y = 1;
//                     game->player.plane_x = -0.66;
//                     game->player.plane_y = 0;
//                 }
//                 else if (game->map->grid[y][x] == 'E')
//                 {
//                     game->player.dir_x = 1;
//                     game->player.dir_y = 0;
//                     game->player.plane_x = 0;
//                     game->player.plane_y = 0.66;
//                 }
//                 else if (game->map->grid[y][x] == 'W')
//                 {
//                     game->player.dir_x = -1;
//                     game->player.dir_y = 0;
//                     game->player.plane_x = 0;
//                     game->player.plane_y = -0.66;
//                 }
//                 game->player.move_speed = 0.05;
//                 game->player.rot_speed = 0.03;
//                 game->map->grid[y][x] = '0';
//                 return;
//             }
//             x++;
//         }
//         y++;
//     }
// }
// int load_textures(t_game *game)
// {
//     // Load North Texture
//     if (!(game->textures[0].img = mlx_xpm_file_to_image(game->mlx.mlx, game->map->no,
//                                              &game->textures[0].width, &game->textures[0].height)))
//         return (1);
    
//     game->textures[0].addr = mlx_get_data_addr(game->textures[0].img,
//                                         &game->textures[0].bits_per_pixel,
//                                         &game->textures[0].line_length,
//                                         &game->textures[0].endian);
    
//     // Load South Texture
//     if (!(game->textures[1].img = mlx_xpm_file_to_image(game->mlx.mlx, game->map->so,
//                                              &game->textures[1].width, &game->textures[1].height)))
//         return (1);
    
//     game->textures[1].addr = mlx_get_data_addr(game->textures[1].img,
//                                         &game->textures[1].bits_per_pixel,
//                                         &game->textures[1].line_length,
//                                         &game->textures[1].endian);
    
//     // Load East Texture
//     if (!(game->textures[2].img = mlx_xpm_file_to_image(game->mlx.mlx, game->map->ea,
//                                              &game->textures[2].width, &game->textures[2].height)))
//         return (1);
    
//     game->textures[2].addr = mlx_get_data_addr(game->textures[2].img,
//                                         &game->textures[2].bits_per_pixel,
//                                         &game->textures[2].line_length,
//                                         &game->textures[2].endian);
    
//     // Load West Texture
//     if (!(game->textures[3].img = mlx_xpm_file_to_image(game->mlx.mlx, game->map->we,
//                                              &game->textures[3].width, &game->textures[3].height)))
//         return (1);
    
//     game->textures[3].addr = mlx_get_data_addr(game->textures[3].img,
//                                         &game->textures[3].bits_per_pixel,
//                                         &game->textures[3].line_length,
//                                         &game->textures[3].endian);
    
//     return (0);
// }

// int run_game(t_game *game)
// {
//     // Set up hooks
//     mlx_hook(game->mlx.win, 2, 1L << 0, key_press, game);
//     mlx_hook(game->mlx.win, 3, 1L << 1, key_release, game);
//     mlx_hook(game->mlx.win, 17, 0, close_window, game);
    
//     // Set the game loop
//     mlx_loop_hook(game->mlx.mlx, game_loop, game);
    
//     // Start the mlx loop
//     mlx_loop(game->mlx.mlx);
    
//     return (0);
// }

// int key_press(int keycode, t_game *game)
// {
//     if (keycode < 0 || keycode >= 256)
//         return (0);
//     game->keys[keycode] = 1;
//     return (0);
// }

// int key_release(int keycode, t_game *game)
// {
//     if (keycode < 0 || keycode >= 256)
//         return (0);
//     game->keys[keycode] = 0;
//     return (0);
// }

// int close_window(t_game *game)
// {
//     cleanup_game(game);
//     exit(0);
//     return (0);
// }

// int game_loop(t_game *game)
// {
//     // Handle player movement
//     handle_movement(game);
    
//     // Clear screen
//     ft_memset(game->mlx.addr, 0, game->mlx.win_height * game->mlx.line_length);
    
//     // Draw ceiling and floor
//     draw_ceiling_floor(game);
    
//     // Raycasting
//     raycasting(game);
    
//     // Put image to window
//     mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
    
//     return (0);
// }
// void handle_movement(t_game *game)
// {
//     double old_dir_x;
//     double old_plane_x;
    
//     // Move forward
//     if (game->keys[13] || game->keys[119]) // W key
//     {
//         if (game->map->grid[(int)(game->player.pos_y)][(int)(game->player.pos_x + game->player.dir_x * game->player.move_speed)] == '0')
//             game->player.pos_x += game->player.dir_x * game->player.move_speed;
//         if (game->map->grid[(int)(game->player.pos_y + game->player.dir_y * game->player.move_speed)][(int)(game->player.pos_x)] == '0')
//             game->player.pos_y += game->player.dir_y * game->player.move_speed;
//     }
    
//     // Move backward
//     if (game->keys[1] || game->keys[115]) // S key
//     {
//         if (game->map->grid[(int)(game->player.pos_y)][(int)(game->player.pos_x - game->player.dir_x * game->player.move_speed)] == '0')
//             game->player.pos_x -= game->player.dir_x * game->player.move_speed;
//         if (game->map->grid[(int)(game->player.pos_y - game->player.dir_y * game->player.move_speed)][(int)(game->player.pos_x)] == '0')
//             game->player.pos_y -= game->player.dir_y * game->player.move_speed;
//     }
    
//     // Rotate right
//     if (game->keys[2] || game->keys[100]) // D key
//     {
//         old_dir_x = game->player.dir_x;
//         game->player.dir_x = game->player.dir_x * cos(-game->player.rot_speed) - game->player.dir_y * sin(-game->player.rot_speed);
//         game->player.dir_y = old_dir_x * sin(-game->player.rot_speed) + game->player.dir_y * cos(-game->player.rot_speed);
//         old_plane_x = game->player.plane_x;
//         game->player.plane_x = game->player.plane_x * cos(-game->player.rot_speed) - game->player.plane_y * sin(-game->player.rot_speed);
//         game->player.plane_y = old_plane_x * sin(-game->player.rot_speed) + game->player.plane_y * cos(-game->player.rot_speed);
//     }
    
//     // Rotate left
//     if (game->keys[0] || game->keys[97]) // A key
//     {
//         old_dir_x = game->player.dir_x;
//         game->player.dir_x = game->player.dir_x * cos(game->player.rot_speed) - game->player.dir_y * sin(game->player.rot_speed);
//         game->player.dir_y = old_dir_x * sin(game->player.rot_speed) + game->player.dir_y * cos(game->player.rot_speed);
//         old_plane_x = game->player.plane_x;
//         game->player.plane_x = game->player.plane_x * cos(game->player.rot_speed) - game->player.plane_y * sin(game->player.rot_speed);
//         game->player.plane_y = old_plane_x * sin(game->player.rot_speed) + game->player.plane_y * cos(game->player.rot_speed);
//     }
    
//     // Exit game with ESC key
//     if (game->keys[53] || game->keys[65]) // ESC key
//     {
//         cleanup_game(game);
//         exit(0);
//     }
// }

// void draw_ceiling_floor(t_game *game)
// {
//     int x;
//     int y;
//     int color;
    
//     // Draw ceiling
//     color = (game->map->ceiling_color.r << 16) | 
//             (game->map->ceiling_color.g << 8) | 
//             (game->map->ceiling_color.b);
    
//     y = 0;
//     while (y < game->mlx.win_height / 2)
//     {
//         x = 0;
//         while (x < game->mlx.win_width)
//         {
//             my_mlx_pixel_put(&game->mlx, x, y, color);
//             x++;
//         }
//         y++;
//     }
    
//     // Draw floor
//     color = (game->map->floor_color.r << 16) | 
//             (game->map->floor_color.g << 8) | 
//             (game->map->floor_color.b);
    
//     y = game->mlx.win_height / 2;
//     while (y < game->mlx.win_height)
//     {
//         x = 0;
//         while (x < game->mlx.win_width)
//         {
//             my_mlx_pixel_put(&game->mlx, x, y, color);
//             x++;
//         }
//         y++;
//     }
// }

// void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
// {
//     char *dst;
    
//     if (x < 0 || y < 0 || x >= mlx->win_width || y >= mlx->win_height)
//         return;
//     dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

// void raycasting(t_game *game)
// {
//     int x;
//     t_ray ray;
    
//     x = 0;
//     while (x < game->mlx.win_width)
//     {
//         // Calculate ray position and direction
//         ray.camera_x = 2 * x / (double)game->mlx.win_width - 1;
//         ray.ray_dir_x = game->player.dir_x + game->player.plane_x * ray.camera_x;
//         ray.ray_dir_y = game->player.dir_y + game->player.plane_y * ray.camera_x;
        
//         // Which box of the map we're in
//         ray.map_x = (int)game->player.pos_x;
//         ray.map_y = (int)game->player.pos_y;
        
//         // Length of ray from current position to next x or y-side
//         if (ray.ray_dir_x == 0)
//             ray.delta_dist_x = 1e30;
//         else
//             ray.delta_dist_x = fabs(1 / ray.ray_dir_x);
        
//         if (ray.ray_dir_y == 0)
//             ray.delta_dist_y = 1e30;
//         else
//             ray.delta_dist_y = fabs(1 / ray.ray_dir_y);
        
//         // Calculate step and initial sideDist
//         if (ray.ray_dir_x < 0)
//         {
//             ray.step_x = -1;
//             ray.side_dist_x = (game->player.pos_x - ray.map_x) * ray.delta_dist_x;
//         }
//         else
//         {
//             ray.step_x = 1;
//             ray.side_dist_x = (ray.map_x + 1.0 - game->player.pos_x) * ray.delta_dist_x;
//         }
        
//         if (ray.ray_dir_y < 0)
//         {
//             ray.step_y = -1;
//             ray.side_dist_y = (game->player.pos_y - ray.map_y) * ray.delta_dist_y;
//         }
//         else
//         {
//             ray.step_y = 1;
//             ray.side_dist_y = (ray.map_y + 1.0 - game->player.pos_y) * ray.delta_dist_y;
//         }
        
//         // Perform DDA (Digital Differential Analysis)
//         ray.hit = 0;
//         while (ray.hit == 0)
//         {
//             // Jump to next map square
//             if (ray.side_dist_x < ray.side_dist_y)
//             {
//                 ray.side_dist_x += ray.delta_dist_x;
//                 ray.map_x += ray.step_x;
//                 ray.side = 0;
//             }
//             else
//             {
//                 ray.side_dist_y += ray.delta_dist_y;
//                 ray.map_y += ray.step_y;
//                 ray.side = 1;
//             }
            
//             // Check if ray has hit a wall
//             if (ray.map_y < 0 || ray.map_x < 0 || ray.map_y >= game->map->height || ray.map_x >= game->map->width)
//                 break;
//             if (game->map->grid[ray.map_y][ray.map_x] == '1')
//                 ray.hit = 1;
//         }
        
//         // Calculate distance projected on camera direction
//         if (ray.side == 0)
//             ray.perp_wall_dist = (ray.map_x - game->player.pos_x + (1 - ray.step_x) / 2) / ray.ray_dir_x;
//         else
//             ray.perp_wall_dist = (ray.map_y - game->player.pos_y + (1 - ray.step_y) / 2) / ray.ray_dir_y;
        
//         // Calculate height of line to draw on screen
//         ray.line_height = (int)(game->mlx.win_height / ray.perp_wall_dist);
        
//         // Calculate lowest and highest pixel to fill in current stripe
//         ray.draw_start = -ray.line_height / 2 + game->mlx.win_height / 2;
//         if (ray.draw_start < 0)
//             ray.draw_start = 0;
        
//         ray.draw_end = ray.line_height / 2 + game->mlx.win_height / 2;
//         if (ray.draw_end >= game->mlx.win_height)
//             ray.draw_end = game->mlx.win_height - 1;
        
//         // Texturing
//         draw_textured_line(game, &ray, x);
        
//         x++;
//     }
// }

// void draw_textured_line(t_game *game, t_ray *ray, int x)
// {
//     int tex_num;
//     double wall_x;
//     int tex_x;
//     double step;
//     double tex_pos;
//     int y;
//     int tex_y;
//     int color;
    
//     // Choose texture
//     if (ray->side == 0)
//     {
//         if (ray->ray_dir_x > 0)
//             tex_num = 2; // East
//         else
//             tex_num = 3; // West
//     }
//     else
//     {
//         if (ray->ray_dir_y > 0)
//             tex_num = 1; // South
//         else
//             tex_num = 0; // North
//     }
    
//     // Calculate value of wall_x
//     if (ray->side == 0)
//         wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
//     else
//         wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
//     wall_x -= floor(wall_x);
    
//     // Calculate tex_x
//     tex_x = (int)(wall_x * (double)game->textures[tex_num].width);
//     if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1 && ray->ray_dir_y < 0))
//         tex_x = game->textures[tex_num].width - tex_x - 1;
    
//     // Calculate how much to increase the texture coordinate per screen pixel
//     step = 1.0 * game->textures[tex_num].height / ray->line_height;
    
//     // Starting texture coordinate
//     tex_pos = (ray->draw_start - game->mlx.win_height / 2 + ray->line_height / 2) * step;
    
//     // Draw the pixels of the stripe
//     y = ray->draw_start;
//     while (y < ray->draw_end)
//     {
//         tex_y = (int)tex_pos & (game->textures[tex_num].height - 1);
//         tex_pos += step;
        
//         // Get pixel color from texture
//         color = *(unsigned int*)(game->textures[tex_num].addr + 
//                              (tex_y * game->textures[tex_num].line_length + 
//                               tex_x * (game->textures[tex_num].bits_per_pixel / 8)));
        
//         // Make color darker for y-sides
//         if (ray->side == 1)
//             color = (color >> 1) & 8355711;
        
//         my_mlx_pixel_put(&game->mlx, x, y, color);
//         y++;
//     }
// }