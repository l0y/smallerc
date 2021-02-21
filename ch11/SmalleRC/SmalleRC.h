#ifndef SMALLERC_H
#define SMALLERC_H

#include "Arduino.h"
#include <SPI.h>
#include <RH_RF69.h>

#define RF69_FREQ 915.0

#define RFM69_CS      4
#define RFM69_INT     3
#define RFM69_RST     2
#define LED           13

#define rc_INIT_SUCCESS  1
#define rc_INIT_FAILED  -1
#define rc_FREQ_FAILED  -2

// Define our direction type
typedef char direction_t;

// Define our direction constants
const direction_t rc_STOP     = 0;
const direction_t rc_LEFT     = 1;
const direction_t rc_RIGHT    = 2;
const direction_t rc_FORWARD  = 3;
const direction_t rc_BACKWARD = 4;

char rc_start();
void rc_send(int d);
int  rc_receive();

#endif /* SMALLERC_H */
