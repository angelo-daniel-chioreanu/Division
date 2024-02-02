#include <iostream>
#include <string>
#include <bitset>

using namespace std;

unsigned long convertBinaryImageToDecimalNumber(unsigned long n);

/*
Implement a function that can solve the following problem:
Given a number A, find the smallest number which has only 1s and 0s as its digits which are divisible by the number A.
For example:
If the given number A is 4, the smallest number with 1s and 0s which is divisible by 4 is 100.
If the given number A is 3, the answer would be 111.
*/

/*
* My solution is empirical, trying to find the result using the computer power but in an optimal process with the minimum operations so that to be fast.
* There is a limitation to the processing numbers based on the programming language standard types.
* I have not used online ideas, it is my own idea.
* I have observed that the test number is formed only by 1s and 0s like a binary number in text format but it is in fact in decimal format.
* My code optimization is to get the decimal numbers formed by 1s and 0s without many tests and increment operations thus:
* I increment an integer type by 1, I convert it into string representation of its binary format then I convert the string which has only 1s and 0s to the decimal number which is tested by modulo operator.
* On this way, the process is fast with the minimum number of processing steps.
*/

int main()
{
    cout << "*** The program runs in a loop until entering 'q' ***" << endl;
    for (;;)
    {
        try
        {
            string input;
            long a = 0;
            unsigned long d = 0, r = 0;

            cout << "Provide the A number then press Enter (enter 'q' to quit): ";

            cin >> input;

            if (input == "q")
                break;
            else
                a = stol(input);

            if (a <= 0)
            {
                cout << "The A number must be greater than zero." << endl;
                continue;
            }

            while (r <= a)
                r = convertBinaryImageToDecimalNumber(++d);

            cout << "try :" << r << endl;

            while (r % a != 0)
            {
                r = convertBinaryImageToDecimalNumber(++d);
                cout << "try :" << r << endl;
            }

            cout << "********" << endl;
            cout << "The smallest number which has only 1s and 0s as its digits which are divisible by the number " << a << " is: " << r << endl;
            cout << "********" << endl;
        }
        catch (out_of_range)
        {
            cout << "********" << endl;
            cout << "The result number is too big for the standard types supported by the C++ language." << endl;
            cout << "********" << endl;
        }
    }

    cout << "*** Good-bye! ***" << endl;
}

unsigned long convertBinaryImageToDecimalNumber(unsigned long n)
{
    string sBynaryImage = bitset<32>(n).to_string();

    unsigned long uNumber = stoul(sBynaryImage);

    return uNumber;
}

/*
*** The program runs in a loop until entering 'q' ***
Provide the A number then press Enter (enter 'q' to quit): 3
try :10
try :11
try :100
try :101
try :110
try :111
********
The smallest number which has only 1s and 0s as its digits which are divisible by the number 3 is: 111
********
Provide the A number then press Enter (enter 'q' to quit): 4
try :10
try :11
try :100
********
The smallest number which has only 1s and 0s as its digits which are divisible by the number 4 is: 100
********
Provide the A number then press Enter (enter 'q' to quit): 435435345345
********
The result number is too big for the standard types supported by the C++ language.
********
Provide the A number then press Enter (enter 'q' to quit): 78
try :100
try :101
try :110
try :111
try :1000
try :1001
try :1010
try :1011
try :1100
try :1101
try :1110
try :1111
try :10000
try :10001
try :10010
try :10011
try :10100
try :10101
try :10110
try :10111
try :11000
try :11001
try :11010
try :11011
try :11100
try :11101
try :11110
try :11111
try :100000
try :100001
try :100010
try :100011
try :100100
try :100101
try :100110
try :100111
try :101000
try :101001
try :101010
********
The smallest number which has only 1s and 0s as its digits which are divisible by the number 78 is: 101010
********
Provide the A number then press Enter (enter 'q' to quit): q
*** Good-bye! ***

C:\Users\Explorer\source\repos\Division\x64\Debug\Division.exe (process 8860) exited with code 0.
Press any key to close this window . . .
*/