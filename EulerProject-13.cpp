// 10_05_hw3_help.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Krishant Rauniyar

#include <iostream>
#include <fstream>
#include <string>
#include <list>

/

int main()
{
    std::ifstream file("nums.txt");
    if (!file.is_open()) {
        std::cerr << "error: could not open the file." << std::endl;
    }

    // create a list object 
    std::list<int> result;

    // need to read each line into a string
    std::string line;
    while (std::getline(file, line)) {
        //std::cout << "line: " << line << std::endl;

        //std::cout << std::endl;

        // if result list is empty: load the first number
        if (result.empty()) {
            for (auto it = line.begin(); it != line.end(); it++) {
                //int a = *it - '0';      // offset by '0' to retrieve real digit
                result.push_front(*it - '0');
            }


        }
        else {      // add new number to the list, one digit at a time
            int carry{ 0 };
            int i{ 0 };
            for (auto it = result.begin(); it != result.end(); it++) {
                // add digit from list node to the newly read digit 
                int index = line.size() - 1 - i; // index for the line from the text file
                int newDigit;

                if (index > 49 || index < 0) // if the index is out of bounds then the new carry digit will be zero
                    newDigit = 0;
                else
                    newDigit = line[index] - '0';

                int sum = carry + *it + newDigit; // add the carry bit and current value

                // store only one digit back to iter
                *it = sum % 10; // new value in the list will be first digit of actual addition

                // update carry 
                carry = sum / 10; // carry bit will be 1 if addition value is > 1

                i++; // iterator for index of the string

            }
            if (carry > 0) { // checks for a carry bit and then if there is one, a new digit place is added
                result.push_back(carry); // puts cary and the end of the list 
            }

        }

        // traverse the list 
        for (auto it = result.begin(); it != result.end(); ++it) {
            std::cout << *it;
        }

        std::cout << std::endl;

    }


    file.close();
}

