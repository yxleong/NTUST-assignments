/*****************************************************************//**
 * File: main.cpp
 * Author: Leong Yah Xuan
 * Create Date: April 23, 2023
 * Update Date: May 20, 2023
 * Description: This C++ program is to simulate the process of writing and reading memory data.
 *********************************************************************/
#include <iostream>
#include <vector>
#include <string>

enum TYPE_SIZE {
	CHAR = 1,
	SHORT = 2,
	INT = 4
}; // byte

int main(void)
{
	// declare variables which are needed
	int memSize = 0, commandNum = 0;

	// read size of the memory
	std::cin >> memSize;

	// read number of commands
	while (std::cin >> commandNum)
	{
		// initialize memory with specific size
		std::vector<unsigned char> memory(memSize, 0);

		// loop operations to the memory
		for (int i = 0; i < commandNum; i++)
		{
			// declare variables which are needed
			std::string command = "", type = "";
			int position = 0;

			// readn instructions
			std::cin >> command >> position >> type;

			if (command == "Set")
			{
				if (type == "char")
				{
					unsigned int value = 0;

					std::cin >> value;

					// to avoid char greater than 255
					value = value > 255 ? 255 : value;
					// signed char: -128 to 127
					// unsigned char: 0 to 255

					if (position + CHAR > memSize) // if overflow occurs
					{
						std::cout << "Violation Access." << std::endl;
					}

					if (position < memSize)
					{
						// Write the given value into memory start with the given position
						// allocate memory space according to the given type
						memory[position] = (char)value;
					}
					else // if the size of value exceeds the size of type
					{
						// the excess part will be ignored
						continue;
					}

				}
				else if (type == "short")
				{
					unsigned short value = 0;

					std::cin >> value;

					if (position + SHORT > memSize) // if overflow occurs
					{
						std::cout << "Violation Access." << std::endl;
					}

					// loop by byte, 1 byte = 8 bits
					// right move 8 bits to reach next byte
					for (int i = position; value; value >>= 8, i++)
					{
						if (i < memSize)
						{
							// Write the given value into memory start with the given position
							// allocate memory space according to the given type
							memory[i] = (char)(value & 0xff); // 11111111
							// only save the least significant 8 bits
						}
						else // if the size of value exceeds the size of type
						{
							// the excess part will be ignored
							continue;
						}
					}
				}
				else if (type == "int")
				{
					unsigned int value = 0;

					std::cin >> value;

					if (position + INT > memSize) // if overflow occurs
					{
						std::cout << "Violation Access." << std::endl;
					}

					// loop by byte, 1 byte = 8 bits
					// right move 8 bits to reach next byte
					for (int i = position; value; value >>= 8, i++)
					{
						if (i < memSize)
						{
							// Write the given value into memory start with the given position
							// allocate memory space according to the given type
							memory[i] = (char)(value & 0xff); // 11111111
							// only save the least significant 8 bits
						}
						else // if the size of value exceeds the size of type
						{
							// the excess part will be ignored
							continue;
						}
					}
				}
				else if (type == "String")
				{
					std::string value = "";

					std::cin.get();	// ignore space
					std::getline(std::cin, value);

					if (position + value.size() > memSize) // if overflow occurs
					{
						std::cout << "Violation Access." << std::endl;
					}

					// loop by char in string
					for (int i = 0; i < value.size(); i++)
					{
						int index = i + position;
						if (index < memSize)
						{
							// Write the given value into memory start with the given position
							// allocate memory space according to the given type
							memory[index] = value[i];
						}
						else // if the size of value exceeds the size of type
						{
							// the excess part will be ignored
							continue;
						}
					}
				}
			}
			else if (command == "Get")
			{
				if (type == "char")
				{
					if (position + CHAR > memSize) // if given position is illegal
					{
						std::cout << "Violation Access." << std::endl;
					}
					else // if the given position is legal
					{
						std::cout << (int)memory[position] << std::endl;
					}

				}
				else if (type == "short")
				{
					if (position + SHORT > memSize) // if given position is illegal
					{
						std::cout << "Violation Access." << std::endl;
					}
					else // if the given position is legal
					{
						unsigned short value = 0;

						// loop by 8^n
						// left move 8 bits 00000001 -> 0000000100000000
						for (int i = 0, base = 1; i < SHORT; i++, base <<= 8)
						{
							int index = i + position;
							value += (unsigned short)memory[index] * base;
							// if decimal then * 10
							// but now is octal, so * 256
						}

						std::cout << value << std::endl;
					}
				}
				else if (type == "int")
				{
					if (position + INT > memSize) // if given position is illegal
					{
						std::cout << "Violation Access." << std::endl;
					}
					else // if the given position is legal
					{
						unsigned int value = 0;

						// loop by 8^n
						// left move 8 bits 00000001 -> 0000000100000000
						for (int i = 0, base = 1; i < INT; i++, base <<= 8)
						{
							int index = i + position;
							value += (unsigned int)memory[index] * base;
							// if decimal then * 10
							// but now is octal, so * 256
						}

						std::cout << value << std::endl;
					}
				}
				else if (type == "String")
				{
					// check by char
					if (position + CHAR > memSize) // if given position is illegal
					{
						std::cout << "Violation Access." << std::endl;
					}
					else // if the given position is legal
					{
						for (int i = position; memory[i] && i < memory.size(); i++)
						{
							std::cout << memory[i];
						}
					}

					std::cout << std::endl;
				}
			}
		}
	}
	return 0;
}