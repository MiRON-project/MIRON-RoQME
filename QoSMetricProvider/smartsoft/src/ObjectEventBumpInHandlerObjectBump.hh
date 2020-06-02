

#ifndef _OBJECTEVENTBUMPINHANDLERObjectBump_HH
#define _OBJECTEVENTBUMPINHANDLERObjectBump_HH

#include "ObjectEventBumpInHandlerObjectBumpCore.hh"
#include <RoqmeWriterImpl.h>
	
class ObjectEventBumpInHandlerObjectBump : public ObjectEventBumpInHandlerObjectBumpCore
{		
public:
	ObjectEventBumpInHandlerObjectBump(Smart::InputSubject<CommObjectRecognitionObjects::CommObjectRecognitionEventBumpResult> *subject, const int &prescaleFactor=1);
	virtual ~ObjectEventBumpInHandlerObjectBump();
	
	virtual void on_ObjectEventBumpInObjectBump(const CommObjectRecognitionObjects::CommObjectRecognitionEventBumpResult &input);
	
private:
	Roqme::RoqmeEnumWriter enum_dw;
};

#endif
