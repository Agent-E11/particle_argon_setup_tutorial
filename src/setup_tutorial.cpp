/* 
 * Project setup_tutorial
 * Author: Eamon Burns
 * Date: 23-01-11
 */

// Include Particle Device OS APIs
#include "Particle.h"

#include <cmath>
#include <string>

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

// Setup temp sensor
#include "Grove_Temperature_And_Humidity_Sensor.h"

DHT dht(D2);

float temp, humidity;
double temp_dbl, humidity_dbl;

// Setup LEDs
#include "Grove_ChainableLED.h"

ChainableLED leds(A4, A5, 1);

int toggle_led(String args) {
    Particle.publish("Called `toggle_led`");

    leds.setColorHSB(0, 0.0, 1.0, 0.5);
    
    delay(500);

    leds.setColorHSB(0, 0.0, 0.0, 0.0);

    delay(500);
    
    return 1;
}

// setup() runs once, when the device is first turned on
void setup() {
    Serial.begin();
    
    leds.init();

    leds.setColorHSB(0, 0.0, 0.0, 0.0);
    
    // dht.begin();
    
    // Particle.variable("temp", temp_dbl);
    // Particle.variable("humidity", humidity_dbl);
    
    Particle.function("blink_led", toggle_led);
}

float t = 0.0;

float my_mod(float num, float denom) {
    int whole_part = floor(num / denom);
    
    return (num / denom) - whole_part;
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

    // temp = dht.getTempFarenheit();
    // humidity = dht.getHumidity();
    
    // Serial.printlnf("Temp: %f", temp);
    // Serial.printlnf("Humidity: %f", humidity);
    
    // temp_dbl = temp;
    // humidity_dbl = humidity;
    
}
