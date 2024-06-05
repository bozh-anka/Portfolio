#include "Skills.h"
#include <cstdlib>
#include <Windows.h>
#include "Talent.h"
//#include <process.h>
#include <iomanip>
#include <array> 
#include "Die.h"

void Skills::setSkill(int sk, int val)
{
	if ((0 <= val && val <= 8)) {


		switch (sk)
		{
		case 0:
			skills[0] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 1:
			skills[1] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 2:
			skills[2] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 3:
			skills[3] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 4:
			skills[4] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 5:
			skills[5] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 6:
			skills[6] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 7:
			skills[7] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 8:
			skills[8] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 9:
			skills[9] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 10:
			skills[10] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 11:
			skills[11] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 12:
			skills[12] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 13:
			skills[13] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 14:
			skills[14] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 15:
			skills[15] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 16:
			skills[16] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		case 17:
			skills[17] = val;
			Sheet::setExp(Sheet::getExp() - sCost[val - 1]);
			break;
		default:
			//std::cout << "Bad input nothing set" << std::endl;
			break;
		}
		//std::cout << "Current XP " << Sheet::getExp() << std::endl;
	}
	else {
		std::cout << "Bad skill input" << std::endl;
	}
}


void Skills::Randomize()
{
	//seed set to time for alteration on each run
	

	//calculating down to desired range
	int roll = 0;
	/*Function to randomly choose skills and attributes for a character
	does not set name species and tier these must be
	set before the function is called or it will work with defaults*/
	std::cout << "   .   ";

	//randomize attributes, set them 
	for (int i = 1; i < 8; i++) {
		//int seed = _getpid(); //process id
		srand((int) time(0)+ 1);
		roll = (rand() % 8) + 1;
		//std::cout <<"Roll is "<< roll << std::endl;
		Attributes::setAttribute(i,roll);
		Sleep(800);
		std::cout << " . ";
	}
	std::cout << " . ";
	//std::cout << "SKill time"  << std::endl;
	//randomize skills, set them 
	for (int i = 1; i < 19; i++) {
		//int seed = _getpid(); //process id
		//srand(seed);
		srand((int)time(0) + 2);
		roll = (rand() % 8) + 1;
		//std::cout << "Roll is " << roll << std::endl;
		Skills::setSkill(i, roll);
		Sleep(900);
		std::cout << " . ";
	}
	
}
void Skills::applyTalents()
{
	if (!talents.empty()) {
		for (int i = 0; i < talents.size(); i++) {

			if (talents[i].getApplied() == false && talents[i].getTalentEffect() == "add") {
				/*std::string getTalentSkill();
				std::string getTalentEffect();
				int getEffectVal();*/
				talents[i].setApplied(true);
				switch (talents[i].getTalentSkillN()) {
				case 0:
					//std::cout << " changing ";
					skills[0] = skills[0] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Athletics";
				case 1:
					//std::cout << " changing ";
					skills[1] = skills[1] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Awareness";
				case 2:
					//std::cout << " changing ";
					skills[2] = skills[2] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Ballistic";
				case 3:
					//std::cout << " changing ";
					skills[3] = skills[3] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Cunning";
				case 4:
					//std::cout << " changing ";
					skills[4] = skills[4] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Deception";
				case 5:
					//std::cout << " changing ";
					skills[5] = skills[5] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Insight";
				case 6:
					//std::cout << " changing ";
					skills[6] = skills[6] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Intimidation";
				case 7:
					//std::cout << " changing ";
					skills[7] = skills[7] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Investigation";
				case 8:
					//std::cout << " changing ";
					skills[8] = skills[8] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Leadership";
				case 9:
					//std::cout << " changing ";
					skills[9] = skills[9] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Medicine";
				case 10:
					//std::cout << " changing ";
					skills[10] = skills[10] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Presuasion";
				case 11:
					//std::cout << " changing ";
					skills[11] = skills[11] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Pilot";
				case 12:
					//std::cout << " changing ";
					skills[12] = skills[12] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Magic";
				case 13:
					//std::cout << " changing ";
					skills[13] = skills[13] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Scholar";
				case 14:
					skills[14] = skills[14] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Stealth";
				case 15:
					skills[15] = skills[15] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Survival";
				case 16:
					skills[16] = skills[16] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Technology";
				case 17:
					skills[17] = skills[17] + talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Weapon";
				default:
					std::cout << "Something went wrong when applying plus talents" << std::endl;
					//return "Skill";
				}

			}
			else if (talents[i].getApplied() == false && talents[i].getTalentEffect() == "multiply")
			{
				switch (talents[i].getTalentSkillN()) {
				case 0:
					//std::cout << " changing ";
					skills[0] = skills[0] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Athletics";
				case 1:
					//std::cout << " changing ";
					skills[1] = skills[1] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Awareness";
				case 2:
					//std::cout << " changing ";
					skills[2] = skills[2] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Ballistic";
				case 3:
					//std::cout << " changing ";
					skills[3] = skills[3] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Cunning";
				case 4:
					//std::cout << " changing ";
					skills[4] = skills[4] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Deception";
				case 5:
					//std::cout << " changing ";
					skills[5] = skills[5] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Insight";
				case 6:
					//std::cout << " changing ";
					skills[6] = skills[6] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Intimidation";
				case 7:
					skills[7] = skills[7] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Investigation";
				case 8:
					skills[8] = skills[8] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Leadership";
				case 9:
					skills[9] = skills[9] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Medicine";
				case 10:
					skills[10] = skills[10] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Presuasion";
				case 11:
					skills[11] = skills[11] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Pilot";
				case 12:
					skills[12] = skills[12] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Magic";
				case 13:
					skills[13] = skills[13] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Scholar";
				case 14:
					skills[14] = skills[14] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Stealth";
				case 15:
					skills[15] = skills[15] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Survival";
				case 16:
					skills[16] = skills[16] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Technology";
				case 17:
					skills[17] = skills[17] * talents[i].getEffectVal();
					talents[i].setApplied(true);
					break;
					//return "Weapon";
				default:
					std::cout << "Something went wrong when applying plus talents" << std::endl;
					//return "Skill";
				}

			}
			else
			{
				std::cout << "Error with talent application" << std::endl;
			}
		}
	}
}

