#pragma once
#include "Sheet.h"
#include <vector>
//This class represents the character sheet's attribute section
//It is abstract because attributes cannot exist on their own
//It inherits sheet because sheet is the first aspect of the character sheet representation
class Attributes : public Sheet {
	
private:
	//attributes
	
	// index to stat = 0 - str, 1 - tough, 2 - agil , 3- init, 4 - will, 5 - int, 6 - fell
	int attributes[7] = {1,1,1,1,1,1,1};
	void HumanAttribute(int att, int val);
	void ElfAttribute(int att, int val);
	void OrcAttributes(int att, int val);
public:
	//cost distribution
	int const aCost[12] = { 0,4,10,20,35,55,80,110,145,185,230,280 };
	Attributes();
	Attributes(std::string name, std::string species, int tier);
	Attributes(std::string name, std::string species, int tier, int str, int t, int a, int ini, int will, int i, int f);
	//They reference the race and exp when determining maximums

	void setAttribute(int att, int val);		//sets based off of incremental choices
	

	int getStrength();
	int getToughness();
	int getAgility();
	int getInitiative();
	int getWillpower();
	int getIntellect();
	int getFellowship();

	virtual void Randomize() = 0; //auto generation function
	int getAttribute(int index);
	operator std::string();
	friend std::ostream& operator<<(std::ostream& os, const Attributes& dt);

};