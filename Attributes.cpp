#include "Talent.h"
#include "Attributes.h"
#include <string>
#include <vector>
#include <iostream>
//#include <sstream>
//#include <algorithm>
#include <iomanip>



Attributes::Attributes()
{
	for (int i = 0; i < 6; i++) {
		attributes[i] = 1;
	}

}

Attributes::Attributes(std::string name, std::string species, int tier):Sheet::Sheet(name,species,tier)
{

	for (int i = 0; i < 6; i++) {
		attributes[i] = 1;
	}
}

Attributes::Attributes(std::string name, std::string species, int tier, int str, int t, int a, int ini, int will, int i, int f):
	Sheet::Sheet(name, species, tier)
{
	int check = str * t * a * ini * will * i * f;
	if (getSpecies() == "Human" && check > 0) {
		Attributes::HumanAttribute(1, str);
		Attributes::HumanAttribute(2, t);
		Attributes::HumanAttribute(3, a);
		Attributes::HumanAttribute(4, ini);
		Attributes::HumanAttribute(5, will);
		Attributes::HumanAttribute(6, i);
		Attributes::HumanAttribute(7, f);
	}
	else if (getSpecies() == "Elf" && check > 0) {
		Attributes::ElfAttribute(1, str);
		Attributes::ElfAttribute(2, t);
		Attributes::ElfAttribute(3, a);
		Attributes::ElfAttribute(4, ini);
		Attributes::ElfAttribute(5, will);
		Attributes::ElfAttribute(6, i);
		Attributes::ElfAttribute(7, f);
	}
	else if (getSpecies() == "Orc" && check > 0) {
		Attributes::OrcAttributes(1, str);
		Attributes::OrcAttributes(2, t);
		Attributes::OrcAttributes(3, a);
		Attributes::OrcAttributes(4, ini);
		Attributes::OrcAttributes(5, will);
		Attributes::OrcAttributes(6, i);
		Attributes::OrcAttributes(7, f);
	}

}

