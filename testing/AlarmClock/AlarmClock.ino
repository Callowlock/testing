#include "Date.h"
#include "Time.h"
#include <LiquidCrystal.h>

Date d = Date(1,12,12);

void setup() {
  Serial.begin(9600);
  

}

void loop() {
  Serial.println(d.dateToString());
  // put your main code here, to run repeatedly:
  delay(1000);
}
