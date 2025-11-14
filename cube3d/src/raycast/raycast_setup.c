/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:00:00 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/07 11:39:48 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	build_camera_from_player(const t_player *player, t_camera *cam)
{
	double	fov;
	double	plane_scale;

	fov = PI / 3.0;
	cam->dirx = cos(player->angle);
	cam->diry = sin(player->angle);
	plane_scale = tan(fov / 2.0);
	cam->planex = -cam->diry * plane_scale;
	cam->planey = cam->dirx * plane_scale;
}

void	set_ray_dir(int x, const t_camera *cam, t_ray *ray)
{
	const double	camera_x = 2.0 * x / (double)WIDTH - 1.0;

	ray->rdx = cam->dirx + cam->planex * camera_x;
	ray->rdy = cam->diry + cam->planey * camera_x;
}

static void	set_ray_deltas(t_ray *ray)
{
	if (ray->rdx == 0.0)
		ray->ddx = 1e30;
	else
		ray->ddx = fabs(1.0 / ray->rdx);
	if (ray->rdy == 0.0)
		ray->ddy = 1e30;
	else
		ray->ddy = fabs(1.0 / ray->rdy);
}

static void	set_ray_sides(double posx, double posy, t_ray *ray)
{
	if (ray->rdx < 0)
		ray->stepx = -1;
	else
		ray->stepx = 1;
	if (ray->rdy < 0)
		ray->stepy = -1;
	else
		ray->stepy = 1;
	if (ray->rdx < 0)
		ray->sdx = (posx - ray->mapx) * ray->ddx;
	else
		ray->sdx = (ray->mapx + 1.0 - posx) * ray->ddx;
	if (ray->rdy < 0)
		ray->sdy = (posy - ray->mapy) * ray->ddy;
	else
		ray->sdy = (ray->mapy + 1.0 - posy) * ray->ddy;
}

void	set_ray_steps(double posx, double posy, t_ray *ray)
{
	ray->mapx = (int)posx;
	ray->mapy = (int)posy;
	set_ray_deltas(ray);
	set_ray_sides(posx, posy, ray);
}
