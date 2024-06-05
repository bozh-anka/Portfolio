// SeniorProject_BGK.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include "Talent.h"
#include "Sheet.h"
#include "Attributes.h"
#include "Skills.h"
#include <sstream>
#include <vector>
#include <stack>
#include <cstdlib> 
#include <queue>
#include <iomanip>
#include <algorithm>

/*//For running through a command prompt window 
#include "/Users/bozha/source/repos/SeniorProject_BGK/Skills.h"
#include "/Users/bozha/source/repos/SeniorProject_BGK/Skills.cpp"
#include "/Users/bozha/source/repos/SeniorProject_BGK/Attributes.h"
#include "/Users/bozha/source/repos/SeniorProject_BGK/Attributes.cpp"
#include "/Users/bozha/source/repos/SeniorProject_BGK/Sheet.h"
#include "/Users/bozha/source/repos/SeniorProject_BGK/Sheet.cpp"
#include "/Users/bozha/source/repos/SeniorProject_BGK/Die.h"
#include "/Users/bozha/source/repos/SeniorProject_BGK/Die.cpp"
#include "/Users/bozha/source/repos/SeniorProject_BGK/Talent.h"
#include "/Users/bozha/source/repos/SeniorProject_BGK/Talent.cpp"
//*/
//tree data structure definition
//Talent trees are a straight downward thread, there is only one child 
struct Node {
    Talent tal;
    Node *left;
   
    Node(Talent talen, Node* l) {
        tal = talen;
        left = l;
    }
};


//Function that builds a forest out of the talent bank, expects vector of talents
std::vector<std::stack<Node>>forestBuilder(std::vector<Talent>& t) {
  
    // Add talents to tree stack until a new no prerequisite talent is met 
    //Process the vector backwards create leaf node first until root is found and added
    //Start new stack after adding root for next tree's leaf 
    
    //create the vector for the stacks, create push empty stack into vector rootNumber amount of times

    int rootNumber = 0;
    int stackIndex = 0;
    std::vector<std::stack<Node>> forest;
    for (int i = 0; i < t.size(); i++) {
        if (t[i].getTalentReq() == "-") {
            rootNumber++;
           // std::cout << "RootNumber is " << rootNumber << std::endl;
        }
    }

    while (rootNumber > 0) {
        rootNumber--;
        std::stack<Node> stack;
        forest.push_back(stack);
    }
    for (int i = t.size()-1; i >= 0 ; i--) {
        Node n = Node(t[i], nullptr);
       
        if (!forest[stackIndex].empty()) {//if the current stack isnt empty assign top of stack as child of current
            n.left = &forest[stackIndex].top();

        }
       
        forest[stackIndex].push(n);
        if (t[i].getTalentReq() == "-") {
            stackIndex++;
        }
    }
    return forest;
}

//Expects vector of trees represented by stacks and char sheet. 
// Prune the forest from trees we dont match talent requirements for
void forestCutter(std::vector<std::stack<Node>> forest, Skills s) {
    for (int i = 0; i < forest.size() - 1; i++) {
            //if the talent doesnt match sheet species or if attribute requirement is not met 
        if ((forest[i].top().tal.getSpeciesReq() == s.Sheet::getSpecies() ^ forest[i].top().tal.getSpeciesReq() == "-") 
            && forest[i].top().tal.getAttributeVal() <= s.getAttribute(forest[i].top().tal.getAttributeReq() - 1)) {
            //std::cout << "KEEPING " << forest[i].tal.getName() <<std::endl;

        }
        else {
           // std::cout << "Removing " << forest[i].tal.getName() << " Because race req is " << forest[i].tal.getSpeciesReq() 
             //   << " And sheet says we have " << s.getSpecies() << " or because attributes compare like: "<<std::endl;
           // std::cout << forest[i].tal.getAttributeVal() << " <=" << s.getAttribute(forest[i].tal.getAttributeReq()) << std::endl;
            forest.erase(forest.begin() + i);
            //remove the unapplicable talent
        }
    }
}

