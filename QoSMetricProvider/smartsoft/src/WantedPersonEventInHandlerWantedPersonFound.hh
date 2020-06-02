

#ifndef _WANTEDPERSONEVENTINHANDLERWantedPersonFound_HH
#define _WANTEDPERSONEVENTINHANDLERWantedPersonFound_HH

#include "WantedPersonEventInHandlerWantedPersonFoundCore.hh"
#include <RoqmeWriterImpl.h>
	
class WantedPersonEventInHandlerWantedPersonFound : public WantedPersonEventInHandlerWantedPersonFoundCore
{		
public:
	WantedPersonEventInHandlerWantedPersonFound(Smart::InputSubject<CommObjectRecognitionObjects::CommObjectRecognitionEventResult> *subject, const int &prescaleFactor=1);
	virtual ~WantedPersonEventInHandlerWantedPersonFound();
	
	virtual void on_WantedPersonEventInWantedPersonFound(const CommObjectRecognitionObjects::CommObjectRecognitionEventResult &input);
	
private:
	Roqme::RoqmeEnumWriter enum_dw;
};

#endif
