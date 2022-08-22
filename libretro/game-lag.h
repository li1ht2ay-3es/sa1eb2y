#define RETRO_SETVARS_GAME_LAG \
	{ \
		"sameboy_game_lag", \
		"System - Game Lag", \
		"Game Lag", \
		"Measure internal game lag.", \
		NULL, \
		"system", \
		{ \
			{ "0", "Off" }, \
			{ "60", NULL }, \
			{ "50", NULL }, \
			{ "75", NULL }, \
		}, \
		"0" \
	},



#define RETRO_GETVARS_GAME_LAG \
	var.key = "sameboy_game_lag"; \
	var.value = NULL; \
	if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) { \
		retro_game_lag = atoi(var.value); \
		\
		retro_game_lag_reset(); \
	}



extern void retro_game_lag_reset();
extern void retro_game_lag_frame();

extern int retro_game_lag;
