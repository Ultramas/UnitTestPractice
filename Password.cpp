#include "Password.h"
#include <string>
#include <cctype>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  if (phrase.empty()) return 0;
  int repetition = 1;
  size_t index = 0;
  while (index + 1 < phrase.length() && phrase[index] == phrase[index + 1]) {
    repetition++;
    index++;
  }
  return repetition;
}

/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string pass){

  bool has_lower = false;
  bool has_upper = false;
  for (unsigned char ch : pass) {
    if (std::islower(ch)) has_lower = true;
    else if (std::isupper(ch)) has_upper = true;
    if (has_lower && has_upper) return true;
  }
  return false;
}

unsigned int password_test_count_leading_characters(string phrase)
{
  Password p;
  return p.count_leading_characters(phrase);
}