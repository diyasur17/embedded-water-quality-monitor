# Embedded Water-Quality Alert Prototype

This project is a C++-based water-quality alert prototype designed for Arduino microcontrollers, inspired by research into "Filter First" drinking water legislation. It uses an 8-point moving average filter to process simulated sensor inputs, successfully smoothing out erratic data to reliably trigger an LCD alert system without screen flickering.

## Performance Results
The software-injected noise was evaluated to ensure the moving average filter performed as mathematically expected:
* **Raw Noise Standard Deviation ($\sigma$):** ~4.87
* **Filtered Standard Deviation ($\sigma$):** ~1.67
* **Noise Reduction:** The filter successfully achieved the theoretical sqrt{8} prediction, reducing sensor jitter by approximately 2.8x.

## System Lag
Because the filter requires 8 data points to average, it introduces a mathematical delay of about 3.5 samples. At the current loop rate of 10 Hz, this results in a minimal system lag of 0.35 seconds, which is acceptable for environmental monitoring.

## Limitations & Future Scope
* **Simulated Hardware:** Inputs are currently simulated using a potentiometer, with environmental noise injected purely via software.
* **Arbitrary Thresholds:** The "action level" threshold is currently set for prototype demonstration and is not yet mapped to a cited regulatory standard (e.g., EPA lead/copper limits).
* **Future Upgrades:** Future iterations will include non-blocking `millis()` timing, hardware integration (e.g., NTC thermistors), and software hysteresis for even better UI stability.
