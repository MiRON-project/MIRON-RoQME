

#ifndef _BUMPEREVENTSERVICEINHANDLERRobotBump_HH
#define _BUMPEREVENTSERVICEINHANDLERRobotBump_HH

#include "BumperEventServiceInHandlerRobotBumpCore.hh"
#include <RoqmeWriterImpl.h>
	
class BumperEventServiceInHandlerRobotBump : public BumperEventServiceInHandlerRobotBumpCore
{		
public:
	BumperEventServiceInHandlerRobotBump(Smart::InputSubject<CommBasicObjects::CommBumperEventResult> *subject, const int &prescaleFactor=1);
	virtual ~BumperEventServiceInHandlerRobotBump();
	
	virtual void on_BumperEventServiceInRobotBump(const CommBasicObjects::CommBumperEventResult &input);
	
private:
	Roqme::RoqmeEnumWriter enum_dw;
};

#endif