//Prunes away trees that do not concern the preffered attribute
std::stack<std::stack<Node>>PreferenceSort(int attrP, std::vector<std::stack<Node>> f , Skills s) { //stack here is for the roots only
    std::stack<std::stack<Node>> multi;
    //std::stack<std::stack<Node>> add; 
    
    
    //we might need to divide roots and full node storage into two somehow
   // while (!f.empty()) 
    for (int i = 0; i < f.size();i++) {
        //dont forget to check if reference isnt empty 
       
        //Talent Attributes are not indexed 
            if (f[i].top().tal.getAttributeReq() - 1 != attrP) {
               // std::cout << " Removing " << f[i].top().tal.getName() << " " << f[i].top().tal.getAttributeReq() - 1 << " Is NOT  " << attrP << std::endl;
                f[i].pop();
               
                continue;
            }
            else {
                multi.push(f[i]);
            }
        
       /* if (f[i].top().tal.getTalentEffect() == "multiply") {
           // std::cout << " Adding " << f[i].top().tal.getName() << " " << f[i].top().tal.getAttributeReq() - 1 << " Is " << attrP << std::endl;
            multi.push(f[i]);
            f[i].pop();
            
        }
        else if (f[i].top().tal.getTalentEffect() == "add") {
          //  std::cout << " Adding " << f[i].top().tal.getName() << " " << f[i].top().tal.getAttributeReq() - 1 << " Is " << attrP << std::endl;
            add.push(f[i]);
            f[i].pop();
        }*/
     }

    //while (!add.empty()) {
    //    multi.push(add.top());
        //add.pop();
   // }
    
    return multi;
}

//Breadth First Search - Traverses Skill Tree and checks if all prerequisites are met before selecting the talent and continuing
std::stack<Talent> BFS(Node t, Skills s) {

    std::stack<Talent> sel;
    std::queue<Node> q;
    q.push(t);
    Talent tal = Talent();
    Node current = Node(tal, nullptr);
    while (q.size() > 0) {

        //std::cout << " Tree traversing " << std::endl;
        current.tal = q.front().tal;
        current.left = q.front().left;
        q.pop();
        if (current.tal.getCost() < s.getExp() &( current.tal.getSpeciesReq() == s.getSpecies() || current.tal.getSpeciesReq() == "-")
            & current.tal.getAttributeVal() <= s.getAttribute(current.tal.getAttributeReq() - 1)) {
            sel.push(current.tal);
          //  std::cout << " Adding " << current.tal.getName() << std::endl;
        }
        if (current.left != nullptr) {
            q.push(*current.left);
           // std::cout << " Pushing " << current.left -> tal.getName() << std::endl;
        }
        

       
    }
    return sel;
}

//Quality algorithm - Selects talents from the talent bank that maximize only preffered skill (maximize = false) or collects all talents
//that modify the attribute associated with preffered skill (maximize = true).
std::vector<Talent> Quality(int skl, Skills s, std::vector<Talent>& talentBank, bool maximize) { //boolean refers to if we want tallents for skills with same attribute as preference skill

    //represent the talent bank talents as trees based on talent prerequisites 
    //double output creates an instance of all nodes from all trees and holds a stack of references to each tree's root
    std::vector<std::stack<Node>> plants = forestBuilder(talentBank);
    std::vector<Talent> selected;
    std::stack<Talent> dummy;
    std::stack<std::stack<Node>> treePool;
    forestCutter(plants, s);
    int stopControl = -1;
    //preference sort takes stacks modify it so it takes the vector of stacks and removes stacks for the wrong attrib making the vector shorter
    // then we go call bfs to select 


    
    treePool = PreferenceSort(s.matchAttribute(skl), plants, s);
    

    ///= PreferenceSort(s.matchAttribute(skl), plants, s); //this used to be troots the func is edited to transfer vec to stack needs fixing
   // std::cout << treePool.size() << "is the number of trees! " << std::endl;
    //while ((talmax != 0) & !treePool.empty() & stopControl !=0)
   while (!treePool.empty() )
   {
        if (treePool.top().top().tal.getTalentSkillN() == skl) { //if desired traverse tree

            //error control to be deleted
            try { dummy = (BFS(treePool.top().top(),s)); } 
            catch (int err) {
             //   std::cout << "Caught an error" << std::endl;
                stopControl = err;
            }
            //std::cout << "Adding Talent " << treePool.top().top().tal.getName();
            while (!dummy.empty()) {
                selected.push_back(dummy.top());
               // std::cout << "Adding Talent " << dummy.top().getName();
                dummy.pop();
            }
           // selected.insert(selected.end(), dummy.begin(), dummy.end());
            
            //talmax--;
        }
        else if (maximize) {
            try { dummy = (BFS(treePool.top().top(), s)); }
            catch (int err) {
             //   std::cout << "Caught an error" << std::endl;
                stopControl = err;
            }
            
            while (!dummy.empty()) {
               // std::cout << "Adding Talent " << dummy.top().getName();
                selected.push_back(dummy.top());
                dummy.pop();
            }
            //selected.insert(selected.end(), dummy.begin(), dummy.end());
           
           // talmax--;
        }
        else {
         //   std::cout << "Not Adding Talent ";
           
        }
        treePool.pop();
    }
    return selected;
    //return selected;
}

