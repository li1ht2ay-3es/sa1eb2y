int retro_video_overclock;
int retro_video_overclock_type;


static int overclock_cycles;



void retro_set_overclock(int type)
{
/*
	1 = pre-vblank  (LY = 144-1, h-blank)
	2 = post-vblank  (LY = 0, start)
	3 = lcd off
*/
	overclock_cycles = 0;

	if (retro_video_overclock_type == 0) return;

	if (
		type == 3 ||
		retro_video_overclock_type == 3 ||
		retro_video_overclock_type == type
	) {
		// emulator always runs in double speed cycles  [114 cpu * 154 lines]
		overclock_cycles = ((long long) (retro_video_overclock - 100) * 114 * 154 * 2) / 100;
	}

	if (retro_video_overclock_type == 3) {
		// split pre-vblank and post-vblank
		overclock_cycles /= 2;
	}
}



int retro_get_overclock(GB_gameboy_t *gb, int cycles)
{
	/*
	direct wave pcm = manual timing
	- Boxxle II = yeah! stage clear  [di, ffff wave, 0 freq / pulse]
	*/

	if (
		gb->ime == false &&
		gb->apu.global_enable &&
		gb->apu.wave_channel.enable &&
		gb->apu.is_active[GB_WAVE] &&
		gb->apu.wave_channel.pulse_length == 0x100 &&
		gb->apu.wave_channel.sample_length == 0
	) {
		return 0;
	}
	
	
	if (gb->cgb_double_speed) {
		cycles *= 2;
	}

	if (overclock_cycles > 0) {
		overclock_cycles -= cycles;

		return 1;
	}

	return 0;
}
