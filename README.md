DA FARE:

- TOGLIERE I .O DI MINILIBX

# fractol

// main.c
int main(int argc, char **argv);
t_fractal_params parse_args(int argc, char **argv);
void print_usage(void);
int cleanup(t_vars *vars);
void init_params(t_fractal_params *params);

// init.c
int init_mlx(t_vars *vars);
void init_hooks(t_vars *vars);
int create_window(t_vars *vars);
int create_image(t_vars *vars);
void init_complex(t_complex *c, double real, double imag);

// render.c
void render_fractal(t_vars *vars);
void set_pixel(t_vars *vars, int x, int y, int color);
t_complex map_to_complex(t_vars *vars, int x, int y);
int get_color(int iterations);
void put_image_to_window(t_vars *vars);

// fractal_math.c
int mandelbrot(t_complex c);
int julia(t_complex z, t_complex c);
void complex_square(t_complex *z);
void complex_add(t_complex *z, t_complex c);
double complex_abs_sq(t_complex z);

// events.c
int handle_key(int key, t_vars *vars);
int handle_mouse(int button, int x, int y, t_vars *vars);
void zoom(t_vars *vars, double factor, int x, int y);
void move(t_vars *vars, double dx, double dy);
int close_window(t_vars *vars);

// utils.c
double ft_atof(const char *str);
int ft_strcmp(const char *s1, const char *s2);
void ft_putstr_fd(char *s, int fd);
void *ft_memset(void *b, int c, size_t len);