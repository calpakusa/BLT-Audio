/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# Basic usage of on-board LED and button
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <asf.h>

void app_call_back(struct tc_module *const module)
{
	
}

void init_app_tc(void)
{
	struct tc_config app_tc_config;
	struct tc_module app_tc_module;
	
	tc_get_config_defaults(&app_tc_config);
	app_tc_config.clock_source = GCLK_GENERATOR_0;
	app_tc_config.clock_prescaler = TC_CLOCK_PRESCALER_DIV1024;
	app_tc_config.counter_size = TC_COUNTER_SIZE_8BIT;
	app_tc_config.count_direction = TC_COUNT_DIRECTION_UP;
	tc_init(&app_tc_module,APP_TC,&app_tc_config);
	tc_set_top_value(&app_tc_module,78);
	tc_register_callback(&app_tc_module,&AppCallBack,TC_CALLBACK_OVERFLOW);
	tc_enable_callback(&app_tc_module,TC_CALLBACK_OVERFLOW);
	tc_enable(&app_tc_module);
	tc_start_counter(&app_tc_module);
}

int main (void)
{
	system_init();

	// Insert application code here, after the board has been initialized.

	// This skeleton code simply sets the LED to the state of the button.
	while (1)
	{
	}
}
