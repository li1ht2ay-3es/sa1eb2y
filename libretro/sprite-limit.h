#define RETRO_SETVARS_SPRITE_LIMIT \
    { \
        "sameboy_sprite_limit", \
        "Video - Sprite Limit", \
        "Sprite Limit", \
        "Maximum number of sprites that can be drawn.", \
        NULL, \
        "video", \
        { \
            { "10", NULL }, \
            { "15", NULL }, \
            { "20", NULL }, \
            { "25", NULL }, \
            { "30", NULL }, \
            { "35", NULL }, \
            { "40", NULL }, \
            { NULL, NULL }, \
        }, \
        "10" \
    },



#define RETRO_GETVARS_SPRITE_LIMIT \
        var.key = "sameboy_sprite_limit"; \
        var.value = NULL; \
        if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) { \
            retro_sprite_limit = atoi(var.value); \
        }



extern int retro_sprite_limit;
