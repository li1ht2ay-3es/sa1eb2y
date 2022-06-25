static char osd_message[4096];


void retro_osd_message_add(char *str)
{
	if (osd_message[0] != '\0')
		strcat(osd_message, "\n");


	strcat(osd_message, str);
}



void retro_osd_message_send(retro_environment_t environ_cb)
{
	if (osd_message[0] == '\0')
		return;


	struct retro_message msg = { osd_message, 120+30 };
	environ_cb(RETRO_ENVIRONMENT_SET_MESSAGE, &msg);
	
	
	osd_message[0] = '\0';
}
