#include <iostream>
#include <fstream>

#include "ioutils.hpp"
#include "cipher.hpp"
#include "date.hpp"

int main(int argc, const char *argv[]) {

	IOUtils io;
	io.openStream(argc,argv);
	std::string input, encrypted, decrypted;
	input = io.readFromStream();
	std::cout << "Original text: " << std::endl << input;


	Date date;
	encrypted = date.encrypt(input);
	std::cout << "Encrypted text: " << std::endl << encrypted << std::endl;

	decrypted = date.decrypt(encrypted);
	std::cout << "Decrypted text: " << std::endl << decrypted << std::endl;

	if (decrypted == input){
	    std::cout << "Decrypted text matches input!" << std::endl;
	} // End if statement
	else {
	    std::cout << "Oops! Decrypted text doesn't match input!" << std::endl;
	    return 1;   // Make sure to return a non-zero value to indicate failure
	} // End else statement

	return 0;
} // End main()

