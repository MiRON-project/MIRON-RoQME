 
#include "BatteryPushServiceInHandlerBatteryCharging.hh"
#include <iostream>

BatteryPushServiceInHandlerBatteryCharging::BatteryPushServiceInHandlerBatteryCharging(Smart::InputSubject<CommBasicObjects::CommBatteryLevel> *subject, const int &prescaleFactor)
:	BatteryPushServiceInHandlerBatteryChargingCore(subject, prescaleFactor)
{
	std::cout << "constructor BatteryPushServiceInHandler\n";
}
BatteryPushServiceInHandlerBatteryCharging::~BatteryPushServiceInHandlerBatteryCharging() 
{
	std::cout << "destructor BatteryPushServiceInHandlerBatteryCharging\n";
}

void BatteryPushServiceInHandlerBatteryCharging::on_BatteryPushServiceInBatteryCharging(const CommBasicObjects::CommBatteryLevel &input)
{
	
	try
	{
		RoqmeDDSTopics::RoqmeBooleanContext booleanContext;
		booleanContext.name("BatteryCharging");
		booleanContext.value().push_back(input.getExternalPower());
		std::cout << "Publishing data context" << std::endl;
		boolean_dw.write(booleanContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}