//Partition function for Quicksort
int Partition(std::vector<Talent>& t, int start, int end) {

    int pivot = end; //last element taken as a pivot
    int j = start; //set j to start of vector
    for (int i = start; i < end; ++i) {
        //if current element is less than pivot, make current element first
        if (t[i] < t[pivot]) {
            std::swap(t[i], t[j]);
            ++j; // iterate j 
        }
    }
    std::swap(t[j], t[pivot]);
    return j;

}

//Quicksort
void Quicksort(std::vector<Talent>& t, int start, int end) {

    if (start < end) {
        int p = Partition(t, start, end);
        Quicksort(t, start, p - 1);
        Quicksort(t, p + 1, end);
    }

}

//Checks if talent prerequisites are met.
bool talPrereq(Talent t, Skills s) {
    if (t.getTalentReq() == "-") {
        return true;
    }
    else if (!s.getTalents().empty()) {
        //check if talent in s is prereq for t 
        for (int i = 0; i < s.getTalents().size() - 1; i++) {
            if (t.getTalentReq() == s.getTalents()[i].getName()) {
                return true;
            }
        }
        return false;
    }
    else {
        return false;
    }
}

//Checks if attribute prerequisites are met.
bool attPrereq(Talent t, Skills s) {
    if (t.getAttributeReq() != 0 && t.getAttributeVal() <= s.getAttribute(t.getAttributeReq() - 1)) {
        //wtf does this do
        return true;
    }
    else {
        return false;
    }
}

//Checks if character species matches talent requirement
bool hasSpecies(Talent t, Skills s) {
    if (t.getSpeciesReq() == "-") {
       // std::cout << "Talent species req is none \t";
        return true;
    }
    else if (t.Talent::getSpeciesReq().compare(s.Sheet::getSpecies())==0) {
        //std::cout << "Talent req = " << t.Talent::getSpeciesReq() << "Sheet stat = " << s.Sheet::getSpecies();
        return true;
    }
    else {
        return false;
    }
}

//Removes talents that do not fit the character stats
void PrereqSort(std::vector<Talent> t, Skills s) {

    for (int i = 0; i < t.size(); i++) {
        if (!(talPrereq(t[i], s) & attPrereq(t[i], s) & hasSpecies(t[i], s))) {
          //  std::cout << "FIXING " << std::endl;
            t.erase(t.begin()+i);
        }
    }

}
//Quantity algorithm, selects the highest possible amount of applicable talents
std::vector<Talent> Quantity(std::vector<Talent> tBank, Skills s) {
    /* take the sorted list check each item for other talent prerequisites, move those items to the back.
    Once the talents are sorted, take top element and verify prerequisites.
    If the prerequisites are met and funds allow, select talent.
    Subtract it’s cost from the total xp.
    If insufficient funds, quit selection.
    Repeat until all are processed or funds become insufficient.
    Return the selected talents.
*/
    std::vector<Talent> tal;
    PrereqSort(tBank, s);
    Quicksort(tBank, 0, tBank.size() - 1);
    for (int i = 0; i < tBank.size(); i++) {
        if ((talPrereq(tBank[i], s) & attPrereq(tBank[i], s) & hasSpecies(tBank[i], s))) {
            tal.push_back(tBank[i]);
           // std::cout << " Adding talent " << tBank[i].getName() << std::endl;
        }
    }
    return tal;
}

