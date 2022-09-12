#define RETRO_SETVARS_SPRITE_PRIORITY \
	{ \
		"sameboy_sprite_priority", \
		"Video - Sprite Priority", \
		"Sprite Priority", \
		"Sort by sprite priority for non-gbc models.", \
		NULL, \
		"video", \
		{ \
			{ "Off",  NULL }, \
			{ "On",  NULL }, \
			{ NULL, NULL }, \
		}, \
		"Off" \
	},




#define RETRO_GETVARS_SPRITE_PRIORITY \
	var.key = "sameboy_sprite_priority"; \
	var.value = NULL; \
	if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) { \
		retro_sprite_priority = strcmp(var.value, "On") == 0; \
		\
		set_retro_sprite_priority(&gameboy[0]); \
		if (&gameboy[1]) { \
			set_retro_sprite_priority(&gameboy[1]); \
		} \
	}



extern int retro_sprite_priority;

extern void set_retro_sprite_priority(GB_gameboy_t *gb);
