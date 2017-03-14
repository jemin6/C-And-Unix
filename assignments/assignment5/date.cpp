#include <iostream>
#include <string>

#include "cipher.hpp"
#include "date.hpp"

//Constructor
Date::Date() : Cipher(){
    for(int i = 0; i < 6; i++){
	rotation[i] = 2;
    } // End for loop 
} // End

Date::Date(std::string d) : Cipher(){
   if(d.length() != 6){
      std::cout << "Invalid" << std::endl;
   } // End if 
   for(int i = 0; i < d.length(); i++){
      if(std::isdigit(d[i])){
      	 for(int j = 0; j < 6; j++){
	     rotation[j] = (int)d[i];
	 } // End nested for loop 
      } // End if statement
   } // End for loop 
} // End 


//Destructor
Date::~Date(){

}

std::string
Date::encrypt( std::string &inputText ){
   std::string text = inputText;
   std::string::size_type len = text.length();
   int index;

   for(int i = 0; i < len; i++){
        if(text[i] == '\n'){
            continue;
        } // End if statement
        else{
            if(ispunct(text[i])){
                continue;
            } // End nested if
            else{
                index = 0;
                while(text[i] != alphabet[index]){
                   ++index;
                } // End while loop
                text[i] = alphabet[((index+rotation[i % 6]) % 53)];
            } // End nested else
        } // End elst statement
   } // End for loop
   return text;
} // End encrypt()


std::string
Date::decrypt( std::string &inputText ){
    std::string text = inputText;
    std::string::size_type len = text.length();
    int index;

    for(int i = 0; i < len; i++){
        if(text[i] == '\n'){
            continue;
        } // End if statement
        else{
            if(ispunct(text[i])){
                continue;
            } // end nested if
            else{
                index = 0;
                while(text[i] != alphabet[index]){
                   ++index;
                } // End while
                if((index - rotation[i % 6]) < 0){
                   text[i] = alphabet[((53 + (index - rotation[i % 6])) % 53)];
                } // End if
                else{
                   text[i] = alphabet[((index - rotation[i % 6]) % 53)];
                } // End else
            } // End nested elst
        } // End else
    } // End for loop

    return text;

} // End decrypt()

