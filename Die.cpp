#include "Die.h"
//#include <cstdlib>
#include <Windows.h>
//#include <ctime>
#include <iostream>
#include <process.h>



Die::Die() {
	critical = false;
	Roll();
	}

int Die::Roll() {
	int roll;
	
	//seed set to time for alteration 
	srand((int) time(0));

	//calculating doen to range
	roll = 1 + (rand() % 6);
	switch (roll) {
	case 1:
		setSuccess(0);
		setCritical(true);
		return 1;
		break;
	case 2:
		setSuccess(0);
		return 2;
		break;
	case 3:
		setSuccess(0);
		return 3;
		break;
	case 4:
		setSuccess(1);
		return 4;
		break;
	case 5:
		setSuccess(1);
		return 5;
		break;
	case 6:
		return 6;
		setSuccess(2);
		setCritical(true);
		break;
	}
	
}

void Die::setSuccess(int success) {
	if (success > 0 && success <= 2) {
		this->success = success;
	}
	else {
		//std::cout << "Bad Roll" << std::endl;
	}
}

void Die::setCritical(bool critical) {
	this->critical = critical;
}

int Die::getSuccess() {
	return success;
}

bool Die::getCritical() {
	return critical;
}