#include "header.h"

void draw_heart(t_point center, int size)
{
  void *mlx;
  void *win;
  mlx = mlx_init();
  win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Heart");

  mlx_string_put(mlx, win, 100, 100, 0xFFFFFF, "Drawing Heart...");

  int i;
  int n = 500;
  float x, y;
  for (i = 0; i < n; i++) 
  {
    x = (float)(2 * i - n) / (float)n * size;
    y = (sqrt(cos(x)) * cos(200 * x) + sin(fabs(x)) - 0.7) * (4 - x*x) / sqrt(fabs(9 - x*x)) * size;
    mlx_pixel_put(mlx, win, center.x + x, center.y + y, 0xFFFFFF);
  }

  mlx_loop(mlx);
}

int main()
{
  t_point center = { WIN_WIDTH / 2, WIN_HEIGHT / 2 };
  int size = 150;
  draw_heart(center, size);
  return 0;
}