int Skills::calculatePool(int sk)
{
	if (0 <= sk <= 17) {
		return skills[sk] + Attributes::getAttribute(matchAttribute(sk));
	}
	else {
		std::cout << "Bad dice pool parameter" << std::endl;
		return 0;
	}
}

int Skills::rollPool(int sk)
{
	int pool = calculatePool(sk);
	int total = 0;
	while (pool != 0) {
		Die d = Die();
		total = total + d.Roll();
		pool--;
	}
	return total;
}





Skills::Skills():Attributes::Attributes()
{
	for (int i = 0; i < 17; i++) {
		skills[i] = 0;
	}
}
Skills::Skills(std::string name, std::string species, int tier) :Attributes::Attributes(name, species, tier) {
	for (int i = 0; i < 17; i++) {
		skills[i] = 0;
	}
}

//index specifies which skill content specifies the pt skill value
Skills::Skills(std::array<int,18> skl, std::string name, std::string species, int tier, int str, int t, int a, int ini, int will, int i, int f) :
	Attributes::Attributes(name,species,tier,str,t,a,ini,will,i,f)
{
	if (skl.size() == 18) {
		for (int i= 0; i < 18 ; i++)
		{
			setSkill(i, skl[i]);
		}

	}else {
		//std::cout << skl.size()<< std::endl;
		std::cout << "Wrong skill using default of 0" <<std::endl;

	}
}

std::vector<Talent> Skills::getTalents()
{
	return talents;
}
Talent Skills::getTalent(int i) {
	if ((!talents.empty())&&(0 <= i <= talents.size())) {
		return talents[i];
	}
	else {
		//std::cout << "No talents" << std::endl;
	}
}
int Skills::getAthletics()
{
	return skills[0];
}

int Skills::getAwareness()
{
	return skills[1];
}

int Skills::getBallistic()
{
	return skills[2];
}

int Skills::getCunning()
{
	return skills[3];
}

int Skills::getDeception()
{
	return skills[4];
}
int Skills::getInsight()
{
	return skills[5];
}
int Skills::getIntimidation()
{
	return skills[6];
}
int Skills::getInvestigation()
{
	return skills[7];
}
int Skills::getLeadership()
{
	return skills[8];
}
int Skills::getMedicine()
{
	return skills[9];
}
int Skills::getPresuasion()
{
	return skills[10];
}
int Skills::getPilot()
{
	return skills[11];
}
int Skills::getMagic()
{
	return skills[12];
}
int Skills::getScholar()
{
	return skills[13];
}
int Skills::getStealth()
{
	return skills[14];
}
int Skills::getSurvival()
{
	return skills[15];
}
int Skills::getTech()
{
	return skills[16];
}
int Skills::getWeapon()
{
	return skills[17];
}
int Skills::getSkill(int index)
{
	if (index >= 0 && index <= std::size(skills)) {
		return skills[index];
	}
	else {
		std::cout << "Bad skill index" << std::endl;
		return 0;
	}
}

// "0 - Athletics", "1 - Awareness", "2 - Ballistic", "3 - Cunning", "4 - Deception", "5 - Insight",
// "6 - Intimidation", "7 - Investigation", "8 - Leadership", "9 - Medicine", "10 - Presuasion",
// "11 - Pilot", "12 - Magic", "13 - Scholar", "14 - Stealth", "15 - Survival", "16 - Tech", "17 - Weapon"

