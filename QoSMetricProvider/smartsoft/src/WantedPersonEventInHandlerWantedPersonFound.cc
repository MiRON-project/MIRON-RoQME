 
#include "WantedPersonEventInHandlerWantedPersonFound.hh"
#include <iostream>

WantedPersonEventInHandlerWantedPersonFound::WantedPersonEventInHandlerWantedPersonFound(Smart::InputSubject<CommObjectRecognitionObjects::CommObjectRecognitionEventResult> *subject, const int &prescaleFactor)
:	WantedPersonEventInHandlerWantedPersonFoundCore(subject, prescaleFactor)
{
	std::cout << "constructor WantedPersonEventInHandler\n";
}
WantedPersonEventInHandlerWantedPersonFound::~WantedPersonEventInHandlerWantedPersonFound() 
{
	std::cout << "destructor WantedPersonEventInHandlerWantedPersonFound\n";
}

void WantedPersonEventInHandlerWantedPersonFound::on_WantedPersonEventInWantedPersonFound(const CommObjectRecognitionObjects::CommObjectRecognitionEventResult &input)
{
	
	try
	{
		RoqmeDDSTopics::RoqmeEnumContext enumContext;
		enumContext.name("WantedPersonFound");
		enumContext.value().push_back(input.getState().to_string());
		std::cout << "Publishing data context" << std::endl;
		enum_dw.write(enumContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}
