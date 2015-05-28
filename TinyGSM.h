#ifndef tiny_gsm_h
#define tiny_gsm_h
#include <Arduino.h>
#include <SoftwareSerial.h>

class TinyGSM{
	public:
		TinyGSM();
		boolean begin(SoftwareSerial *serial);
		void sendSMS(String recipient, String text);
		void print(String input);
		void print(char inChar);
		void print(char *input);
		void flush();
		boolean SMSreceived();
		String getSMS();
	private:
		boolean isConnected();
		boolean timeOut(unsigned long currentTime, unsigned long timeout);
		void disableEcho();
		void enableSMSNotification();
		SoftwareSerial *_serial;
};

class SMS{
	public:
		SMS(String rawText);
		String getText();
		String getSender();
		String getTime();
		String getDate();
	private:
		String _sender, _text, _time, _date;
};

#endif
