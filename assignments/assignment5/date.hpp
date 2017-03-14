#ifndef DATE_HPP_
#define DATE_HPP_

#include "cipher.hpp"

class Date : public Cipher {
public:
	Date();
	Date(std::string date);
	virtual ~Date();
	virtual std::string encrypt( std::string &inputText);
	virtual std::string decrypt( std::string &inputText);
private:
	int rotation[6];
	char alphabet[53] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

};

#endif	/* DATE_HPP_ */
