#define RETRO_SETVARS_VRAM_BLOCKING \
	{ \
		"sameboy_vram_blocking", \
		"Video - VRAM Blocking", \
		"VRAM Access", \
		"Allow memory access to Video RAM outside VBlank.", \
		NULL, \
		"video", \
		{ \
			{ "Off",  NULL }, \
			{ "On",  NULL }, \
			{ NULL, NULL }, \
		}, \
		"Off" \
	},




#define RETRO_GETVARS_VRAM_BLOCKING \
	var.key = "sameboy_vram_blocking"; \
	var.value = NULL; \
	if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) { \
		retro_vram_blocking = strcmp(var.value, "Off") == 0; \
	}



extern int retro_vram_blocking;

extern int get_retro_vram_blocking();
