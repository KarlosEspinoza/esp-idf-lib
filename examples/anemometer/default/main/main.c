/* WiFi station Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>
#include <esp_log.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <esp_event.h>
#include <esp_timer.h>
#include <esp_netif.h>
#include <esp_wifi.h>
#include <driver/gpio.h>

#include <anemometer.h>

static const char *TAG="APP";

void app_main()
{
    float val;
    anemometer_config_t config = {
        .input_pin = CONFIG_EXAMPLE_ANEMOMETER_GPIO,
        .scale_factor = ANEMOMETER_DEFAULT_SF
    };

    anemometer_t wind_sensor = anemometer_init(&config);

    while(1){
        anemometer_get_wind_speed(wind_sensor,&val);
        ESP_LOGI(TAG, "Wind speed = %.2f m/s", val);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
