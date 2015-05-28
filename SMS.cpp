#include "TinyGSM.h"

SMS::SMS(String rawText){
	_sender = rawText.substring(0,rawText.indexOf('"'));
	_sender.trim();
	_text = rawText.substring(rawText.indexOf('\n')+1);
	_text.trim();
	rawText = rawText.substring(rawText.indexOf('"'), rawText.indexOf('\n')-2);
	rawText = rawText.substring(rawText.lastIndexOf('"') + 1, rawText.indexOf('+'));
	_date = rawText.substring(0,rawText.indexOf(','));
	_date.trim();
	_time = rawText.substring(rawText.indexOf(',') + 1);
	_time.trim();
}

String SMS::getText(){
	if (!_text.length()){
		return "error";
	}else{
		return _text;
	}
}

String SMS::getSender(){
	if (!_sender.length()){
		return "error";
	}else{
		return _sender;
	}
}

String SMS::getTime(){
	if (!_time.length()){
		return "error";
	}else{
		return _time;
	}	
}

String SMS::getDate(){
	if (!_date.length()){
		return "error";
	}else{
		return _date;
	}
}
