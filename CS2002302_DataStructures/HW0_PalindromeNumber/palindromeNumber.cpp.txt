#include <iostream>
#include <string>

std::string reverse(std::string input) {
 
  std::string tupin = "";
  
  for(int i = input.length() - 1; i >= 0; i--) {
    tupin += input[i];
  }
  
  return tupin;
}

int main(void) {
  
  std::string intX = "";
  std::cin >> intX;
  
  std::string palindromeX = reverse(intX);
  
  for(int i = intX.length(); i >= 0; i--) {
      
    if(intX[i] != palindromeX[i]) {
      std::cout << intX << " is not a palindrome number.";
      return 0;
    }
  }
  
  std::cout << intX << " is a palindrome number.";
  
  return 0;  
}