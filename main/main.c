#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_app_desc.h"
#include "sdkconfig.h"
#include "led_blink.h"

static const char *TAG = "example";

static uint8_t s_led_state = 0;

void app_main(void)
{
    const esp_app_desc_t *app_desc = esp_app_get_description();
    ESP_LOGI(TAG, "Firmware version: %s", app_desc->version);

    /* Configure the peripheral according to the LED type */
    configure_led();

    while (1) {
        ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF");
        blink_led(s_led_state);
        /* Toggle the LED state */
        s_led_state = !s_led_state;
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}