//0 - STR   1 - TOUGH   2 - AGIL  3 - INIT  4 - WILL   5 - INT  6 - FELL
int Skills::matchAttribute(int skl)
{
	switch (skl) {
	case 0:
		return 0; //Athletics is Strength
	case 1:
		return 5; //Awareness is Intelligence
	case 2:
		return 2; //Ballistic is Agility
	case 3:
		return 6; //Cunning is Fellowship
	case 4:
		return 6; //Deception is Fellowship
	case 5:
		return 6; //Insight is Fellowship
	case 6:
		return 4; //Intimidation is Willpower
	case 7:
		return 5; //Investigation is Intelligence
	case 8:
		return 4; //Leadership is Willpower
	case 9:
		return 5; //Medicine is Intelligence
	case 10:
		return 6; //Presuasion is Fellowship
	case 11:
		return 2; //Pilot is Agility
	case 12:
		return 4; //Magic is Willpower
	case 13:
		return 5; //Scholar is Intelligence
	case 14:
		return 2; //Stealth is Agility
	case 15:
		return 4; //Survival is Willpower
	case 16:
		return 5; //Technology is Intelligence
	case 17:
		return 3; //Weapon is Initiative
	}
}

std::string Skills::matchAttributeToStr(int skl)
{
	switch (skl) {
	case 0:
		return "Strength"; //Athletics is Strength
	case 1:
		return "Intelligence"; //Awareness is Intelligence
	case 2:
		return "Agility"; //Ballistic is Agility
	case 3:
		return "Fellowship"; //Cunning is Fellowship
	case 4:
		return "Fellowship"; //Deception is Fellowship
	case 5:
		return "Fellowship"; //Insight is Fellowship
	case 6:
		return "Willpower"; //Intimidation is Willpower
	case 7:
		return "Intelligence"; //Investigation is Intelligence
	case 8:
		return "Willpower"; //Leadership is Willpower
	case 9:
		return "Intelligence"; //Medicine is Intelligence
	case 10:
		return "Fellowship"; //Presuasion is Fellowship
	case 11:
		return "Agility"; //Pilot is Agility
	case 12:
		return "Willpower"; //Magic is Willpower
	case 13:
		return "Intelligence"; //Scholar is Intelligence
	case 14:
		return "Agility"; //Stealth is Agility
	case 15:
		return "Willpower"; //Survival is Willpower
	case 16:
		return "Intelligence"; //Technology is Intelligence
	case 17:
		return "Initiative"; //Weapon is Initiative
	}
}

Skills::operator std::string() {

	
	std::string dummy;
	if (!getTalents().empty()) {
		std::cout << "The talent list is: " << std::endl;

		dummy = dummy + "\nTalents: \n";
		for (int i = 0; i < getTalents().size(); i++) {
			dummy = dummy + std::string(getTalents()[i]) + "\n";
		}
	}
	dummy = dummy + Attributes::operator std::string() + "\n\nSkills:" +
		"\nAthletics\tAwareness\tBallistic\tCunning\t\tDeception\tInsight\n"; //"\t\tIntimidation\tInvestigation\n";
	for (int i = 0; i < 6; i++) {
		dummy = dummy + std::to_string(skills[i]) + "\t\t";
	}
	dummy = dummy + "\nIntimidation\tInvestigation\tLeadership\tMedicine\tPresuasion\tPilot\n";// "\t\tMagic\t\tScholar\t\tStealth\t\tSurvival\tTech\t\tWeapon\n";
	for (int i = 6; i < 12; i++) {
		dummy = dummy + std::to_string(skills[i]) + "\t\t";
	}
	dummy = dummy + "\nMagic\t\tScholar\t\tStealth\t\tSurvival\tTech\t\tWeapon\n";
	for (int i = 12; i < 18; i++) {
		dummy = dummy + std::to_string(skills[i]) + "\t\t";
	}
	

	return dummy;
}
void Skills::addTalent(Talent t)
{
	
	if (t.getCost() <= Sheet::getExp()) {
		talents.push_back(t);
		//std::cout << "Current XP " << Sheet::getExp() << std::endl;
		//  std::cout << s.getTalents()[0]<<std::endl;
		//  std::cout << "Spending " << tBank[i].getCost() << " on a talent" << std::endl;
		Sheet::setExp(Sheet::getExp() - t.getCost());
		//std::cout << "Post talent XP " << Sheet::getExp() << std::endl;
	}
	else {
		std::cout << "No XP for talent. " << std::endl;
	}
	//potential check if there already??
	//can we double take?
	//no cost check bc the agents check on their own
}
std::ostream& operator<<(std::ostream& os, const Skills& s) {
	
	os << "\nSkills:\nAthletics" << "\tAwareness" << "\tBallistic\t" << 
		"Cunning\t\t" <<  "Deception\t"  "Insight\t" << std::endl;
	for (int i = 0; i < 6; i++) {
		os << std::to_string(s.skills[i]) << "\t\t";
	}
	os << "\nIntimidation\tInvestigation\tLeadership\tMedicine\tPresuasion\tPilot" << std::endl;
	for (int i = 6; i < 12; i++) {
		os <<std::to_string(s.skills[i]) << "\t\t";
	}
	os << "\nMagic\t\tScholar\t\tStealth\t\tSurvival\tTech\t\tWeapon" << std::endl;
	for (int i = 12; i < 18; i++) {
		os << std::to_string(s.skills[i]) << "\t\t";
	}

	os << std::endl << "\nTalents: \n\n";
	for (int i = 0; i < s.talents.size(); i++) {
		os << s.talents[i] << std::endl;
	}
	return os;
}