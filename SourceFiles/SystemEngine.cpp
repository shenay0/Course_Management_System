#include "SystemEngine.h"
#include "SystemBinarySerializer.h"

void Engine:: run(){
    try{
    SystemBinarySerializer::loadFromBinaryFile();
    }
    catch(const std::exception& e){
        std::cerr << e.what() <<std::endl;
        std::cin.clear();
    }

    UserContainer* userContainer = UserContainer::getInstance();
    if(!userContainer->find(0)){
        User* admin = new Admin();
        userContainer->createUser(admin);
    }

    CommandFactory* factory = CommandFactory::getInstance();
    
    while (true) 
	{
		string text;
		std::cin >> text;

		if(text == "exit")
		{
			break;
		}

		try
		{
			Command* command = factory->readCommand(text);
			command->execute();
			delete command;
		}
		catch (const std::exception& e){
			std::cerr << e.what() << std::endl;
			std::cin.clear();
		}
	}

   try{
    SystemBinarySerializer::saveToBinaryFile();
    }
    catch(const std::exception& e){
        std:: cerr << e.what() << std::endl;
        std::cin.clear();
    }

    UserContainer::freeInstance();
	CourseRepository::freeInstance();
	CommandFactory::freeInstance();
}