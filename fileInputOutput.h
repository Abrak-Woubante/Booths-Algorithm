/*
Name: KISHORE, NSHE: ABC123, CLASS-SECTION: CS202, ASSIGNMENT: 2
Description: Perform signed binary multiplication using booth's algorith 
with extended method
Input: The user is allowed to choose one out of 3 options.
Option 1:Read data from input.txt file and perform binary multiplication. 
Output 1:Write the steps of algorithm along with result to an output file.
Option 2:Read decimal input from terminal window and perform binary 
multiplication.
Output 2:Similar to output 1 but this time you write in terminal window. 
Option 3:Usage of mutator and accessor functions 
Output 3:Print multiplicand and multiplier values in binary and decimal
in terminal window.
*/
#ifndef H_fileInputOutput
#define H_fileInputOutput

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include "multiplication.h"

using namespace std;

class FileClass
{

public:
    ifstream inFile;
    ofstream outFile;
    bool fileError;

    /* Open the input and output files in the constructor; 
    print error messages accordingly if the files are not present */
    FileClass(string file_name);

    /* This destructor is to close input and output files*/
    ~FileClass();
                
};

// global functions
/*To read data from input file and copy it to vector object. It reads 
multiplicand, multiplier and bits amount for each operation
*/
void getData(std::vector<Multiplication> &multiplications, const std::string &filename);

#endif // H_fileInfo
