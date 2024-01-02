/*
Name: WOUBANTE,ABRAK NSHE: 5007305246,CLASS-SECTION: CS202,ASSIGNMENT:2
Description: Perform signed binary multiplication using booth's algorith 
with extended method
Input: The user is allowed to choose one out of 3 options.
O 1:Read data from input.txt file and perform binary multiplication 
Output 1:Write the steps of algorithm along with result to an output file
Option 2:Read decimal input from terminal window and perform binary 
multiplication.
Output 2:Similar to output 1 but this time you write in terminal window. 
Option 3:Usage of mutator and accessor functions 
Output 3:Print multiplicand and multiplier values in binary and decimal
in terminal window.
*/
#include "multiplication.h"
#include <fstream>
#include <cmath>
#include <iostream>

Multiplication::Multiplication()
{
    multiplicand = 0;
    multiplier = 0;
    bits = 0;
    result = 0;
    manMcand = 0; // object to store multiplicand
    manMplier = 0;
}

void Multiplication::setMultiplicand(int mcand)
{
    manMcand = mcand;//set
}

void Multiplication::setMultiplier(int mplier)
{
    manMplier = mplier;//set
}

int Multiplication::getMultiplicand() const
{
    return manMcand;//get
}

int Multiplication::getMultiplier() const
{
    return manMplier;//get
}

Multiplication::Multiplication(int mc, int ml, int b)
{
    multiplicand = mc;
    multiplier = ml;
    bits = b;
    result = 0;
}
void Multiplication::writeOutputToFile(std::ofstream &outputFile) const
{
    if (!outputFile)//if not open
    {
        cout << "Failed to write to output file." << endl;
    }
    else//just open file 
    {
        performBoothAlgorithm(outputFile);
    }
}

void Multiplication::performBoothAlgorithm(std::ostream &output) const
{
    int acc[10] = {0};
    int mul[10] = {0};//make arrays
    int mcand[10] = {0};
    int temparr[10] = {0};
    int lsb = 0;
    int tempArr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    tempArr[bits - 1] = 1;
    //get binary
    decimalToBinary(multiplier, mul, bits);
    decimalToBinary(multiplicand, mcand, bits);
    output << endl; //spacing
    output << "Multiplicand in decimal: " << multiplicand << endl;
    output << "Multiplicand in binary: ";//get public var
    if (multiplicand > 0)
    {
        output << "0";//only print for positive
    }
    printBinary(multiplicand, bits, output);
    output << endl;
    output << "\nMultiplier in decimal: " << multiplier << endl;
    output << "Multiplier in binary: ";
    if (multiplier > 0)
    {
        output << "0";//only print for positive
    }
    printBinary(multiplier, bits, output);
    output << endl;
output << "step	qn	q[n+1]		action				multiplicand	"<<
    "Product" << endl;
    output << "				initial			";
    printBinary(multiplicand, bits, output);
    output << "		0000 ";
    printBinary(multiplier, bits, output);
    output << endl;//spacing
    for (int i = 0; i < bits; i++)
    {
        output << i + 1;//print steps
        if (mul[bits - 1] == 0 && lsb == 1)
        {
            for (int i = 0; i < bits; i++)
            {
                temparr[i] = mcand[i];
            }
            add(acc, temparr, bits);//add 1
            output << "	0	1		a:01->prod=ls/prod+Mcand	";
            printBinary(multiplicand, bits, output);//print binary
            output << "		";
            display(acc, mul, bits, output);//get the answer
            output << "		";//spacing
            // output<<endl;
            output << "		b:shift right product		";
            printBinary(multiplicand, bits, output);
            output << "		";//spacing
        }
        else if (mul[bits - 1] == 1 && lsb == 0)
        {
            for (int i = 0; i < bits; i++)
            {
                temparr[i] = mcand[i];
            }
            complement(temparr, bits);//1s comp
            add(temparr, tempArr, bits);
            add(acc, temparr, bits);//2s comp
            output << "	1	0 		a:10->prod=ls/prod-Mcand	";
            printBinary(multiplicand, bits, output);//print bin
            output << "		";//spacing
            display(acc, mul, bits, output);//show answer
            output << "		";//spacing
            output << "		b:shift right product		";
            printBinary(multiplicand, bits, output);//get binary
            output << "		";
        }
        else if (mul[bits - 1] == 0 && lsb == 0)//for 0 n 0 
        {
            output << "	0	0 		a:00->no operation;shiftRight	";
            printBinary(multiplicand, bits, output);
            output << "		";
        }
        else//for 1 and 1
        {
            output << "	1	1 		a:11->no operation;shiftRight	";
            printBinary(multiplicand, bits, output);
            output << "		";
        }
        arithShiftRight(acc, mul, lsb, bits, output);//all need to shift
        display(acc, mul, bits, output);//answers
    }

    output << "Result=";//print result
    display(acc, mul, bits, output);//call respective functions
    output << "Result in decimal=";//print decimal
    binaryToDecimal(acc, mul, bits, output);//call respective function
    output << endl;//space
    output << "---------------------------------------------------------"
    <<"----------------------------------------------------------"<<endl;
    output << endl;//spacing
}
void Multiplication::decimalToBinary(int num, int binary[],
 int length) const
{
    int i = 0;
    bool positive = num >= 0;
    num = abs(num);
    // cout << "num: " << num << endl;
    int tempArr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    tempArr[length - 1] = 1;//add 1 to the end
    while (num > 0)
    {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }
    reverseArray(binary, length);
    if (!positive)//twos comp
    {
        complement(binary, length);
        add(binary, tempArr, length);
    }
}

