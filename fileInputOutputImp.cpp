/*Name: WOUBANTE,ABRAK NSHE: 5007305246,CLASS-SECTION: CS202,ASSIGNMENT:2
Description: Perform signed binary multiplication using booth's algorith 
with extended method
Input: The user is allowed to choose one out of 3 options.
Option 1:Read data from input.txt file and perform binary multiplication 
Output 1:Write the steps of algorithm along with result to an output file
Option 2:Read decimal input from terminal window and perform binary 
multiplication.
Output 2:Similar to output 1 but this time you write in terminal window. 
Option 3:Usage of mutator and accessor functions 
Output 3:Print multiplicand and multiplier values in binary and decimal
in terminal window.
*/
#include "fileInputOutput.h"

    FileClass::FileClass(string file_name){// constructor
        inFile.open(file_name);
        if(!inFile){
            cout<<"Error: Can not open file"<<endl;
        }
        outFile.open("outFile.txt");
        if(!outFile){
            cout<<"Error: can not write to file"<<endl;
        }
       
    } 

    /* This destructor is to close input and output files*/
    FileClass::~FileClass(){
        inFile.close();
        outFile.close();
    }   

    void getData(std::vector<Multiplication> &multiplications,
     const std::string &filename){
    ifstream inFile;
    inFile.open(filename);
    if(!inFile){
        cout<<"Failed to open the file."<<endl;
    }else{
        cout<<"file opened successfully."<<endl;
    }
    string line="";
    int md,ml,b;
    getline(inFile,line);
    while(!inFile.eof()){//adding the ! operator 
        inFile >> md >> ml >> b;
        if(!inFile.eof()){
        multiplications.push_back(Multiplication(md,ml,b));
        }
    }

}
