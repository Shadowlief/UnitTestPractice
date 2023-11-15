#include "Password.h"
#include <string>

using std::string;

//password constructor!
Password::Password()
{
  string passcode = "ChicoCA-95929";
  vector<string> pass_history;
  pass_history.push_back(passcode);
};

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

/*my version-fuck me it seg faults
bool Password::has_mixed_case(string phrase){
  bool mixed = false;
  bool hasLowerCase = false;
  bool hasUpperCase = false;
  int currASCII = 0;
  for(int i = 0; i < phrase.length()-1; i++)
  {
    currASCII = int(phrase[i]); //typecast the character at this point of the string into an int to get the ASCII code.

    if(currASCII >= 65 && currASCII <=90) //ASCII val is from 65-90 [an upper case letter]
    {
      hasUpperCase = true;
    }
    if(currASCII >= 97 && currASCII <= 122) //ASCII val is from 97-122 [a lower case letter]
    {
      hasLowerCase = true;
    }
  }
  if(hasLowerCase && hasUpperCase)
  {
    mixed = true;
  }
  return mixed;
}*/


//tony version
bool Password::has_mixed_case(string phrase)
{
  if(phrase.size() == 0){ //if input in empty
    return false;
  }
  bool upper = false;
  bool lower = false;
  for(int i = 0; i < phrase.length(); i++){
    if(isupper(phrase[i])) //check if current charactrer is uppercase
      upper = true;
    if(islower(phrase[i])) //check if current character is lowercase 
      lower = true;
  }
  return upper && lower; //return true if both are true
}

//Starting here everything breaks and I don't know where the hiding {} is!!

/*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
  */
  void Password::set(string currentCode)
  {
    if(authenticate(currentCode))
    {
      pass_history.push_back(currentCode);
    }
  }


  /*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
  */
  bool Password::authenticate(string testME)
  {
    bool isGood = true;

    //passcode length test
    if(testME.length() < 8)
    {
      isGood = false;
      return isGood;
    }

    //leading character check
    int rep = count_leading_characters(testME);
    if(rep > 3)
    {
      isGood = false;
      return isGood;
    }
    
    //mixed case check
    if(!has_mixed_case(testME))
    {
      isGood = false;
      return isGood;
    }

    //previous passcode test
    for(int i = 0; i < pass_history.size(); i++)
    {
      if(testME == pass_history.at(i))
      {
        isGood = false;
        return isGood;
      }
    }

    return isGood;
  }