void Multiplication::reverseArray(int arr[], int length) const
{
    int temp;//just turn array around
    for (int i = length - 1; i >= length / 2; i--)
    {
        temp = arr[length - i - 1];//store in temp
        arr[length - i - 1] = arr[i];
        arr[i] = temp;//make it to temp
    }
}

void Multiplication::printBinary(int num,int bits,std::ostream &output)
const
{
    int binary[10] = {0};//create binary array
    decimalToBinary(num, binary, bits);//call to mak into binary
    for (int i = 0; i < bits; i++)//go thru each one
    {
        output << binary[i];//go thru and print 
    }
}
void Multiplication::add(int accumulator[], int mcnadBinary[]
, int mplierLength) const
{
    int sum;//make sum
    int carry = 0;//create carry
    for (int i = mplierLength - 1; i >= 0; i--)
    {
        sum = accumulator[i] + mcnadBinary[i] + carry;
        carry = sum / 2; //bring carry over
        sum = sum % 2;
        accumulator[i] = sum;//update
    }
}

void Multiplication::complement(int binary[], int n) const
{
    for (int i = 0; i < n; i++)//very easy peasy
    {
        if (binary[i] == 0)//make 0 a 1
        {
            binary[i] = 1;//doing it here
        }
        else
        {
            binary[i] = 0;//make 1 a 0
        }
    }
}

void Multiplication::arithShiftRight(int accumulator[],int mplierBinary[]
,int &mplierLSB, int mplierLength, std::ostream &output) const
{
    mplierLSB = mplierBinary[mplierLength - 1];//make lsb
    for (int i = mplierLength - 1; i > 0; i--)//go thru backwards
    {
        mplierBinary[i] = mplierBinary[i - 1];//make it last index
    }
    mplierBinary[0] = accumulator[mplierLength - 1];//declarefirst index
    for (int i = mplierLength - 1; i > 0; i--)
    {
        accumulator[i] = accumulator[i - 1];//make lastindex
    }
}

void Multiplication::display(int accumulator[], int mplierBinary[],
 int mplierLength, std::ostream &output) const
{
    int i = 0;//set i to zero
    for (; i < bits; i++)//go until bits is done
    {
        output << accumulator[i];//jus print
    }
    output << " ";//spacing needed
    for (i = 0; i < bits; i++)//go thru 
    {
        output << mplierBinary[i];//jusprint
    }
    output << endl;//spacing
}

