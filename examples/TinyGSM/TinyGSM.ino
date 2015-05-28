#include <SoftwareSerial.h>
#include <TinyGSM.h>

SoftwareSerial mySerial(2, 3);
TinyGSM gsm;

void setup() {
  Serial.begin(9600);
  gsm.begin(&mySerial);
  gsm.sendSMS("+46769220230", "Hi there!");
  gsm.flush();
}

void loop() {
//  if (mySerial.available())
//
//    Serial.write(mySerial.read());
//
//  if (Serial.available())
//
//    mySerial.write(Serial.read());
  if (gsm.SMSreceived()){
    SMS sms(gsm.getSMS());
//    Serial.print("Sender: ");
//    Serial.println(sms.getSender());
//    Serial.print("Text: ");
//    Serial.println(sms.getText());
    if (sms.getText().equalsIgnoreCase("What is your name?")){
      gsm.sendSMS(sms.getSender(), "tinyGSM");
    }
  }
}
