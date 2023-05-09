# Namespace

## Problem Statement
This programming project explores the usage of unnamed namespace in C++. The program consists of two files, `user.cpp` and `password.cpp`, which contain code to input and validate a username and password respectively. The `isValid()` function checks if the input meets certain criteria, while the `inputUserName()` and `inputPassword()` functions prompt the user to input a username and password respectively until the input is valid. The `getUserName()` and `getPassword()` functions return the valid username and password respectively.

The task is to define the `isValid()` function and the username/password variables in the unnamed namespace in each file, and to place the `main()` function in an appropriate place to ensure that the program compiles and runs.

## Sample Input / Output

### Input
The program prompts the user to input a username and password, with the requirements specified in the code.
```
aaa
aaaaaa
abcdefghi
abcdefgh
aaaaaaaaaa1
```

### Output
The program outputs the valid username and password.
```
Enter your username (8 letters only)
Enter your username (8 letters only)
Enter your username (8 letters only)
Enter your username (8 letters only)
Enter your password (at least 8 characters and at least one non-letter)
Your username is abcdefgh and your password is: aaaaaaaaaa1
```

## Note
main.cpp
```
int main()
{
  inputUserName();
  inputPassword();
  cout << "Your username is " << getUserName() <<
      	" and your password is: " <<
      	getPassword() << endl;
  return 0;
}
```
user.cpp
```
namespace Authenticate
{
  void inputUserName()
  {
	do
	{
 	cout << "Enter your username (8 letters only)" << endl;
 	cin >> username;
	} while (!isValid());
  }
 
  string getUserName()
  {
 	return username;
  }
}
```
password.cpp
```
namespace Authenticate
{
  void inputPassword()
  {
	do
	{
 	cout << "Enter your password (at least 8 characters " <<
         	"and at least one non-letter)" << endl;
 	cin >> password ;
	} while (!isValid());
  }
 
  string getPassword()
  {
 	return password;
  }
}
```

## Additional Information
* Medium, multiple programming grammars and structures are required.
* Solving time: 20 minutes
* Contributors: 謝公耀, 陳俊儒, 廖宣瑋


