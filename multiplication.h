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
#ifndef H_multiplication
#define H_multiplication

#include <string>
using namespace std;

class Multiplication
{
private:
    int manMcand; //object to store multiplicand
    int manMplier; //object to store multiplier
public:
    int multiplicand;
    int multiplier;
    int bits;
    int result;
    
    Multiplication(); // Default constructor
    void setMultiplicand(int mcand); //To set multiplicand
    void setMultiplier(int mplier); //To set multiplier
    int getMultiplicand() const; //returns multiplicand
    int getMultiplier() const; //returns multiplier

    /*Parameterized constructor to initialize multiplicand,
    multiplier, bits; Also initialize result to 0 */
    Multiplication(int mc, int ml, int b);

    /*check if output file is open and then call performBoothAlgorithm()
    and write the output to an output file*/
    void writeOutputToFile(std::ofstream &outputFile) const;

    /*Use booth's algorithm to perform signed binary multiplication and 
    write the results to an output file*/ 
    void performBoothAlgorithm(std::ostream &output) const;

    /*This function takes the decimal number as input and converts it
    to binary and stores it in binary [] */
    void decimalToBinary(int num, int binary[], int length) const;

    /*This function reverses the given array */
    void reverseArray(int arr[], int length) const;

    /* This function prints the given number in binary*/
    void printBinary(int num, int bits, std::ostream &output) const;

    /*This function adds the accumulator and multiplicand bitwise and 
    store/write back the addition result to the accumulator in binary*/
    void add(int accumulator[], int mcnadBinary[], int mplierLength) const;

    /*This function does the 1s complement to the given binary[]
    and stores/write back it in binary[] */
    void complement(int binary[], int n) const;

    /*This function does the arithmetic shift right, extending the MSB of 
    accumulator[]; In this, accumulator[] lsb is shifted to MSB of 
    mplierBiary[] and so on; check sample output */
    void arithShiftRight(int accumulator[], int mplierBinary[], 
        int &mplierLSB, int mplierLength, std::ostream &output) const;

    /*This function is to display the parameters accumulator[], 
    mplierBinary[]; if output file is selected it writes to output file,
    else prints on terminal window; It depends on your ostream object*/
    void display(int accumulator[], int mplierBinary[], int mplierLength, 
        std::ostream &output) const;

    /*Use booth's algorithm to perform signed binary multiplication and 
    write the results in terminal/console window*/ 
    void performBoothAlgorithmUserInput();

    /*This function gets the accumulator[], mplierBinary[] as input and 
    converts it to decimal. It writes the result to an output file or terminal
    depends upon the ofstream object */
    void binaryToDecimal(int accumulator[], int mplierBinary[], 
        int mplierLength, std::ostream &output) const;
};

#endif // H_multiplication