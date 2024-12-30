/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_init_fdf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:17:05 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/30 12:38:23 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void free_fdf(t_fdf *fdf)
{
    if (fdf == NULL)
        return;

    if (fdf->map)
        free(fdf->map);
    if (fdf->img)
        mlx_delete_image(fdf->mlx, fdf->img);
    if (fdf->mlx)
        mlx_close_window(fdf->mlx);
    if (fdf->camera)
        free(fdf->camera);

    free(fdf);
}

int main(int argc, char **argv)
{
    t_fdf *fdf;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    fdf = init_fdf(argv[1]);
    if (fdf == NULL)
    {
        fprintf(stderr, "Error initializing FdF.\n");
        return (EXIT_FAILURE);
    }

    printf("FdF initialized successfully!\n");
    printf("Window dimensions: %dx%d\n", WINDOW_WIDTH, WINDOW_HEIGHT);
    printf("Map: %p\n", (void *)fdf->map);
    printf("Image: %p\n", (void *)fdf->img);
    printf("Camera: %p\n", (void *)fdf->camera);

    mlx_loop(fdf->mlx);

    free_fdf(fdf);

    return (EXIT_SUCCESS);
}
