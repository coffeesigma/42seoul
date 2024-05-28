#include "./mlx/mlx.h"
#include "./libft/libft.h"
#include <stdio.h>

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	printf("%d\n", ft_atoi("344565D"));
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
}