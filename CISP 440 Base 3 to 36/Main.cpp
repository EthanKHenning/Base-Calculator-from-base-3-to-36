#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#pragma warning( disable : 4996) 
#pragma warning( disable : 4244) 
using namespace std; 

//functions native to my code
//int getBaseVal();
//vector<char> defineBase(vector<char> allPossible, int baseVal);

//functions provided in sample, in order
long my_atoi(string s, int base);
void my_itoa(long n, int base);
void itoDNAcodon(int i);
int DNAcodontoi(string codon);
void addInBase(string inputOne, string inputTwo, int base);


//ASCII val - '0' easily converts to integer
// subtract 55 from any letter A to Z you'll get 10 through 36
int main() 
{
    int base = 36;
    string number = "16";
    //long decimalVal = my_atoi(number, base);
    my_atoi(number, base);

    long decimalVal = 42;
    base = 11;
    my_itoa(decimalVal, base);
    base = 36;
    
    itoDNAcodon(33);
    
    string DNA = "ACT";
    DNAcodontoi(DNA);

    base = 16;
    string inputOne = "ABBA";
    string inputTwo = "ACDC";
    addInBase(inputOne, inputTwo, base);

    cout << endl;
    cout << "addition tests: " << endl;
    cout << endl;

    base = 36;
    inputOne = "123A";
    inputTwo = "123";
    addInBase(inputOne, inputTwo, base);

    inputOne = "123";
    inputTwo = "123A";
    addInBase(inputOne, inputTwo, base);

    inputOne = "1236";
    inputTwo = "123";
    base = 7;
    addInBase(inputOne, inputTwo, base);
}


/*
Converts an alphanumeric string 's' representation of a base 'base' number
to internal binary format.
Returns the value as a 32 bit integer
*/
//ASCII val - '0' easily converts to integer
// subtract 55 from any letter A to Z you'll get 10 through 36
long my_atoi(string number, int base)
{
    string workable = number;
    reverse(workable.begin(), workable.end());

    long tempholder = 0;
    long decimal = 0;

    for (int i = 0; i < number.length(); i++)
    {
        if (workable[i] >= '0' && workable[i] <= '9')
        {
            tempholder = (workable[i] - '0');
            tempholder = tempholder * pow(base, i);
        }
        else if (workable[i] >= 'A' && workable[i] <= 'Z')
        {
            tempholder = (workable[i] - '7');
            tempholder = tempholder * pow(base, i);
        }
        decimal += tempholder;
    }

    for (int i = 0; i < number.length(); i++)
    {
            cout << number[i];
    }

    cout << " base " << base << " is " << decimal << " base 10" << endl;

    return decimal;
}


/*
Converts a 32 bit integer 'n' into an alphanumeric string 'sOut'
representation of a base 'base' number
*/
void my_itoa(long decimal, int base)
{
    
    long decimalVal = decimal;
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string sOut = "";
    int remainder;


    while ( decimal > 0)
    {
        remainder = decimal % base;
        sOut = sOut + digits[remainder];
        decimal = decimal / base;
    }
    
    reverse(sOut.begin(), sOut.end());

    cout << decimalVal << " base 10 is " << sOut << " base " << base << endl;
}


/*
Converts an integer to base 4 codon format
*/
void itoDNAcodon(int i)
{
    int holder = i;
    string baseFour = "";
    string temp = "";
    //first turn int to from base 10 to base 4
    while (i > 0)
    {
       temp = to_string(i % 4);
       baseFour = baseFour + temp; 
       i = i / 4;
    }

    string DNA = "";

    //next make each base 4 value find it's corresponding DNA letter
    for (int j = 0; j < baseFour.length(); j++)
    {
        if(baseFour[j] - '0' == 0)
        {
            DNA = DNA + 'C';
        }

        if(baseFour[j] - '0' == 1)
        {
            DNA = DNA + 'A';
        }

        if(baseFour[j] - '0' == 2)
        {
            DNA = DNA + 'T';
        }

        if(baseFour[j] - '0' == 3)
        {
            DNA = DNA + 'G';
        }
    }

    //output the DNA string
    cout << holder << " base 10 is " << DNA << " in DNA" << endl;
}


/*
Returns the base 4 value of a codon
*/
int DNAcodontoi(string codon)
{
    int value = 0;
    string temp = "";

    for(int i = 0; i < codon.length(); i++)
    { 
        if(codon[i] == 'C')
        {
            temp += '0';
        }

        if(codon[i] == 'A')
        {
            temp += '1';
        }

        if(codon[i] == 'T')
        {
            temp += '2';
        }

        if(codon[i] == 'G')
        {
            temp += '3';
        }   
    }

    int holder = 0;
    for (int i = 0; i < temp.length(); i++)
    {
        holder = temp[i] - '0';
        holder = holder * pow(4, i);
        value += holder;
    }

    cout << codon << " in DNA is " << value << " base 10" << endl;
    return value;
}



