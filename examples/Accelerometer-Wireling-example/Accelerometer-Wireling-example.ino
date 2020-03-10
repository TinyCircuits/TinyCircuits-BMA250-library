/*************************************************************************
 * Accelerometer BMA250 Wireling Tutorial:
 * This example program will show the basic method of printing out the 
 * accelerometer values from the BMA250 to the Serial Monitor/Serial Plotter
 * 
 * Hardware by: TinyCircuits
 * Code by: Laveréna Wienclaw for TinyCircuits
 *
 * Initiated: 11/29/2017 
 * Updated: 12/06/2019
 ************************************************************************/
 
#include <Wire.h>         // For I2C communication with sensor
#include <Wireling.h>     // For interfacing with Wirelings
#include <BMA250.h>       // For interfacing with the accel. sensor

// Accelerometer sensor variables for the sensor and its values
BMA250 accel_sensor;
int x, y, z, temp;

// Make Serial Monitor compatible for all TinyCircuits processors
#if defined(ARDUINO_ARCH_AVR)
  #define SerialMonitorInterface Serial
#elif defined(ARDUINO_ARCH_SAMD)
  #define SerialMonitorInterface SerialUSB
#endif

void setup() {
  SerialMonitorInterface.begin(115200);
  Wire.begin();

  // Initialize Wireling
  Wireling.begin();
  Wireling.selectPort(0); 

  // Sets up the BMA250 accelerometer
  accel_sensor.begin(BMA250_range_2g, BMA250_update_time_64ms); 
}

void loop() {
  accel_sensor.read();//This function gets new data from the accelerometer

  // Get the acceleration values from the sensor and store them into local variables
  // (Makes reading the rest of the program easier)
  x = accel_sensor.X;
  y = accel_sensor.Y;
  z = accel_sensor.Z;
  temp = ((accel_sensor.rawTemp * 0.5) + 24.0, 1);

 // If the BMA250 is not found, nor connected correctly, these values will be produced
 // by the sensor 
  if (x == -1 && y == -1 && z == -1) {
    // Print error message to Serial Monitor
    SerialMonitorInterface.print("ERROR! NO BMA250 DETECTED!");
  }
  else { // if we have correct sensor readings: 
    showSerial();                 //Print to Serial Monitor or Serial Plotter
  }

  // The BMA250 can only poll new sensor values every 64ms, so this delay
  // will ensure that we can continue to read values
  delay(250);
  // ***Without the delay, there would not be any sensor output*** 
}

// Prints the sensor values to the Serial Monitor (found under 'Tools')
void showSerial() {
  SerialMonitorInterface.print("X = ");
  SerialMonitorInterface.print(x);
  
  SerialMonitorInterface.print("  Y = ");
  SerialMonitorInterface.print(y);
  
  SerialMonitorInterface.print("  Z = ");
  SerialMonitorInterface.print(z);
  
  SerialMonitorInterface.print("  Temperature(C) = ");
  SerialMonitorInterface.println((accel_sensor.rawTemp * 0.5) + 24.0, 1);
}
