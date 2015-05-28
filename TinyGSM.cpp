#include "TinyGSM.h"


const unsigned short TINYGSM_BAUD_RATE = 19200;

TinyGSM::TinyGSM(){}

void TinyGSM::begin(SoftwareSerial *serial){
	_serial = serial;
	_serial->begin(TINYGSM_BAUD_RATE);
	while (!isConnected()); //TO-DO: add timeout
	disableEcho();
	delay(100);
	enableSMSNotification();
	delay(100);
	flush();
}

boolean TinyGSM::isConnected(){
	print("AT+CREG?\r");
	delay(100);
	while(_serial->available()){
		String input = _serial->readStringUntil('\n');
		input.trim();
		if (input.equals("+CREG: 0,1") || input.equals("+CREG: 0,5")) return true;
	}
	return false;
}

void TinyGSM::flush(){
	while (_serial->read() != -1);
}

void TinyGSM::disableEcho(){
	print("ATE0\r");
}

void TinyGSM::print(String input){
	_serial->print(input);
}

void TinyGSM::print(char inChar){
	_serial->print(inChar);
}

void TinyGSM::print(char *input){
	_serial->print(input);
}

void TinyGSM::sendSMS(String recipient, String text){
	print("AT+CMGF=1\r");
	delay(100);
	print("AT+CMGS=\"");
	print(recipient);
	print("\"");
	print('\r');
	delay(100);
	print(text);
	delay(100);
	print((char)26); //ctrl+z
	delay(100);
}

void TinyGSM::enableSMSNotification(){
	print("AT+CNMI=1,2,0,0,0\r");
}

boolean TinyGSM::SMSreceived(){
	if (_serial->available()){
		_serial->setTimeout(200);
		String input = _serial->readStringUntil('"');
		input.trim();
		if (input.startsWith("+CMT:")) return true;
	}
	return false;
}

String TinyGSM::getSMS(){
	if (_serial->available()){
		_serial->setTimeout(200);
		String input = _serial->readStringUntil('\n'); //read first line
		input += '\n';
		input += _serial->readStringUntil('\n'); //read second line
		return input;
	}
	return "error";
}
