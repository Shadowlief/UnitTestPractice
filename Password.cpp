#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
  
}

/*
   The function recieves a string, checks to see if there's an upper case letter and a lower case letter 
*/

bool Password::has_mixed_case(string phrase){
  bool mixed = false;
  bool hasLowerCase = false;
  bool hasUpperCase = false;
  int currASCII = 0;
  for(int i = 0; i < phrase.length()-1; i++)
  {
    if() //ASCII val is from 65-90 [an upper case letter]
    {
      hasUpperCase = true;
    }
    if() //ASCII val is from #-# [a lower case letter]
    {
      hasLowerCase = true;
    }
  }
  if(hasLowerCase && hasUpperCase)
  {
    mixed = true;
  }
  return mixed;
}