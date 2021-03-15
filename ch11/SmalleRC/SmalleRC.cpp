#include "SmalleRC.h"

RH_RF69 rf69(RFM69_CS, RFM69_INT);

char rc_start() {
  pinMode(LED, OUTPUT);     
  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, LOW);

  // manual reset
  digitalWrite(RFM69_RST, HIGH);
  delay(10);
  digitalWrite(RFM69_RST, LOW);
  delay(10);
  
  if (!rf69.init()) {
    return rc_INIT_FAILED;
  }
  
  if (!rf69.setFrequency(RF69_FREQ)) {
    return rc_FREQ_FAILED;
  }

  rf69.setTxPower(17, true);  // range from 14-20 for power, 2nd arg must be true for 69HCW

  // The encryption key has to be the same for the car and the control
  uint8_t key[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
  rf69.setEncryptionKey(key);
  
  pinMode(LED, OUTPUT);
  return rc_INIT_SUCCESS;
}

void rc_send(int d) {
  uint8_t packet[1] = { d };
  rf69.send(packet, 1);
  rf69.waitPacketSent();
}

int rc_receive() {
  uint8_t buf[RH_RF69_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);
  if (rf69.recv(buf, &len)) {
    if (len <= 0) {
      return -1;
    }
    buf[len] = 0;
    return buf[0];
  }
  return 0;
}

