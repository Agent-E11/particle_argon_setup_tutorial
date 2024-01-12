/* 
 * Project setup_tutorial
 * Author: Eamon Burns
 * Date: 23-01-11
 */

// Include Particle Device OS APIs
#include "Particle.h"

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

// setup() runs once, when the device is first turned on
void setup() {
    Serial.begin();
    
    dht.begin();
    
    Particle.variable("temp", temp_dbl);
    Particle.variable("humidity", humidity_dbl);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

    temp = dht.getTempFarenheit();
    humidity = dht.getHumidity();
    
    Serial.printlnf("Temp: %f", temp);
    Serial.printlnf("Humidity: %f", humidity);
    
    temp_dbl = temp;
    humidity_dbl = humidity;
    
    delay(10 * 1000);
}
