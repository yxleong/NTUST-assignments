# Class Inheritance

## Problem Statement
Define a class named `Document` that contains a member variable of type string named `text` that stores any textual content for the document. Create a method named `getText` that returns the text field, a way to **set** this value, and an overloaded assignment **operator**.

Next, define a class for `Email` that is derived from `Document` and includes member variables for the `sender`, `recipient`, and `title` of an email message. Implement appropriate **accessor** and **mutator** methods. The `body` of the email message should be stored in the inherited variable text. Also overload the assignment **operator** for this class.

Similarly, define a class for `File` that is derived from `Document` and includes a member variable for the `pathname`. Implement appropriate **accessor** and **mutator** methods for the `pathname` and overload the assignment **operator**. 

Finally, create several sample objects of type `Email` and `File` in your `main` method. Test your objects by passing them to the following subroutine that returns true if the object contains the specified keyword in the text property.

For example, you might test to see if an email message contains the text "c++" with the call `ContainsKeyword(emailObj, "c++")`;

```cpp
bool ContainsKeyword(const Document& docObject, string keyword)
{
   if (docObject.getText().find(keyword) != string::npos)	
		return true;
   return false;
}
```


## Input:
No Input for this problem, but the different main function will be changed to test your code.
```
main.in
```

## Output:
Depends on the output of testing main function.
```
sample.out
```

## Note
main.in
```cpp
int main()
{
    // Create several test objects
    Email email1("Body about programming in C++",
        "Larry", "Curly", "Programming");
    Email email2("Body about running marathons",
        "Speedy", "Gonzales", "races");

    File file1("Contents about some C++ file", "file.txt");
    File file2("Contents about marathon races", "run.txt");

    cout << "Which contains C++?" << endl;
    if (ContainsKeyword(email1, "C++")) cout << " Email1" << endl;
    if (ContainsKeyword(email2, "C++")) cout << " Email2" << endl;
    if (ContainsKeyword(file1, "C++")) cout << " File1" << endl;
    if (ContainsKeyword(file2, "C++")) cout << " File2" << endl;

    // Test our assignment operator
    file2 = file1;
    file2.setPathname("c:");
    cout << "After assignment file2=file1 and file2.setPathname(\"c:\"): "
        << endl;
    cout << "File1's path = " << file1.getPathname() << endl;
    cout << "File2's path = " << file2.getPathname() << endl;

    return 0;
}
```
sample.out
```
Which contains C++?
 Email1
 File1
After assignment file2=file1 and file2.setPathname("c:"): 
File1's path = file.txt
File2's path = c:

```

## Additional Information
* Eazy, only basic programming syntax and structure are required.
* Solving time: 30 minutes
* Contributors: 陳俊儒, 鄭鈺哲, 張子樂