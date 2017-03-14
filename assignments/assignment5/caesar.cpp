#include "cipher.hpp"
#include "caesar.hpp"

#include <string>

// Constructor
Caesar::Caesar(): Cipher(), rotation(2){

}

//Caesar::Caesar(int rotate) : Cipher(), rotation(rotate){
//}

// Destructor 
Caesar::~Caesar(){

}

std::string 
Caesar::encrypt( std::string &inputText ){
   std::string text = inputText;
   std::string::size_type len = text.length();
   for(int i = 0; i < len; i++){
	if(text[i] == '\n'){
	    continue;
	} // End if statement
	else{
	    if(ispunct(text[i])){
		continue;
	    } // End nested if statement
	    else{
		int index = 0; 
		while(text[i] != alphabet[index]){
		   ++index;
		} // End nested nested while loop 
		text[i] = alphabet[((index + rotation) % 53)];
	    } // End nested else statement
	} // End else statement 
   } // End for loop 

   return text; 
} // End encrypt()

std::string 
Caesar::decrypt( std::string &inputText ){
   std::string text = inputText; 
   std::string::size_type len = text.length(); 
   int index; 

   for(int i = 0; i < len; i++ ){
	if(text[i] == '\n') {
	    continue;
	} // End nested if statement
 	else{
	    if(ispunct(text[i])){
		continue;
	    } // End nested nested if statement
	    else{
	       index = 0; 
	       while(text[i] != alphabet[index]){
	  	   ++index;
	       } // End nested nested nested while loop 
	       if((index - rotation) < 0){
		   text[i] = alphabet[((53 + (index - rotation)) % 53)];
	       } // End nested nested nested if statement		
	       else{
		   text[i] = alphabet[((index - rotation) % 53)];
	       } // End nested nested nested else statement
	    } // End nested nested else statement
	} // End nested else 
   } // End for loop 

   return text;
} // End decrypt()
