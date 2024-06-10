#include "./mlx/mlx.h"
#include "./libft/libft.h"
#include <stdio.h>

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
    void *img;
    void *img2;
    void *img3;
    void *img4;
    void *img5;
    int img_width;
    int img_height;

	printf("%d\n", ft_atoi("344565D"));
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
    if (!win_ptr)
        return (0);
    img = mlx_xpm_file_to_image(mlx_ptr, "./textures/link.xpm", &img_width, &img_height);
    img2 = mlx_xpm_file_to_image(mlx_ptr, "./textures/hiral.xpm", &img_width, &img_height);
    img3 = mlx_xpm_file_to_image(mlx_ptr, "./textures/rupy.xpm", &img_width, &img_height);
    img4 = mlx_xpm_file_to_image(mlx_ptr, "./textures/tile.xpm", &img_width, &img_height);
    img5 = mlx_xpm_file_to_image(mlx_ptr, "./textures/wall.xpm", &img_width, &img_height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img2, 0, 64);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img3, 64, 0);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img4, 64, 64);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img5, 128, 0);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img5, 128, 64);
	mlx_loop(mlx_ptr);
    return (0);
}