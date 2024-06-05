#include <iostream>
#include "Talent.h"
#include "Sheet.h"
#include <vector>
#include <map>

void talentMaker() {
    ifstream file;
    file.open("TalentBank.csv");
    string line;
    getline(file, line);
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    return 0;
}