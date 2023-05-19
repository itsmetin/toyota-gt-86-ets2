#include "e90canbus.h"
#include "globals.h"

const uint16_t CAN_ID = 0x141;
uint8_t rpm_frame[8] = {0x8F, 0x26, 0xDF, 0x28, 0x34, 0x0D, 0xA7, 0x00};

void canSendRPM(){
  uint16_t value = s_rpm / 256;

  rpm_frame[5] = value;
  rpm_frame[6] = value + 0x80;

  CAN.sendMsgBuf(CAN_ID, 0, 8, rpm_frame);
}
