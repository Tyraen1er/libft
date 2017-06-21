/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savebitmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:53:25 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/20 17:49:39 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"

typedef struct					s_header_file_bmp
{
	short						bf_type;
	int							bf_size;
	int							reserved;
	int							bf_offset;
}	__attribute((packed))		t_header_file_bmp;

typedef struct					s_info_bmp
{
	int							info_size;
	int							width;
	int							height;
	short						nb_planes;
	short						bits_per_pixel;
	int							compression;
	int							pic_size;
	int							h_pixel_per_meter;
	int							v_pixel_per_meter;
	int							nb_color_used;
	int							nb_color_important;
}								t_info_bmp;

typedef struct					s_bmp
{
	t_header_file_bmp			header;
	t_info_bmp					info;
	int							*palette;
	char						*picture;
}								t_bmp;

t_bmp	ft_uncompress_bitmap(t_bmp old)
{
	t_bmp	new;
	int		a;
	int		pos;
	int		offset;
	long	mask;

	a = 0;
	pos = 0;
	offset = 0;
	mask = 0xFFFFFFFFFFFFFFFF;
	new = old;
	new.info.compression = 0;
	new.palette = NULL;
	new.picture = (char*)malloc(old.info.width * old.info.height * 3);
	while (a < old.info.width * old.info.height)
	{
		while (8 <= pos)
		{
			++a;
			pos -= 8;
		}
		pos += old.info.bits_per_pixel;
		*((long*)old.picture) & (mask >> offset);
	}
	return (new);
}

int		ft_load_bitmap(int fd, t_bmp *bmp)
{
	char	buf[40];

	if (read(fd, (char*)&(bmp->header), 14) != 14 ||
					(bmp->header.bf_type !=
			0x4D42 && bmp->header.bf_type != 0x4142 && bmp->header.bf_type !=
			0x4943 && bmp->header.bf_type != 0x5043 && bmp->header.bf_type !=
			0x4349 && bmp->header.bf_type != 0x5450) ||
				read(fd, (char*)&(bmp->info), 40) != 40 ||
			bmp->info.info_size != 40 || bmp->info.nb_planes != 1)
		return (-1);
	if (bmp->info.compression)
	{
		bmp->palette = (int*)malloc(sizeof(int) * bmp->info.nb_color_used);
		if (-1 == read(fd ,(char*)bmp->palette, bmp->info.nb_color_used * 4) ||
				-1 == ft_read_all(fd, (void*)&bmp->picture))
			return (-1);
		return (1);
	}
	bmp->palette = NULL;
	if (-1 == ft_read_all(fd, (void*)&bmp->picture))
		return (-1);
	return (0);
}

int		ft_display(t_bmp pic)
{
	void	*mlx[4];
	int		bpp;
	int		s_l;
	int		endian;
	int		a;
	int		b;

	a = 0;
	b = 0;
	bpp = 0;
	s_l = 0;
	endian = 0;
	if (!(mlx[0] = mlx_init()) ||
		!(mlx[1] = mlx_new_window(mlx[0], pic.info.width, pic.info.height, "fractal 42")) ||
		!(mlx[2] = mlx_new_image(mlx[0], pic.info.width, pic.info.height)) ||
		!(mlx[3] =
			(void*)mlx_get_data_addr(mlx[2], &(bpp), &(s_l), &(endian))))
		exit(3);
	while(b < pic.info.pic_size)
	{
		if ((a + 1) % 4)
		{
			((char*)mlx[3])[a] = pic.picture[b];
			++b;
		}
		else
			((char*)mlx[3])[a] = 0;
		++a;
	}
	mlx_put_image_to_window(mlx[0], mlx[1], mlx[2], 0, 0);
	mlx_loop(mlx[0]);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_bmp	picture;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if (-1 == ft_load_bitmap(fd, &picture))
	{
		ft_putstr("aie aie aie\n");
		return (0);
	}
		printf("____________HEADER D INFORMATIONS____________\nnombre de bits par pixel = %d\ntaille de compression = %d\n", picture.info.bits_per_pixel, picture.info.compression);
	printf("nombre de couleurs importantes = %d\n", picture.info.nb_color_important);
	if (picture.info.bits_per_pixel < 24)
	{
		printf("CETTE IMAGE EST COMPRESSEE !\n");
		picture = ft_uncompress_bitmap(picture);
		ft_display(picture);
		return (0);
	}
	ft_display(picture);
	return (0);
}