//Generate talent bank from cvs file, Talents must be in hierarchical order Parent - Child - Grandchild
std::vector<Talent> talentMaker() {
    std::ifstream file;
    file.open("TalentBank.csv");
    if (file.fail()) {
        std::cout << "Error opening file";
        exit(0);
    }
    std::string line;
    getline(file, line);

    std::string name = "default";
    int cost = 0;
    std::string keyword = "default";
    std::string t_req = "default";
    int attr_req = 0;
    int attr_req_v = 0;
    int tal_skill = 0;
    std::string	tal_skill_ef = "default";
    int tal_ef_v = 0;

    std::vector<Talent> talents;
    while (getline(file, line)) {
        //std::cout << line << std::endl;

        std::stringstream          lineStream(line);
        std::string                cell;

        std::getline(lineStream, cell, ',');
        name = cell;
        //std::cout << name + " ";

        std::getline(lineStream, cell, ',');
        cost = stoi(cell);
        //std::cout << cost + " ";

        std::getline(lineStream, cell, ',');
        keyword = cell;
        //std::cout << keyword + " ";

        std::getline(lineStream, cell, ',');
        t_req = cell;
        //std::cout << t_req + " ";

        std::getline(lineStream, cell, ',');
        attr_req = stoi(cell);
        //std::cout << attr_req+ " ";

        std::getline(lineStream, cell, ',');
        attr_req_v = stoi(cell);
        //std::cout << attr_req_v + " ";

        std::getline(lineStream, cell, ',');
        tal_skill = stoi(cell);
        //std::cout << tal_skill + " ";

        std::getline(lineStream, cell, ',');
        tal_skill_ef = cell;
        //std::cout << tal_skill_ef + " ";

        std::getline(lineStream, cell, ',');
        tal_ef_v = stoi(cell);
        //std::cout << tal_ef_v + " " << std::endl;
        //std::cout << std::endl;

        Talent test = Talent(name, cost, keyword, t_req, attr_req, attr_req_v, tal_skill, tal_skill_ef, tal_ef_v);
        // std::cout << test << std::endl;
        talents.push_back(test);
        lineStream.flush();
    }
    file.close();
    return talents;
}

