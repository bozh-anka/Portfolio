#include "Talent.h"
#include "Talent.h"
#include <string>
#include <vector>
#include <iostream>
//#include <sstream>
//Definition of talent class functions

//talent constructor takes:
//	talent name, xp cost, species prereq,   talent prereq,      attribute req,     req attr score,     affected skill,    effect (+/*),   value of effect
Talent::Talent(std::string name, int cost, std::string spe, std::string tal_r, int attr_req, int attr_req_v, int tal_af, std::string tal_ef, int tal_e)
{
	tal_name = name;							//set talent name
	if (cost > 0) {								
		this->cost = cost;						//verify non zero cost and set
	}
	else {
		std::cout << "Bad Cost" << std::endl;		//alert
	}


	species = spe;							//set species prereq
	tal_req = tal_r;							//set talent prerequisite
	this->attr_req = attr_req;					//set attribute req


	if (attr_req_v >= 0) {
		this->attr_req_v = attr_req_v;
	}											//set attribute req score, can be zero
	else {
		std::cout << "Bad Req" << std::endl;		//alert
	}


	this->tal_af = tal_af;						//set affected skill
	this->tal_ef = tal_ef;						//set effect type
	if (tal_e > 0) {
		tal_effect = tal_e;
	}											//verify and set effect value
	else {
		std::cout << "Bad Effect" << std::endl;		//alert
	}
}
//default constructor
Talent::Talent()
{
	tal_name = "-";
	cost = 0;
	species = "-";
	tal_req = "-";
	attr_req = 0;
	attr_req_v = 0;
	tal_af = 0;
	tal_ef = "-";
	tal_effect = 0;
}

//verify cost and set it
void Talent::setCost(int cost) {
	if (cost > 0) {
		this->cost = cost;
	}
	else {
		std::cout << "Bad Cost"<< std::endl;
	}
}
//set name
void Talent::setName(std::string name) {
	tal_name = name;
}
//set species requirement
void Talent::setSpeciesReq(std::string spe) {
	species = spe;
}
//set talent requirement
void Talent::setTalentReq(std::string tal_req) {
	this->tal_req = tal_req;
}

void Talent::setAttributeReq(int attr_req)
{
	this->attr_req = attr_req;					//set attribute req
}

void Talent::setAttributeVal(int attr_req_v)
{
	if (attr_req_v >= 0) {
		this->attr_req_v = attr_req_v;
	}											//set attribute req score, can be zero
	else {
		std::cout << "Bad Req" << std::endl;		//alert
	}
}

void Talent::setTalentSkill(int tal_af)
{
	this->tal_af = tal_af;						//set affected skill
}

void Talent::setTalentEffect(std::string tal_ef)
{
	this->tal_ef = tal_ef;						//set effect type	
}

void Talent::setEffectVal(int tal_e)
{
	if (tal_e > 0) {
		tal_effect = tal_e;
	}											//verify and set effect value
	else {
		std::cout << "Bad Effect" << std::endl;		//alert
	}
}
//set if talent has been used
void Talent::setApplied(bool t)
{
	applied = t;
}


// getters

bool Talent::getApplied()
{
	return applied;
}

int Talent::getCost() {
	return cost;
}
std::string Talent::getName() {
	return tal_name;
}
std::string Talent::getSpeciesReq() {
	return species;
}
std::string Talent::getTalentReq() {
	return tal_req;
}

int Talent::getAttributeReq()
{
	return attr_req;
}

int Talent::getAttributeVal()
{
	return attr_req_v;
}
//match index to name
std::string Talent::getTalentSkill()
{
	switch (tal_af) {
	case 0:
		return "Athletics";
	case 1:
		return "Awareness";
	case 2:
		return "Ballistic";
	case 3:
		return "Cunning";
	case 4:
		return "Deception";
	case 5:
		return "Insight";
	case 6:
		return "Intimidation";
	case 7:
		return "Investigation";
	case 8:
		return "Leadership";
	case 9:
		return "Medicine";
	case 10:
		return "Presuasion";
	case 11:
		return "Pilot";
	case 12:
		return "Magic";
	case 13:
		return "Scholar";
	case 14:
		return "Stealth";
	case 15:
		return "Survival";
	case 16:
		return "Technology";
	case 17:
		return "Weapon";
	default:
		return "Skill";
	}
	//switch case to return word
	
}

int Talent::getTalentSkillN()
{
	return tal_af;
}

std::string Talent::getTalentEffect()
{
	return tal_ef;
}

int Talent::getEffectVal()
{
	return tal_effect;
}
std::ostream& operator<<(std::ostream& os, const Talent& t)
{

	os << "\nTalent: " + t.tal_name + "\t"
		+ "Cost: " + std::to_string(t.cost) + "\n\n"
		+ "Prerequisites: " + "\n" + " Species Requirement - " + t.species + "\t"
		+ " Talent Requirement - " + t.tal_req + "\n"
		+ " Attribute Prerequsite: " + std::to_string(t.attr_req) + " min " + std::to_string(t.attr_req_v) + "\n"
		+ " The talent will " + t.tal_ef + " the " + std::to_string(t.tal_af) // fix to make it say word not number
		+ " skill by " + std::to_string(t.tal_effect) + "\n";
	return os;
}
Talent::operator std::string()
{
	std::string attributeN[7] = { "Strength","Toughness","Agility","Initiative","Willpower","Intelligence","Fellowship" };
	std::string dummy = "\nTalent: " + Talent::getName() + "\t"
		+ "Cost: " + std::to_string(Talent::getCost()) + "\n\n"
		+ "Prerequisites: " + "\n" + " Species Requirement - " + Talent::getSpeciesReq() + "\t"
		+ " Talent Requirement - " + Talent::getTalentReq() + "\n"
		+ " Attribute Prerequsite: " + attributeN[Talent::getAttributeReq()-1]+ " min " + std::to_string(Talent::getAttributeVal()) + "\n"
		+ " The talent will " + Talent::getTalentEffect() + " the " + Talent::getTalentSkill()
		+ " skill by " + std::to_string(Talent::getEffectVal()) + "\n\n";
		
	return dummy;
}

bool Talent::operator<(const Talent& t)
{
	if (this->cost < t.cost) {
		return true;
	}
	else {
		return false;
	}
}
