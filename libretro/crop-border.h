#define RETRO_SETVARS_CROP_BORDER \
    { \
        "sameboy_crop_border", \
        "Video - Crop Border", \
        "Crop Border", \
        "Crop SGB border toggle.", \
        NULL, \
        "video", \
        { \
            { "Off",  NULL }, \
            { "On",  NULL }, \
            { NULL, NULL }, \
        }, \
        "Off" \
    },



#define RETRO_SETVARS_CROP_BORDER_WIDTH \
    { \
        "sameboy_crop_border_width", \
        "Video - Crop Border Width", \
        "Crop Border Width", \
        "Remove SGB border width.", \
        NULL, \
        "video", \
        { \
            { "0",  NULL }, \
            { "2",  NULL }, \
            { "4",  NULL }, \
            { "6",  NULL }, \
            { "8",  NULL }, \
            { "10", NULL }, \
            { "12", NULL }, \
            { "14", NULL }, \
            { "16", NULL }, \
            { "18", NULL }, \
            { "20", NULL }, \
            { "22", NULL }, \
            { "24", NULL }, \
            { "26", NULL }, \
            { "28", NULL }, \
            { "30", NULL }, \
            { "32", NULL }, \
            { "34", NULL }, \
            { "36", NULL }, \
            { "38", NULL }, \
            { "40", NULL }, \
            { "42", NULL }, \
            { "44", NULL }, \
            { "46", NULL }, \
            { "48", NULL }, \
            { "50", NULL }, \
            { "52", NULL }, \
            { "54", NULL }, \
            { "56", NULL }, \
            { "58", NULL }, \
            { "60", NULL }, \
            { "62", NULL }, \
            { "64", NULL }, \
            { "66", NULL }, \
            { "68", NULL }, \
            { "70", NULL }, \
            { "72", NULL }, \
            { "74", NULL }, \
            { "76", NULL }, \
            { "78", NULL }, \
            { "80", NULL }, \
            { "82", NULL }, \
            { "84", NULL }, \
            { "86", NULL }, \
            { "88", NULL }, \
            { "90", NULL }, \
            { "92", NULL }, \
            { "94", NULL }, \
            { "96", NULL }, \
            { NULL, NULL }, \
        }, \
        "0" \
    },



#define RETRO_SETVARS_CROP_BORDER_HEIGHT \
    { \
        "sameboy_crop_border_height", \
        "Video - Crop Border Height", \
        "Crop Border Height", \
        "Remove SGB border height.", \
        NULL, \
        "video", \
        { \
            { "0",  NULL }, \
            { "2",  NULL }, \
            { "4",  NULL }, \
            { "6",  NULL }, \
            { "8",  NULL }, \
            { "10", NULL }, \
            { "12", NULL }, \
            { "14", NULL }, \
            { "16", NULL }, \
            { "18", NULL }, \
            { "20", NULL }, \
            { "22", NULL }, \
            { "24", NULL }, \
            { "26", NULL }, \
            { "28", NULL }, \
            { "30", NULL }, \
            { "32", NULL }, \
            { "34", NULL }, \
            { "36", NULL }, \
            { "38", NULL }, \
            { "40", NULL }, \
            { "42", NULL }, \
            { "44", NULL }, \
            { "46", NULL }, \
            { "48", NULL }, \
            { "50", NULL }, \
            { "52", NULL }, \
            { "54", NULL }, \
            { "56", NULL }, \
            { "58", NULL }, \
            { "60", NULL }, \
            { "62", NULL }, \
            { "64", NULL }, \
            { "66", NULL }, \
            { "68", NULL }, \
            { "70", NULL }, \
            { "72", NULL }, \
            { "74", NULL }, \
            { "76", NULL }, \
            { "78", NULL }, \
            { "80", NULL }, \
            { NULL, NULL }, \
        }, \
        "0" \
    },



#define RETRO_GETVARS_CROP_BORDER \
        var.key = "sameboy_crop_border"; \
        var.value = NULL; \
        if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) { \
            retro_crop_border = strcmp(var.value, "On") == 0; \
            geometry_updated = true; \
        } \
        \
        \
        var.key = "sameboy_crop_border_width"; \
        var.value = NULL; \
        if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) { \
            retro_crop_border_width = atoi(var.value); \
            geometry_updated = true; \
        } \
        \
        \
        var.key = "sameboy_crop_border_height"; \
        var.value = NULL; \
        if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) { \
            retro_crop_border_height = atoi(var.value); \
            geometry_updated = true; \
        }



extern int retro_crop_border_width;
extern int retro_crop_border_height;
extern int retro_crop_border;


extern int get_border_width(GB_gameboy_t *gb);
extern int get_border_height(GB_gameboy_t *gb);
extern int get_border_ptr(GB_gameboy_t *gb);
