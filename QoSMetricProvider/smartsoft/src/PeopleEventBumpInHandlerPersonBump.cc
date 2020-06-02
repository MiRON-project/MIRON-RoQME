 
#include "PeopleEventBumpInHandlerPersonBump.hh"
#include <iostream>

PeopleEventBumpInHandlerPersonBump::PeopleEventBumpInHandlerPersonBump(Smart::InputSubject<CommObjectRecognitionObjects::CommObjectRecognitionEventBumpResult> *subject, const int &prescaleFactor)
:	PeopleEventBumpInHandlerPersonBumpCore(subject, prescaleFactor)
{
	std::cout << "constructor PeopleEventBumpInHandler\n";
}
PeopleEventBumpInHandlerPersonBump::~PeopleEventBumpInHandlerPersonBump() 
{
	std::cout << "destructor PeopleEventBumpInHandlerPersonBump\n";
}

void PeopleEventBumpInHandlerPersonBump::on_PeopleEventBumpInPersonBump(const CommObjectRecognitionObjects::CommObjectRecognitionEventBumpResult &input)
{
	
	try
	{
		RoqmeDDSTopics::RoqmeEnumContext enumContext;
		enumContext.name("PersonBump");
		enumContext.value().push_back(input.getState().to_string());
		std::cout << "Publishing data context" << std::endl;
		enum_dw.write(enumContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}
