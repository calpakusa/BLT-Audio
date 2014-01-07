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
#include "conf_board.h"

void app_call_back(struct tc_module *const module);
void init_app_tc(void);

struct tc_config app_tc_config;
struct tc_module app_tc_module;

void app_call_back(struct tc_module *const module)
{
	if(module == &app_tc_module)
	{
		
	}
}

void init_app_tc(void)
{
	tc_get_config_defaults(&app_tc_config);
	app_tc_config.clock_source = GCLK_GENERATOR_0;
	app_tc_config.clock_prescaler = TC_CLOCK_PRESCALER_DIV1024;
	app_tc_config.counter_size = TC_COUNTER_SIZE_8BIT;
	app_tc_config.count_direction = TC_COUNT_DIRECTION_UP;
	tc_init(&app_tc_module,APP_TC,&app_tc_config);
	tc_set_top_value(&app_tc_module,78);
	tc_register_callback(&app_tc_module,&app_call_back,TC_CALLBACK_OVERFLOW);
	tc_enable_callback(&app_tc_module,TC_CALLBACK_OVERFLOW);
	tc_enable(&app_tc_module);
	tc_start_counter(&app_tc_module);
}

void board_init(void)
{
	struct port_config pin_conf;
	port_get_config_defaults(&pin_conf);

	// Configure LEDs as outputs, turn them off
	pin_conf.direction  = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(LED_Phantom, &pin_conf);
	port_pin_set_output_level(LED_Phantom, true);
	port_pin_set_config(LED_MIC, &pin_conf);
	port_pin_set_output_level(LED_MIC, true);
	port_pin_set_config(LED_LINE, &pin_conf);
	port_pin_set_output_level(LED_LINE, true);
	port_pin_set_config(LED_HBEAT, &pin_conf);
	port_pin_set_output_level(LED_HBEAT, true);
/*
	// Set buttons as inputs
	pin_conf.direction  = PORT_PIN_DIR_INPUT;
	pin_conf.input_pull = PORT_PIN_PULL_UP;
	port_pin_set_config(BUTTON_0_PIN, &pin_conf);
*/
}

int main (void)
{
	//system_init();
	// Configure GCLK and clock sources according to conf_clocks.h
	system_clock_init();
	// Initialize board hardware
	board_init();
	
	init_app_tc();

	// Insert application code here, after the board has been initialized.

	// This skeleton code simply sets the LED to the state of the button.
	while (1)
	{
	}
}
