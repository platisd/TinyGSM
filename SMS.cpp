#include "TinyGSM.h"

SMS::SMS(String rawText){
	_sender = rawText.substring(0,rawText.indexOf('"'));
	_sender.trim();
	_text = rawText.substring(rawText.indexOf('\n')+1);
	_text.trim();
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
