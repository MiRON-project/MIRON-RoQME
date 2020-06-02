 
#include "ObjectEventBumpInHandlerObjectBump.hh"
#include <iostream>

ObjectEventBumpInHandlerObjectBump::ObjectEventBumpInHandlerObjectBump(Smart::InputSubject<CommObjectRecognitionObjects::CommObjectRecognitionEventBumpResult> *subject, const int &prescaleFactor)
:	ObjectEventBumpInHandlerObjectBumpCore(subject, prescaleFactor)
{
	std::cout << "constructor ObjectEventBumpInHandler\n";
}
ObjectEventBumpInHandlerObjectBump::~ObjectEventBumpInHandlerObjectBump() 
{
	std::cout << "destructor ObjectEventBumpInHandlerObjectBump\n";
}

void ObjectEventBumpInHandlerObjectBump::on_ObjectEventBumpInObjectBump(const CommObjectRecognitionObjects::CommObjectRecognitionEventBumpResult &input)
{
	
	try
	{
		RoqmeDDSTopics::RoqmeEnumContext enumContext;
		enumContext.name("ObjectBump");
		enumContext.value().push_back(input.getState().to_string());
		std::cout << "Publishing data context" << std::endl;
		enum_dw.write(enumContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}
