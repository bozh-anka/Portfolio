#pragma once
#include "Attributes.h"
#include <vector>
#include <array>
class Skills :
    public Attributes
{
    friend class Talent;
private:
    // 1athletics, 2awareness, 3ballistic, 4cunning, 5deception, 6insight, 7intimidation, 
    // 8investigation, 9leadership, 10medicine, 11presuasion, 12pilot, 13magic, 14scholar, 15stealth, 16survival, 17tech, 18weapon;
    std::array<int,18> skills {0,0,0,0,0, 0,0,0,0,0  ,0,0,0,0,0 ,0,0, 0};
    std::vector<Talent> talents;
   

public:
    Skills();
    Skills(std::string name, std::string species, int tier);
    Skills(std::array<int,18> skl, std::string name, std::string species, int tier, int str, int t, int a, int ini, int will, int i, int f);
    int const sCost[8] = { 2,6,12,20,30,42,56,72 };

    std::vector<Talent> getTalents();
    
    int getAthletics();
    int getAwareness();
    int getBallistic();
    int getCunning();
    int getDeception();
    int getInsight();
    int getIntimidation();
    int getInvestigation();
    int getLeadership();
    int getMedicine();
    int getPresuasion();
    int getPilot();
    int getMagic();
    int getScholar();
    int getStealth();
    int getSurvival();
    int getTech();
    int getWeapon();
    int getSkill(int index);
    Talent getTalent(int i);

    int matchAttribute(int skl);
    std::string matchAttributeToStr(int skl);
    operator std::string();
    friend std::ostream& operator<<(std::ostream& os, const Skills& s);

    void addTalent(Talent t);

    //skill cap is 8 for all
    void setSkill(int sk, int val);
    void Randomize();
    void applyTalents();
    int calculatePool(int sk);
    int rollPool(int sk);
};