/*
Adds 2 numbers in any base.

Arguments:
input s1, s2, base, return sum
*/
void addInBase(string inputOne, string inputTwo, int base)
{
    // return a dummy for now until you get it actually working
   // strcpy(sum, "1153");
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string sum = "";
    
    string tempOne = inputOne;
    string tempTwo = inputTwo;
    reverse(tempOne.begin(), tempOne.end());
    reverse(tempTwo.begin(), tempTwo.end());
    int carry = 0;
    int temp;

    string remainingDigits = "";
    //after addition is done do if statements to see if one of the strings holds more, then append those values to the front of the other string
    
    if (tempOne.length() > tempTwo.length())
    {
        remainingDigits = tempOne.substr(tempTwo.length(), tempOne.length() - tempTwo.length());
        tempOne.resize(tempTwo.length());
        
        //use tempTwo
        for (int i = 0; i < tempTwo.length(); i++)
        {

            if (tempTwo[i] >= '0' && tempTwo[i] <= '9')
            {
                temp = tempTwo[i] - '0';
            }
            else if (tempTwo[i] >= 'A' && tempTwo[i] <= 'Z')
            {
                temp = tempTwo[i] - '7';
            }

            if (carry == 1)
            {
                temp += 1;
                carry = 0;
            }

            if (tempOne[i] >= '0' && tempOne[i] <= '9')
            {
                temp = temp + (tempOne[i] - '0');
            }
            else if (tempOne[i] >= 'A' && tempOne[i] <= 'Z')
            {
                temp = temp + (tempOne[i] - '7');
            }

            if (base <= temp)
            {
                //have to account for all situations that can allow for a carry
                carry = 1;
                temp = temp % base;
            }

            //convert that number to the string using the digits string 
            //add that character to the sum
            sum = sum + digits[temp];
        }
        //fix the order of sum
        reverse(sum.begin(), sum.end());
        //adding the extra onto the front
        string prepend = "";
        int loopAmount = (tempOne.length() - tempTwo.length());
        for (int i = 0; i < loopAmount; i++)
        {
            prepend = prepend + tempOne[i];
        }
        sum = remainingDigits + sum;
    }



    else if (tempOne.length() < tempTwo.length())
    {
        remainingDigits = tempTwo.substr(tempOne.length(), tempTwo.length() - tempOne.length());
        tempTwo.resize(tempOne.length());

        //use tempOne
        for (int i = 0; i < tempOne.length(); i++)
        {
            if (tempTwo[i] >= '0' && tempTwo[i] <= '9')
            {
                temp = tempTwo[i] - '0';
            }
            else if (tempTwo[i] >= 'A' && tempTwo[i] <= 'Z')
            {
                temp = tempTwo[i] - '7';
            }

            if (carry == 1)
            {
                temp += 1;
                carry = 0;
            }

            if (tempOne[i] >= '0' && tempOne[i] <= '9')
            {
                temp = temp + (tempOne[i] - '0');
            }
            else if (tempOne[i] >= 'A' && tempOne[i] <= 'Z')
            {
                temp = temp + (tempOne[i] - '7');
            }

            if (base <= temp)
            {
                //have to account for all situations that can allow for a carry
                carry = 1;
                temp = temp % base;
            }

            //convert that number to the string using the digits string 
            //add that character to the sum
            sum = sum + digits[temp];
        }
        //fix the order of sum
        reverse(sum.begin(), sum.end());
        //adding the extra onto the front
        string prepend = "";
        int loopAmount = (tempOne.length() - tempTwo.length());
        for (int i = 0; i < loopAmount; i++)
        {
            prepend = prepend + tempOne[i];
        }
        sum = remainingDigits + sum;
        
    }

    else if (tempOne.length() == tempTwo.length())
    {
        for (int i = 0; i < tempOne.length(); i++)
        {
            if (tempTwo[i] >= '0' && tempTwo[i] <= '9')
            {
                temp = tempTwo[i] - '0';
            }
            else if (tempTwo[i] >= 'A' && tempTwo[i] <= 'Z')
            {
                temp = tempTwo[i] - '7';
            }

            if (carry == 1)
            {
                temp += 1;
                carry = 0;
            }

            if (tempOne[i] >= '0' && tempOne[i] <= '9')
            {
                temp = temp + (tempOne[i] - '0');
            }
            else if (tempOne[i] >= 'A' && tempOne[i] <= 'Z')
            {
                temp = temp + (tempOne[i] - '7');
            }

            if (base <= temp)
            {
                //have to account for all situations that can allow for a carry
                carry = 1;
                temp = temp % base;
            }
            //convert that number to the string using the digits string 
            //add that character to the sum
            sum = sum + digits[temp];
        }
        reverse(sum.begin(), sum.end());
    }

    cout << inputOne << " base " << base << " + " << inputTwo << " base " << base << " = " << sum << endl;
}
