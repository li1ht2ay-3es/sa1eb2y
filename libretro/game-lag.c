int retro_game_lag;


static int input_count;

static bool write_oam;
static bool write_vram;

static int video_count;
static int video_oam_count;
static int video_vram_count;

static int game_frame;



void retro_game_lag_frame(GB_gameboy_t *gb)
{
	static char tmp[512];


	if (retro_game_lag == 0)
		return;


	if (write_oam || write_vram) {
		video_count++;
	}

	if (write_oam) {
		video_oam_count++;

		write_oam = false;
	}

	if (write_vram) {
		video_vram_count++;

		write_vram = false;
	}

	if (GB_get_joyp_accessed(gb)) {
		input_count++;
	}
	GB_clear_joyp_accessed(gb);


	game_frame++;
	if (game_frame < retro_game_lag)
		return;


	sprintf(tmp, "lag: %di -- %dv <%do %dw>  [%df]",
		input_count,
		video_count, video_oam_count, video_vram_count,
		game_frame);


	//printf("%s\n", tmp);
	retro_osd_message_add(tmp);


	retro_game_lag_reset();
}



void retro_game_lag_reset()
{
	input_count = 0;

	video_count = 0;
	video_oam_count = 0;
	video_vram_count = 0;

	write_oam = false;
	write_vram = false;

	game_frame = 0;
}



void retro_game_lag_video_oam()
{
	write_oam = true;
}



void retro_game_lag_video_vram()
{
	write_vram = true;
}
