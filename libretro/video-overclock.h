#define RETRO_SETVARS_VIDEO_OVERCLOCK \
	{ \
		"sameboy_video_overclock", \
		"System - Video Overclock", \
		"Video Overclock", \
		"Add extra scanlines to video frame time.", \
		NULL, \
		"system", \
		{ \
			{ "100",  "100%" }, \
			{ "150",  "150%" }, \
			{ "200",  "200%" }, \
			{ "250",  "250%" }, \
			{ "300",  "300%" }, \
			{ "350",  "350%" }, \
			{ "400",  "400%" }, \
			{ "450",  "450%" }, \
			{ "500",  "500%" }, \
			{ "600",  "600%" }, \
			{ "700",  "700%" }, \
			{ "800",  "800%" }, \
			{ "900",  "900%" }, \
			{ "1000", "1000%" }, \
			{ NULL, NULL }, \
		}, \
		"100" \
	},




#define RETRO_SETVARS_VIDEO_OVERCLOCK_TYPE \
	{ \
		"sameboy_video_overclock_type", \
		"System - Video Overclock Mode", \
		"Video Overclock Mode", \
		"Where to add virtual overclock scanlines.", \
		NULL, \
		"system", \
		{ \
			{ "Disabled", NULL }, \
			{ "Pre-Vblank", NULL }, \
			{ "Post-Vblank", NULL }, \
			{ "Split", NULL }, \
			{ NULL, NULL }, \
		}, \
		"Disabled" \
	},




#define RETRO_GETVARS_VIDEO_OVERCLOCK \
	var.key = "sameboy_video_overclock"; \
        var.value = NULL; \
        if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) { \
		retro_video_overclock = atoi(var.value); \
        } \
	\
	\
	var.key = "sameboy_video_overclock_type"; \
        var.value = NULL; \
        if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) { \
		retro_video_overclock_type = 0; \
		\
		if (strcmp("Pre-Vblank", var.value) == 0) { \
			retro_video_overclock_type = 1; \
		} \
		\
		else if (strcmp("Post-Vblank", var.value) == 0) { \
			retro_video_overclock_type = 2; \
		} \
		\
		else if (strcmp("Split", var.value) == 0) { \
			retro_video_overclock_type = 3; \
		} \
        }




extern int retro_video_overclock;
extern int retro_video_overclock_type;
