#include "IDgenerator.h"
#include <string>
#include <chrono>
#include <iostream>

/*
*  Klase skirtta unikalaus kodo generavimui, kuris reikalingas Vartotojui
*/
IDgenerator::IDgenerator() {}
IDgenerator::IDgenerator(int &id)
{
	id = generateID();

};
/*	
*	Algoritmas veikia naudojant chrono biblioteka. ID generuojamas pagal dabartini laika ir pristatomas sekundemis.
*	Grazinama, kaip unsigned int, nes kitaip rodomas skaicius yra neigiamas.
*/
unsigned int IDgenerator::generateID() const{
	auto now = chrono::system_clock::now();
	auto timestamp = chrono::duration_cast<chrono::seconds>(now.time_since_epoch()).count();
	return static_cast<unsigned int>(timestamp); 
}
