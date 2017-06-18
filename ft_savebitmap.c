/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savebitmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:53:25 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/18 23:28:28 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

typedef struct			s_header_file_bmp
{
	short				bf_type;
	int					bf_size;
	int					reserved;
	int					bf_offset;
}						t_header_file_bmp;

typedef struct			s_info_bmp
{
	int					info_size;
	int					width;
	int					height;
	short				nb_planes;
	short				bits_per_pixel;
	int					compression;
	int					pic_size;
	int					h_pixel_per_meter;
	int					v_pixel_per_meter;
	int					nb_color_used;
	int					nb_color_important;
}						t_info_bmp;

typedef struct			s_bmp
{
	t_header_file_bmp	header;
	t_info_bmp			info;
	int					*palette;
	char				*picture;
}						t_bmp;

int		ft_load_bitmap(int fd, t_bmp *bmp)
{
	int	a;

	printf("bmo = %lu\nheader = %lu\ninfo = %lu\n", sizeof(*bmp), sizeof(bmp->header), sizeof(bmp->info));
/*	if (!((file[0] == 'B' && file[1] == 'M') ||
				(file[0] == 'B' && file[1] == 'A') ||
				(file[0] == 'C' && file[1] == 'I') ||
				(file[0] == 'C' && file[1] == 'P') ||
				(file[0] == 'I' && file[1] == 'C') ||
				(file[0] == 'P' && file[1] == 'T')))
		return (-1);
	bmp->header.bf_type = *((short*)file);
	bmp->header.bf_size = *((int*)&(file + 2));
	bmp->header.bf_offset = *((int*)&(file + 10));
	bmp->info.info_size = *((int*)&(file + 14));
	bmp->info.width = *((int*)&(file + 18));
	bmp->info.height = *((int*)&(file + 22));
	bmp->header.nb_planes = *((short*)&(file + 26));
	bmp->header.bits_per_pixel = *((short*)&(file + 28));
*/	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_bmp	picture;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("impossible d open\n");
		return (0);
	}
	ft_load_bitmap(fd, &picture);
	return (0);
}
