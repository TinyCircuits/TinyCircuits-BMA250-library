# BMA250 library

Used for the TinyCircuits Accelerometer **[BMA250 on the TinyZero](https://tinycircuits.com/collections/processors/products/tinyzero-processor?variant=21137366515796)**,the *[Accelerometer TinyShield](https://tinycircuits.com/collections/sensors/products/accelerometer-tinyshield)**, and the **[Accelerometer Wireling](https://tinycircuits.com/collections/wireling-sensors/products/accelerometer-wireling-bma250)**. 

*Support this library by buying products from **[TinyCircuits](https://tinycircuits.com/)***


## BMA250 Class

* **int begin(uint8_t range, uint8_t bandwidth)** Input the *range* of acceleration readings (±2/±4g/±8g/±16g) and low-pass filter *bandwidth* 1kHz - < 8Hz to initialize the accelerometer in the proper reading mode
* **void read()** Reads and assigns the BMA250 class variables *X*, *Y*, *Z*, and *tempC*
