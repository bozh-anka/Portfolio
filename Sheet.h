#pragma once
#include <string>
#include <iostream>
#include "Talent.h"

// This header file contains the outline for the Sheet class 
// It represents the top row of the character sheet
class Sheet {
	friend class Talent;

private:
	//top row details
	std::string name; //Name of player or character
	std::string species; // Character species, must be of a predetermined list can be selected from options in SelectSpecies
	int tier;
	int exp;

public:
	Sheet();
	Sheet(std::string name, std::string species, int tier);

	//Setters
	void setName(std::string name);
	void selectSpecies(std::string species); //asks for input from listed options  change to cin if needed 
	void selectTier(int tier);				//asks for input from 1 to 4 and asigns exp based on it
	void setExp(int xp);
	//Getters
	std::string getName();
	std::string getSpecies();
	int getTier(); 
	int getExp();

	virtual void Randomize() = 0;
	operator std::string();
	friend std::ostream& operator<<(std::ostream& os, const Sheet& dt);



};