#pragma once
#include <string>
#include <iostream>
#include <ostream>

// This header file contains the outline for the talent class.
// A talent is a representation of a selectable modification to a set skill's dice pool.
// Skills are determined by the cost selection within the sheet class. 

class Talent {
	
private:
	int cost;
	std::string tal_name;							//name of the talent
	std::string species;							//species requirements
	std::string tal_req;							//talent prerequisite
	int attr_req;							//name of attribute score prerequisite
	int attr_req_v;									//minimum score of prerequisite attribute  
	int tal_af;								//skill modified by the talent
	std::string	tal_ef;								//the talent effect (plus/ mult)
	int tal_effect;									//effect value
	bool applied = false;
														 
	
public:

	//talent constructor parameters are:
	//talent name, xp cost, keyword prereq,   talent prereq,      attribute req,     req attr score,     affected skill,    effect (+/*),   value of effect
	 Talent(std::string name, int cost, std::string spe, std::string tal_r, int attr_req, int attr_req_v, int tal_af, std::string tal_ef, int tal_e);
	 Talent();
	//setters

	//set cost
	void setCost(int cost);
	//set name
	void setName(std::string name);
	//set Species Requirement
	void setSpeciesReq(std::string species);
	//set Talent Requirement
	void setTalentReq(std::string tal_req);
	//set Attribute Requirement by number
	void setAttributeReq(int attr_req);
	//set Value of the Attribute Requirement
	void setAttributeVal(int attr_req_v);
	//set The skill this talent modifies
	void setTalentSkill(int tal_af);
	//set the modification type add/multiply
	void setTalentEffect(std::string tal_ef);
	//value of the modification
	void setEffectVal(int tal_e);
	//Set true if talent has been applied to character sheet
	void setApplied(bool t);

	//getters

	//Check if talent has been applied
	bool getApplied();
	//get the talent's exp price
	int getCost();
	//get name
	std::string getName();
	//get species prerequisite
	std::string getSpeciesReq();
	//get talent prerequisite
	std::string getTalentReq();
	//get number of attribute requirement
	int  getAttributeReq();
	//get value of attribute requirement
	int getAttributeVal();
	//get the name of the skill to be modified
	std::string getTalentSkill();
	//get the index of the skill
	int getTalentSkillN();
	//get the type of modification add/multiply
	std::string getTalentEffect();
	//get the value of the modification
	int getEffectVal();
	
	//to string function for printing talent contents
	operator std::string();

	//overloaded less than operator for cost comparisons
	bool operator<(const Talent& t);
	friend std::ostream& operator<<(std::ostream& os, const Talent& dt);

};