void Multiplication::performBoothAlgorithmUserInput()
{
    int mul = 0;//multiplicand
    int mcand = 0;//multiplcand
    int mulbits = 0;//bits
    int mcandbits = 0;//bits
    int acc[10] = {0};//array for accum
    int mull[10] = {0};//mulplier array
    int mcandd[10] = {0};//multiplicadn array
    int temparr[10] = {0};//jus temp
    int lsb=0;
    decimalToBinary(multiplier, mull, mulbits);
    decimalToBinary(multiplicand, mcandd, mcandbits);
    cout << "Number of multiplicand bits =";
    cin >> mcandbits;
    bits = mcandbits;
    cout << "Enter the multiplcand in decimal=";
    cin >> mcand;
    setMultiplicand(mcand);
    cout << "Multiplicand in binary: ";
    if (mcand > 0)
    {
        cout << "0";//print zero
    }
    printBinary(mcand, mcandbits, cout);
    cout << endl;//spacing
    cout << "Number of multiplier bits=";
    cin >> mulbits;//get bits
    cout << "Enter the multiplier in decimal=";
    cin >> mul;//get decimal
    cout << "Multiplier in binary:";
    setMultiplier(mul);//set it
    if (mul > 0)
    {
        cout << "0";//make pos zero
    }
    printBinary(mul, mulbits, cout);
    cout<<endl;
    cout << "step	qn	q[n+1]		action				"
    <<"multiplicand	Product" << endl;
    cout << "				initial			    ";
    printBinary(mcand, mcandbits, cout);
    cout << "		0000 ";
    printBinary(mul, mulbits, cout);
    cout << endl;//spacing
        for (int i = 0; i < mulbits; i++)
        {
            cout<<i+1<<endl;
            if (mull[mulbits - 1]==0 && lsb==1)
            {
                for (int i = 0; i < mulbits; i++){
                    temparr[i] = mcandd[i];
                }
                add(acc, temparr, mulbits);
                cout<<"	0	1		a:01->prod=ls/prod+Mcand	";
                printBinary(multiplicand,mulbits,cout);
                cout<<"		";//spacing
                display(acc, mull,mulbits, cout);
                cout<<"		";//spacing
                cout<<"		b:shift right product		";
                printBinary(multiplicand,mulbits,cout);
                cout<<"		";//spacing
            }
        }
        cout << "Result=";//print result
        display(acc, mull, mulbits, cout);
        cout << "Result in decimal=";//get decimal
        binaryToDecimal(acc, mull, mulbits, cout);
        cout << endl;//spaci

}

void Multiplication::binaryToDecimal(int accumulator[],int mplierBinary[]
,int mplierLength, std::ostream &output) const
{
    int sum2 = 0;//sum var
    if (accumulator[0] == 1)//if negative
    {
        for (int i = 1; i < mplierLength; i++)
        {
            if (accumulator[i] == 0)//make 0
            {
                sum2 += pow(2, (mplierLength - i - 1)+mplierLength);
            }//base and power
        }
        for (int i = 0; i < mplierLength; i++)
        {
            if (mplierBinary[i] == 0)
            {
                sum2 += pow(2, mplierLength - i - 1); 
            }
        }
        sum2 = sum2 + 1;
        sum2 = -sum2;
    }
    else
    {//if posotive
        for (int i = mplierLength - 1; i >= 0; i--)
        {
            if (mplierBinary[i] == 1)//make one
            {
                sum2 += pow(2, mplierLength - i - 1);//do math
            }
        }
        for (int i = mplierLength - 1; i > 0; i--)
        {
            if (accumulator[i] == 1)
            {
                sum2 += pow(2, mplierLength + mplierLength - i - 1); 
            }
        }
    }
    output << sum2;//print sum
}
