int retro_sprite_priority;


void set_retro_sprite_priority(GB_gameboy_t *gb)
{
    if (!GB_is_cgb_in_cgb_mode(gb)) {
        if (retro_sprite_priority) {
            gb->object_priority = GB_OBJECT_PRIORITY_INDEX;
        }
        else {
            gb->object_priority = GB_OBJECT_PRIORITY_X;
        }
    }
}
