#define RETRO_SETVARS_FAST_BOOTROM \
    { \
        "sameboy_fast_bootrom", \
        "System - Fast Boot", \
        "Fast boot", \
        "Skip BIOS logo.", \
        NULL, \
        "system", \
        { \
            { "Off", NULL }, \
            { "On",  NULL }, \
            { NULL, NULL }, \
        }, \
        "Off" \
    },



#define RETRO_GETVARS_FAST_BOOTROM \
        var.key = "sameboy_fast_bootrom"; \
        var.value = NULL; \
        if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) { \
            retro_fast_boot = strcmp(var.value, "On") == 0; \
        }



extern int retro_fast_boot;