void Attributes::setAttribute(int att, int val)
{
	
	if (getSpecies() == "Human" && val > 0) {
		Attributes::HumanAttribute(att, val);
	}
	else if (getSpecies() == "Elf" && val > 0) {
		Attributes::ElfAttribute(att, val);
	}
	else if (getSpecies() == "Orc" && val > 0) {
		Attributes::OrcAttributes(att,val);
	}
	else {
		std::cout << "Bad input fix your value using 1 as default" << std::endl;
		Attributes::setAttribute(att, 1);
	}
}
void Attributes::OrcAttributes(int att, int val) {
	//limits { 12, 12, 7, 7, 8, 7, 7 };
	switch (att)
	{
	case 1:
		if (val <= 12) {
			attributes[0] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			// 1st point is free 
			std::cout << "Bad input setting str to 1" << std::endl;
			attributes[0] = 1;

		}
		break;
	case 2:
		if (val <= 12) {
			attributes[1] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting t to 1" << std::endl;
			attributes[1] = 1;

		}
		break;
	case 3:
		if (val <= 7) {
			attributes[2] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting agil to 1" << std::endl;
			attributes[2] = 1;

		}
		break;
	case 4:
		if (val <= 7) {
			attributes[3] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting init to 1" << std::endl;
			attributes[3] = 1;

		}
		break;
	case 5:
		if (val <= 8) {
			attributes[4] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting will to 1" << std::endl;
			attributes[4] = 1;

		}
		break;
	case 6:
		if (val <=7) {
			attributes[5] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting int to 1" << std::endl;
			attributes[5] = 1;

		}
		break;
	case 7:
		if (val <= 7) {
			attributes[6] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting fell to 1" << std::endl;
			attributes[6] = 1;

		}
		break;
	default:
		std::cout << "Bad input nothing set for Orc" << std::endl;
		break;
	}
}
void Attributes::ElfAttribute(int att, int val) {
	//check if the value exceeds maximum if not, set value and subtract cost
	//elf limits { 7,7,12,12,12,10,6 };
	switch (att)
	{
	case 1:
		if (val <= 7) {
			attributes[0] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			// 1st point is free 
			std::cout << "Bad input setting str to 1" << std::endl;
			attributes[0] = 1;

		}
		break;
	case 2:
		if (val <= 7) {
			attributes[1] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting t to 1" << std::endl;
			attributes[1] = 1;

		}
		break;
	case 3:
		if (val <= 12) {
			attributes[2] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting agil to 1" << std::endl;
			attributes[2] = 1;

		}
		break;
	case 4:
		if (val <= 12) {
			attributes[3] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting init to 1" << std::endl;
			attributes[3] = 1;

		}
		break;
	case 5:
		if (val <= 12) {
			attributes[4] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting will to 1" << std::endl;
			attributes[4] = 1;

		}
		break;
	case 6:
		if (val <= 10) {
			attributes[5] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting int to 1" << std::endl;
			attributes[5] = 1;

		}
		break;
	case 7:
		if (val <= 6) {
			attributes[6] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting fell to 1" << std::endl;
			attributes[6] = 1;

		}
		break;
	default:
		std::cout << "Bad input nothing set for Elf" << std::endl;
		break;
	}
}
//This can be optimized
void Attributes::HumanAttribute(int att, int val)
{
	//check if the value exceeds maximum if not, set value and subtract cost
	switch (att)
	{
	case 1:
		if (val <= 8) {
			attributes[0] = val;
			setExp(getExp() - aCost[val - 1]);
			//std::cout << "Attribute set is " << attributes[0] << std::endl;
		}
		else {
			// 1st point is free 
			std::cout << "Bad input setting str to 1" << std::endl;
			attributes[0] = 1;
			
		}
		break;
	case 2:
		if (val <= 8) {
			attributes[1] = val;
			setExp(getExp() - aCost[val - 1]);
			
		}
		else {
			std::cout << "Bad input setting t to 1" << std::endl;
			attributes[1] = 1;
			
		}
		break;
	case 3:
		if (val <= 8) {
			attributes[2] = val;
			setExp(getExp() - aCost[val - 1]);
			
		}
		else {
			std::cout << "Bad input setting agil to 1" << std::endl;
			attributes[2] = 1;
			
		}
		break;
	case 4:
		if (val <= 8) {
			attributes[3] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting init to 1" << std::endl;
			attributes[3] = 1;

		}
		break;
	case 5:
		if (val <= 8) {
			attributes[4] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting will to 1" << std::endl;
			attributes[4] = 1;

		}
		break;
	case 6:
		if (val <= 8) {
			attributes[5] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting int to 1" << std::endl;
			attributes[5] = 1;

		}
		break;
	case 7:
		if (val <= 8) {
			attributes[6] = val;
			setExp(getExp() - aCost[val - 1]);

		}
		else {
			std::cout << "Bad input setting fell to 1" << std::endl;
			attributes[6] = 1;

		}
		break;
	default:
		std::cout << "Bad input nothing set for Human" << std::endl;
		break;
	}
	//std::cout << "Current XP " << Sheet::getExp() << std::endl;
}
int Attributes::getStrength()
{
	return attributes[0];
}

int Attributes::getToughness()
{
	return attributes[1];
}

int Attributes::getAgility()
{
	return attributes[2];
}
int Attributes::getInitiative() {
	return attributes[3];
}
int Attributes::getWillpower()
{
	return attributes[4];
}

int Attributes::getIntellect()
{
	return attributes[5];
}

int Attributes::getFellowship()
{
	return attributes[6];
}

int Attributes::getAttribute(int index) {
	return attributes[index];
}
Attributes::operator std::string() {
	std::string dummy;
	dummy = Sheet::operator std::string()+ "\nAttributes:\nStrength\tToughness\tAgility\t\tInitiative\tWillpower\tIntellect\tFellowship\n"
		+ std::to_string(getStrength()) + "\t\t" + std::to_string(getToughness()) + "\t\t" + std::to_string(getAgility())
		+ "\t\t" + std::to_string(getInitiative()) + "\t\t" + std::to_string(getWillpower()) + "\t\t"
		+ std::to_string(getIntellect()) + "\t\t" + std::to_string(getFellowship());
	return dummy;
}

std::ostream& operator<<(std::ostream& os, const Attributes& at) {
	os <<"Attributes:\nStrength\tToughness\tAgility\tInitiative\tWillpower\tIntellect\tFellowship\n"
		<< std::setw(5) << std::to_string(at.attributes[0]) << std::setw(5) << std::to_string(at.attributes[1])
		<< std::setw(5) << std::to_string(at.attributes[2]) << std::setw(5) << std::to_string(at.attributes[3])
		<< std::setw(5) << std::to_string(at.attributes[4]) << std::setw(5) << std::to_string(at.attributes[5])
		<< std::setw(5) << std::to_string(at.attributes[6]) << std::endl;
	return os;
}