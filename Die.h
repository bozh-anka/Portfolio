#pragma once

class Die {

	private:
		int success;
		bool critical;
	public: 
		Die();
		int Roll();

		//critical and success options for gameplay, unused
		void setSuccess(int success);
		int getSuccess();

		void setCritical(bool critical);
		bool getCritical();
	
};