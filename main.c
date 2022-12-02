/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:44:23 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/30 22:59:48 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define WINDOW_HEIGHT 1080
#define WINDOW_WIDTH 1920
#define MAX_ITERATIONS 255

int palette[256];


int	fractal(int keycode, t_frame *frame)
{
    float xscale, yscale, zx, zy, cx, tempx, cy;
    int x, y;
    int count;
	(void)keycode;

    // setting up the xscale and yscale
    xscale = frame->xside / WINDOW_WIDTH;
    yscale = frame->yside / WINDOW_HEIGHT;

	t_data	img;
	img.img = mlx_new_image(frame->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	frame->img = &img;

	frame->left = -0.5 * (WINDOW_WIDTH * 9);
	frame->top = -0.5 * (WINDOW_HEIGHT * 16 );
	frame->xside = 1 * (WINDOW_WIDTH * 9 );
	frame->yside = 1 * (WINDOW_HEIGHT * 16);

    // scanning every point in that rectangular area.
    // Each point represents a Complex number (x + yi).
    // Iterate that complex number
	y = 1;
    while (y <= WINDOW_HEIGHT - 1)
	{
		x = 1;
        while (x <= WINDOW_WIDTH - 1)
        {
            // c_real
            cx = x * xscale + frame->left;
            // c_imaginary
            cy = y * yscale + frame->top;
            // z_real
            zx = 0;
            // z_imaginary
            zy = 0;
            count = 0;
            // Calculate whether c(c_real + c_imaginary) belongs
            // to the Mandelbrot set or not and draw a pixel
            // at coordinates (x, y) accordingly
            // If you reach the Maximum number of iterations
            // and If the distance from the origin is
            // greater than 2 exit the loop
            while ((zx * zx + zy * zy < 4) && (count < MAX_ITERATIONS))
            {
                // Calculate Mandelbrot function
                // z = z*z + c where z is a complex number
  
                // tempx = z_real*_real - z_imaginary*z_imaginary + c_real
                tempx = zx * zx - zy * zy + cx;
                // 2*z_real*z_imaginary + c_imaginary
                zy = 2 * zx * zy + cy;
                // Updating z_real = tempx
                zx = tempx;
                // Increment count
                count++;
            }
            // To display the created fractal
            // put_pixel(frame->img, x, y, (count >= MAX_ITERATIONS)*create_trgb(0,0xff,0xff,0xff));
            put_pixel(frame->img, x, y, palette[count % 255]);
			x++;
        }
		y++;
    }
	// printf("scale = %f", frame->scale);
	write(1, "scale : ", 8);
	char buf[100];
  
    gcvt(frame->scale, 6, buf);
	write(1, buf, strlen(buf));
	write(1, "\n", 1);
	// frame->scale+=frame->frame++;
	return 0;
}

int update(t_frame *data)
{
	fractal(0, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
	return (0);
}

int scale(int keycode, t_frame *frame)
{
	(void)keycode;
	frame->scale+=10;
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	t_frame frame;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fractol");
	frame.mlx = mlx;
	frame.mlx_win = mlx_win;
// start of frame loop


	// palette
	int current_color = 0;
	int red = 24;
	int green = 16;
	int blue = 0;
	while (current_color < 256)
	{
		palette[current_color] = create_trgb(0 , red, green, blue);

		if (current_color < 64)
			red += 3;
		else if (current_color < 128)
			green += 3;
		else if (current_color < 192)
			blue += 3;
		current_color++;
	}

// render loop
	
	
	// mlx_put_image_to_window(frame.mlx, frame.mlx_win, frame.img->img, 0, 0);


	// fractal(0, &frame);
	frame.frame = 0;
	frame.scale = 200;
	mlx_loop_hook(mlx, &update, &frame);
	mlx_key_hook(frame.mlx_win, &scale, &frame);


	// mlx_loop_hook(frame.mlx, &handle_no_event, &frame);
	// mlx_key_hook(frame.mlx_win, &handle_input, &frame);


// end of render loop
//end of frame loop
	mlx_loop(mlx);

	/* we will exit the loop if there's no window left, and execute this code */
	// mlx_destroy_display(frame.mlx);
	free(frame.mlx);
}