//User interactive console output for creating the character sheet
Skills SheetIO(std::vector<Talent> talentBank) {
    std::cout << "What is your character's name? " << std::endl;
    std::string name;
    std::cin >> name;

    std::cout << "What is your character's species? The options are human, elf, orc" << std::endl;
    bool correct = false;
    std::string species;
    while (!correct) {
        std::cout << "Type your choice: " << std::endl;
        std::cin >> species;
        std::transform(species.begin(), species.end(), species.begin(),
            [](unsigned char c) { return std::tolower(c); });
        if (species == "human" || species == "elf" || species == "orc") {
            correct = true;
            continue;
        }
    }
    correct = false;
    int tier;
    std::cout << "\nSelect tier from 1 to 4?" << std::endl;

    while (!correct) {

        while (!(std::cin >> tier)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input is not a number." << std::endl;
        }
        //std::cin >> tier;
        if (1 <= (int) tier && (int) tier <= 4) {
            correct = true;
            continue;
        }
        std::cout << "Tier must be from 1 to 4" << std::endl;
    }
    correct = false;
    std::cout << "Will you like to manually select attributes and skills? y/n";
    char answ;
    Skills sheet = Skills(name, species, tier);
    while (!correct) {
        std::cin >> answ;
        if ((char)tolower(answ) == 'n') {
            correct = true;
            std::cout << "Generating" << std::endl;
            sheet.Randomize();
        }
        else if ((char)tolower(answ) == 'y') {
            correct = true;
            //insert input options for both stat arrays add them to sheet somehow idk set funcs
            std::cout << "Inser desired attributes in order" << std::endl;
            int attributes[7];
            std::string attributeN[7] = { "Strength","Toughness","Agility","Initiative","Willpower","Intelligence","Fellowship" };
            for (int i = 0; i < 7; i++) {
                std::cout << attributeN[i] << " will be: ";
                //std::cin >> attributes[i];
                while (!(std::cin >> attributes[i])) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Input is not a number." << std::endl;
                }
                sheet.setAttribute(i + 1, attributes[i]);
            }
           // std::cout << "Invalid input will be set as the default value of 1" << std::endl;
            system("CLS");
            std::cout << "Insert desired skills in the order: " << std::endl;
            int skills[18];
            std::string snames[18] = { "Athletics","Awareness","Ballistic","Cunning","Deception",
                "Insight","Intimidation","Investigation","Leadership","Medicine","Presuasion","Pilot",
                "Magic","Scholar","Stealth","Survival","Tech","Weapon" };
            for (int i = 0; i < 18; i++) {
                std::cout << snames[i] << " will be: ";
                //std::cin >> skills[i];
                while (!(std::cin >> skills[i])) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Input is not a number." << std::endl;
                }
                sheet.setSkill(i, skills[i]);
                std::cout << std::endl;
            }
           // std::cout << "Invalid input will be set as the default value of 0" << std::endl;
        }
        else {
            std::cout << "Answer must be y or n" << std::endl;
        }
        // std::cout << "Tier must be from 1 to 4" << std::endl;
    }
    system("CLS");
    correct = false;
    std::cout << std::string(sheet) << std::endl;
    system("PAUSE");

    //ask for alg preference if qual keep it in a loop for several selections with sentinel value 
    bool qualtime = false;
    std::cout << "Will you like to maximize talents? y/n" << std::endl;
    std::vector<Talent> tals;
    while (!correct) {
        std::cin >> answ;
        if (tolower(answ) == 'n') {
            correct = true;
            qualtime = true;
            continue;
        }
        else if (tolower(answ) == 'y') {
            correct = true;
            tals = Quantity(talentBank, sheet);

            continue;
        }
        else {
            std::cout << "Answer must be y or n" << std::endl;
        }

    }
    if (qualtime) {
        // "0 - Athletics, 1 - Awareness, 2 - Ballistic, 3 - Cunning, 4 - Deception, 5 - Insight, 6 - Intimidation, 7 - Investigation, 8 - Leadership,
        //  9 - Medicine, 10 - Presuasion, 11 - Pilot, 12 - Magic, 13 - Scholar, 14 - Stealth, 15 - Survival, 16 - Tech, 17 - Weapon"
        std::cout << "What skill will you like to specialilze in? Input index from the following list: " << std::endl;
        std::cout << "0 - Athletics, 1 - Awareness, 2 - Ballistic, 3 - Cunning, 4 - Deception, 5 - Insight, 6 - Intimidation, 7 - Investigation," <<
            " 8 - Leadership, 9 - Medicine, 10 - Presuasion, 11 - Pilot, 12 - Magic, 13 - Scholar, 14 - Stealth, 15 - Survival, 16 - Tech, 17 - Weapon" << std::endl;

        int pref;
        //std::cin >> pref;
        while(!(std::cin >> pref)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input is not a number." << std::endl;
        }
        //need input validation here 
        while (!(0 <= pref && pref <= 17)) {
            std::cout << "Faulty input, index must be from the list above." << std::endl;
           // std::cin >> pref;
            while(!(std::cin >> tier)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Input is not a number." << std::endl;
            }
        }


        bool attmax;
        correct = false;
        std::cout << "Do you want to specialzie in all skills related to " << sheet.matchAttributeToStr(pref) << " y/n" << std::endl;
        while (!correct) {
            std::cin >> answ;
            if (tolower(answ) == 'y') {
                attmax = true;
                correct = true;
            }
            else if (tolower(answ) == 'n') {
                attmax = false;
                correct = true;
            }
            else {
                std::cout << "Answer must be y or n." << std::endl;
            }
        }
        tals = Quality(pref, sheet, talentBank, attmax);

    }


    //add talents and apply talents

    if (!tals.empty()) {
        for (int i = 0; i < tals.size(); i++) {
            sheet.addTalent(tals[i]);
        }
    }
    sheet.applyTalents();
    //ask if we want to add another sheet?

    system("CLS");
    std::cout << std::setw(60) << "Your final character sheet is:\n" << std::endl;

    std::cout << std::string(sheet);
    
    return sheet;
}

