#include "ESP32CAN.h"
#include <Arduino.h>

int ESP32CAN::CANInit() {
  return CAN_init();
}
int ESP32CAN::CANWriteFrame(const CAN_frame_t* p_frame) {
  static unsigned long start_time;
  int result = -1;
  if (tx_ok) {
    result = CAN_write_frame(p_frame);
    tx_ok = (result == 0) ? true : false;
    if (tx_ok == false) {
      Serial.println("CAN failure! Check wires");
      LEDcolor = 3;
      start_time = millis();
    }
  } else {
    if ((millis() - start_time) >= 2000) {
      tx_ok = true;
      LEDcolor = 0;
    }
  }
  return result;
}
int ESP32CAN::CANStop() {
  return CAN_stop();
}
int ESP32CAN::CANConfigFilter(const CAN_filter_t* p_filter) {
  return CAN_config_filter(p_filter);
}

ESP32CAN ESP32Can;
