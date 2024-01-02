
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

    Multiplication(int mc, int ml, int b);


    void writeOutputToFile(std::ofstream &outputFile) const;

    void performBoothAlgorithm(std::ostream &output) const;

    void decimalToBinary(int num, int binary[], int length) const;

    void reverseArray(int arr[], int length) const;


    void printBinary(int num, int bits, std::ostream &output) const;

    void add(int accumulator[], int mcnadBinary[], int mplierLength) const;

    void complement(int binary[], int n) const;

    void arithShiftRight(int accumulator[], int mplierBinary[], 
        int &mplierLSB, int mplierLength, std::ostream &output) const;

    void display(int accumulator[], int mplierBinary[], int mplierLength, 
        std::ostream &output) const;

    void performBoothAlgorithmUserInput();

    void binaryToDecimal(int accumulator[], int mplierBinary[], 
        int mplierLength, std::ostream &output) const;
};

#endif // H_multiplication