//Conduct skill check between two pre existing characters
void skillTest(Skills player1, Skills player2) {
    std::cout << "What skill will you like to test from the following index list?" << std::endl;
    std::cout << "0 - Athletics, 1 - Awareness, 2 - Ballistic, 3 - Cunning, 4 - Deception, 5 - Insight, 6 - Intimidation, 7 - Investigation," <<
        " 8 - Leadership, 9 - Medicine, 10 - Presuasion, 11 - Pilot, 12 - Magic, 13 - Scholar, 14 - Stealth, 15 - Survival, 16 - Tech, 17 - Weapon" << std::endl;
    int ch = -1;
   /* while (!(0 <= ch && ch <= 17)) {
        std::cout << "Input: " << std::endl;
        while (!(std::cin >> ch)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input is not a number." << std::endl;
        }
      //  std::cin >> ch;
    }*/

    //std::cin >> ch;
    while (!(std::cin >> ch)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Input is not a number." << std::endl;
    }
    //need input validation here 
    while (!(0 <= ch && ch <= 17)) {
        std::cout << "Faulty input, index must be from the list above." << std::endl;
        // std::cin >> pref;
        while (!(std::cin >> ch)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input is not a number." << std::endl;
        }
    }

    int p1r = player1.rollPool(ch);
    int p2r = player2.rollPool(ch);
    if (p1r > p2r) {
        std::cout << player1.getName() << " wins the contest with a difference of " << p1r - p2r << std::endl;
    }
    else if (p1r < p2r) {
        std::cout << player2.getName() << " wins the contest with a difference of " << p2r - p1r << std::endl;
    }
    else {
        std::cout << "There is no winner in this challenge." << std::endl;

    }
    system("PAUSE");
}
int main()
{
    system("CLS");
    std::vector<Talent> talentBank = talentMaker();
    std::cout << std::setw(60)<< "Greetings and Welcome!" << std::endl;
    std::cout << std::setw(65) << "This is the Table Top Multi-Tool\n" << std::endl;

    std::cout << "This tool is a generic representation of talent based table top role play games." <<
        "\nWith it you can create a character sheet and allow the program to select for you several of " <<
        talentBank.size() << " total talents.\n" << std::endl;
   
    std::cout << std::setw(60) << "Sheet Introduction\n" << std::endl;
    std::cout << "A character has a name, species, tier and experience points." <<
        "You may select name, species and tier for your character.\nExperience points are automatically assigned based on tier. The possible species are human, elf and orc.\n" <<
        "Experience points are used to purchase attribute score improvements, skill scores and talents for your character\n" <<
        "There are seven attributes: Strength  Toughness  Agility  Initiative  Willpower  Intelligence and Fellowship.\n"<<
        "All of these attributes are of value 1 by defaut, the three available species alter the possible maximum.\n" << std::endl;

    std::cout << "Skills are 0 by default. Each skill is associated with an attribute:" << std::endl;
    std::cout << "Athletics - Strength\t Awareness - Intelligence\t Ballistic - Agility\nCunning - Fellowship\t Deception - Fellowship\t\t" <<
        " Insight - Fellowship\nIntimidation - Willpower Investigation - Intelligence\t Leadership - Willpower\n" <<
        "Medicine - Intelligence\t Presuasion - Fellowship\t Pilot - Agility\nMagic - Willpower\t " <<
        "Scholar - Intelligence\t\t Stealth - Agility\nSurvival - Willpower\t Technology - Intelligence\t Weapon - Initiative\n" << std::endl;
    

    std::cout <<  "The tool supports two talent selection approaches.Before making a sheet you must be familiar with these options.\n" << std::endl;
    std::cout << std::setw(60) << "OPTION ONE: Quantity" << std::endl;
    std::cout << "This option will make your character a Jack of All Trades, it will select the highest amount of applicable talents it can.\n" << std::endl;
    std::cout << std::setw(60) << "OPTION TWO: Quality" << std::endl;
    std::cout <<  "This option will take your skill preferernce and find talents that fit the skill preference, it can also select talents with skill augments that match the preferred skill's attribute.\n" << std::endl;

    std::cout << "Ready to make a character? ";
    system("PAUSE");

    system("CLS");

    Skills player1 = SheetIO(talentBank);
    system("PAUSE");
    system("CLS");

    std::cout << "Will you like to make another? y/n " << std::endl;
    char ans;
    bool correct = false;

    while (!correct) {
        std::cin >> ans;
        if (tolower(ans) == 'n') {
            correct = true;
            exit(0);
            continue;
        }
        else if (tolower(ans) == 'y') {
            correct = true;
          
            continue;
        }
        else {
            std::cout << "Answer must be y or n" << std::endl;
        }

    }
    std::vector<Talent> talentBank2 = talentMaker();
    Skills player2 = SheetIO(talentBank2);
    correct = false;
    system("PAUSE");  
    system("CLS");
    std::cout << "\nWill you like to test the characters against eachother? y/n " << std::endl;
    while (!correct) {
        std::cin >> ans;
        if (tolower(ans) == 'n') {
            correct = true;

            continue;
        }
        else if (tolower(ans) == 'y') {
            correct = true;
            std::cout << "How many tests will you like to run? Select a number between 1 and 5" << std::endl;
            int tn = 0;

            std::cin >> tn;
            while (!(std::cin >> tn)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Input is not a number." << std::endl;
            }
            //need input validation here 
            while (!(0 <= tn && tn <= 5)) {
                std::cout <<  "Input: " << std::endl;
                // std::cin >> pref;
                while (!(std::cin >> tn)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Input is not a number." << std::endl;
                }
            }
           /* while (!(1 <= tn && tn <= 5)) {
                std::cout << "Input: " << std::endl;
                std::cin >> tn;
            }*/
            for (int i = 0; i < tn; i++) {
                skillTest(player1, player2);
               
            }
            continue;
        }
        else {
            std::cout << "Answer must be y or n" << std::endl;
        }

    }
    //make this thing a big func to call or smth that can be ran several times ?? will we let them fight ?? 
}





