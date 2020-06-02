

#ifndef _PEOPLEEVENTSERVICEINHANDLERPeopleInRoom_HH
#define _PEOPLEEVENTSERVICEINHANDLERPeopleInRoom_HH

#include "PeopleEventServiceInHandlerPeopleInRoomCore.hh"
#include <RoqmeWriterImpl.h>
	
class PeopleEventServiceInHandlerPeopleInRoom : public PeopleEventServiceInHandlerPeopleInRoomCore
{		
public:
	PeopleEventServiceInHandlerPeopleInRoom(Smart::InputSubject<CommObjectRecognitionObjects::CommObjectRecognitionEventResult> *subject, const int &prescaleFactor=1);
	virtual ~PeopleEventServiceInHandlerPeopleInRoom();
	
	virtual void on_PeopleEventServiceInPeopleInRoom(const CommObjectRecognitionObjects::CommObjectRecognitionEventResult &input);
	
private:
	Roqme::RoqmeEnumWriter enum_dw;
};

#endif
