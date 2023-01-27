#include <iostream>

class Contact
{
	private:
		std::string name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		~Contact();
		std::string getFirstname();
		std::string getLastname();
		std::string getNickname() ;
		std::string getPhoneNumber();
		std::string getSecret();
		void	setPhoneNumber(std::string nb);
		void	setNickname(std::string nick);
		void	setSecret(std::string secret);
		void 	setFirstname(std::string fname);
		void 	setLastname(std::string lname);
};