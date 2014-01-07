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
static void init_app_tc(void);
static void init_adc(void);
void adc_convert(void);

struct tc_config app_tc_config;
struct tc_module app_tc_module;
struct adc_config config;
struct adc_module adc_inst;
volatile uint16_t adc_result;

static void init_adc(void)
{
	adc_get_config_defaults(&config);
	
	config.clock_source = GCLK_GENERATOR_3;
	config.reference = ADC_REFERENCE_INT1V;
	config.clock_prescaler = ADC_CLOCK_PRESCALER_DIV512;
	config.resolution = ADC_RESOLUTION_16BIT;
	config.positive_input = ADC_POSITIVE_INPUT_PIN8;
	config.negative_input = ADC_NEGATIVE_INPUT_GND;
	config.accumulate_samples = ADC_ACCUMULATE_SAMPLES_256;
	config.divide_result = ADC_DIVIDE_RESULT_16;
	config.sample_length = 3;
	
	adc_init(&adc_inst, ADC, &config);
	adc_enable(&adc_inst);
}

void adc_convert(void)
{
	adc_start_conversion(&adc_inst);
	
	while(adc_read(&adc_inst, &adc_result) != STATUS_OK);
	adc_flush(&adc_inst);
}

void app_call_back(struct tc_module *const module)
{
	static uint8_t	cnt = 0;
	
	cnt++;
	if(cnt == 5)
	{
		port_pin_set_output_level(LED_HBEAT, false);
	}
	if(cnt >= 50)
	{
		port_pin_set_output_level(LED_HBEAT, true);
		cnt = 0;
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
	tc_set_top_value(&app_tc_module,156);
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
	port_pin_set_output_level(LED_Phantom, false);
	port_pin_set_config(LED_MIC, &pin_conf);
	port_pin_set_output_level(LED_MIC, false);
	port_pin_set_config(LED_LINE, &pin_conf);
	port_pin_set_output_level(LED_LINE, false);
	port_pin_set_config(LED_HBEAT, &pin_conf);
	port_pin_set_output_level(LED_HBEAT, false);
	// Configure RELE as outputs, turn them off
	port_pin_set_config(RELE, &pin_conf);
	port_pin_set_output_level(RELE, false);

	// Set buttons as inputs
	pin_conf.direction  = PORT_PIN_DIR_INPUT;
	port_pin_set_config(IN_MIC_SEL, &pin_conf);
	port_pin_set_config(IN_LINE_SEL, &pin_conf);
	pin_conf.input_pull = PORT_PIN_PULL_UP;
}

int main (void)
{
	// Configure GCLK and clock sources according to conf_clocks.h
	system_clock_init();
	// Initialize board hardware
	board_init();
	
	init_app_tc();

	// Insert application code here, after the board has been initialized.

	// This skeleton code simply sets the LED to the state of the button.
	while (1)
	{
		// Check MIC button
		if (port_pin_get_input_level(IN_MIC_SEL) == false)
		{
			// Turn MIC LED on
			port_pin_set_output_level(LED_MIC, true);
			// Turn LINE LED off
			port_pin_set_output_level(LED_LINE, false);
			// Switch RELE off
			port_pin_set_output_level(RELE, false);
		}
		// Check LINE button
		else if (port_pin_get_input_level(IN_LINE_SEL) == false)
		{
			// Turn MIC LED off
			port_pin_set_output_level(LED_MIC, false);
			// Turn LINE LED on
			port_pin_set_output_level(LED_LINE, true);
			// Switch RELE on
			port_pin_set_output_level(RELE, true);
		}
		else
		{
			// Turn MIC LED off
			port_pin_set_output_level(LED_MIC, false);
			// Turn LINE LED off
			port_pin_set_output_level(LED_LINE, false);
			// Switch RELE off
			port_pin_set_output_level(RELE, false);
		}
	}
}
