#include "Sheet.h"


Sheet::Sheet()
{
	name = "Tav";
	species = "Human";
	tier = 1;
	exp = 1000;
}

Sheet::Sheet(std::string name, std::string species, int tier)
{
	this->name = name;

	if (species == "human") {
		this->species = "Human";
	}
	else if (species == "orc") {
		this->species = "Orc";
	}
	else if (species == "elf") {
		this->species = "Elf";
	}
	else {
		this->species = "Human";
		std::cout << "Wrong species input, reset to human" << std::endl;
	}

	switch (tier)
	{
	case 1:
		this->exp = 1000;
		this->tier = 1;
		break;
	case 2:
		this->exp = 2000;
		this->tier = 2;
		break;
	case 3:
		this->exp = 3000;
		this->tier = 3;
		break;
	case 4:
		this->exp = 4000;
		this->tier = 4;
		break;
	default:
		std::cout << "The highest tier is 4, tier exceeded setting to 1." << std::endl;
		this->exp = 1000;
		this->tier = 1;
		break;
	}
}

void Sheet::setName(std::string name)
{
	this->name = name;
}

void Sheet::selectSpecies(std::string species)
{
	if (species == "human") {
		this->species = "Human";
	}
	else if (species == "orc") {
		this->species = "Orc";
	}
	else if (species == "elf") {
		this->species = "Elf";
	}
	else {
		this->species = "Human";
		std::cout << "Wrong species input, reset to human" << std::endl;
	}
}

void Sheet::selectTier(int tier)
{
	switch (tier)
	{
	case 1:
		this->exp = 1000;
		this->tier = 1;
		break;
	case 2:
		this->exp = 2000;
		this->tier = 2;
		break;
	case 3:
		this->exp = 3000;
		this->tier = 3;
		break;
	case 4:
		this->exp = 4000;
		this->tier = 4;
		break;
	default:
		std::cout << "The highest tier is 4, tier exceeded setting to 1." << std::endl;
		this->exp = 1000;
		this->tier = 1;
		break;
	}
}

void Sheet::setExp(int xp)
{
	if (xp >= 0) {
		exp = xp;
	}
	else {
		std::cout << "Bad input xp not set" << std::endl;
	}
}

std::string Sheet::getName()
{
	return name;
}

std::string Sheet::getSpecies()
{
	return species;
}

int Sheet::getTier()
{
	return tier;
}

int Sheet::getExp()
{
	return exp;
}

std::ostream& operator<<(std::ostream& os, const Sheet& s)
{
	os << "Character Sheet\nName: " + s.name + "\tSpecies: " + s.species
		+ "\nTier: " + std::to_string(s.tier) +"\tCurrent XP: " + std::to_string(s.exp);
	return os;
}

Sheet::operator std::string() {
	std::string dummy = "Character Sheet\nName: " + getName() + "\tSpecies: " + getSpecies()
		+ "\nTier: " + std::to_string(getTier()) + "\tCurrent XP: " + std::to_string(getExp())+"\n";
	return dummy;
}