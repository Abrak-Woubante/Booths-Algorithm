
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
    FileClass(string file_name);
    ~FileClass();
                
};

void getData(std::vector<Multiplication> &multiplications, const std::string &filename);

#endif // H_fileInfo
