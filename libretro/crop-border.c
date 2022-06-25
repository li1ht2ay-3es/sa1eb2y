int retro_crop_border = 0;
int retro_crop_border_width = 0;
int retro_crop_border_height = 0;


int get_border_width(GB_gameboy_t *gb)
{
	int width = GB_get_screen_width(gb);

	if (retro_crop_border && width == 256) {
		width -= retro_crop_border_width;
	}

	return width;
}


int get_border_height(GB_gameboy_t *gb)
{
	int height = GB_get_screen_height(gb);

	if (retro_crop_border && height == 224) {
		height -= retro_crop_border_height;
	}

	return height;
}


int get_border_ptr(GB_gameboy_t *gb)
{
	int width = GB_get_screen_width(gb);
	int ptr = 0;

	if (retro_crop_border && width == 256) {
		ptr = (retro_crop_border_width / 2) + ((retro_crop_border_height / 2) * width);
	}

	return ptr;
}
