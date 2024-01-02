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
    while(!inFile.eof()){
        inFile >> md >> ml >> b;
        if(!inFile.eof()){
        multiplications.push_back(Multiplication(md,ml,b));
        }
    }

}