/*Skills testy = Skills();
    std::array<int, 18> skl{ 2,3,4,5,1,1,2,3,2,3,2,3,2,3,2,1,1,1 };

    Skills Qtest = Skills(skl, "Durge", "Elf", 1, 3, 3, 3, 3, 3, 3, 3);
    std::cout << std::string(Qtest) << std::endl;
    //testy.Randomize();
    //
      //vector testing 
std::vector<Talent> test = talentMaker();
std::vector<Talent> test1 = talentMaker();
std::vector<Talent> sel = Quality(2, Qtest, test, true);
std::vector<Talent> se = Quality(3, Qtest, test, true);
if (!sel.empty()) {
    for (int i = 0; i < sel.size(); i++) {
        Qtest.addTalent(sel[i]);
    }
}
if (!se.empty()) {
    for (int i = 0; i < se.size(); i++) {
        Qtest.addTalent(se[i]);
    }
}
Qtest.applyTalents();

// std::vector<Talent> sell = Quantity(test1, Qtest);
// if (!sell .empty()) {
 //    for (int i = 0; i < sell.size(); i++) {
 //        Qtest.addTalent(sell[i]);
 //    }
 //}
// Qtest.applyTalents();
std::cout << std::string(Qtest) << std::endl; */
   //forestCutter(plants.fore, Qtest);
   //std::stack<Node> treePool = PreferenceSort(Qtest.matchAttribute(2), plants.fore,Qtest);
   /*for (int i = 0; i < test.size(); i++) {
       std::cout << test[i].getName() << std::endl;
   }
   for (int i = 0; i < plants.size();i++) {
      // std::cout << "\n\nNode: " << plants.fore[i].tal << " with child " << plants.fore[i].left->tal.getName() << std::endl;
       while (!plants[i].empty()) {
           std::cout << "\n\nNode: " << plants[i].top().tal.getName();
           if (plants[i].top().left != nullptr) { std::cout << " with child " << plants[i].top().left->tal.getName(); }
           std::cout << std::endl;
           plants[i].pop();
       }

   }/*

   std::vector<Talent> sel = Quality(3, Qtest, test, true);
   //test[1].operator std::string();
   std::cout << Qtest << std::endl;
   std::cout << sel.size() << std::endl;
   //Qtest.applyTalents();
   //std::vector<Talent> t = Quantity(test, testy);
   if (!sel.empty()) {
       for (int i = 0; i < sel.size() - 1; i++) {
           Qtest.addTalent(sel[i]);
       }
   }
   Qtest.applyTalents();
   std::cout << Qtest << std::endl;
   
   /* if (sel[i].getCost() <= testy.Sheet::getExp()) {
           testy.addTalent(sel[i]);
         //  std::cout <<"Comparison result" << t[i].Talent::getSpeciesReq().compare(testy.Sheet::getSpecies()) << std::endl;
           //std::cout << testy.getTalents().size() << std::endl;
       }
       else {
           break;
       }
   std::cout << std::string(testy) << std::endl;
   //std::cout << "Talent's aquired are: " << testy.getTalents().size() << std::endl;
   std::cout << "Applying talents" << std::endl;
   testy.applyTalents();

   std::cout << std::string(testy) << std::endl;
   */
  /* for (int i = 0; i < testy.getTalents().size(); i++) {
       std::cout << testy.getTalent(i) << std::endl;
   }
   //std::cout << "This is the xp costs pre sorting" << std::endl;

   /*
   for (Talent i : test)
   {
       std::cout << i << std::endl;
       std::cout << std::endl;
   }
   /*std::cout << "Quicksort result !! " << std::endl;
   Quicksort(test, 0, test.size() - 1);
   for (Talent i : test)
   {
       std::cout << i.getCost() << std::endl;
       std::cout << std::endl;
   }*/


