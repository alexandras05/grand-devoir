#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm> // for std::all_of
#include <cctype> // for std::isdigit
using namespace std;



struct CharIntPair {
    char character;
    int number;

    CharIntPair(char c, int n) : character(c), number(n) {}
};

class Calculator
{
public:
    stack<char> expressionStack;
    vector<CharIntPair> data_arr;
    static string letters;

    void readInput(const std::string& filePath){
        ifstream file(filePath);

        if (!file) {
            std::cerr << "Unable to open file " << filePath << std::endl;
            return;
        }

        string line;
        while (getline(file, line)){
            bool allDigits = all_of(line.begin() + 2, line.end(), [](char c){ return isdigit(c); }); //check if everything after = is a digit
            bool A_Z = (letters.find(line[0]) != string::npos); // check if the variable declaration meets the imposed rules
            if((line[0] != '(') && (line[1] == '=') && (A_Z) && (allDigits)){
                //code that writes CharIntPair's to data_array and checks for assignment errors 
                
            } else if (line[0] == '(') {
                /* code that checks expression validity and writes to stack*/
            } else {
                cout << line << ": Improper input format" << endl;
            }
        }
    }

    int execute(){
        // code that calculates the contents of data_arr
    }

    void writeOutput(){
        ofstream outputFile("output.txt");

        if (!outputFile) {
            cerr << "Unable to open output file." << std::endl;
            return;
        }

        int result = execute();
        outputFile << "Result: " << result << std::endl;

        outputFile.close();
    }

    Calculator(/* args */);
    ~Calculator();
};
//avem nevoie de asta la verificari :3
string Calculator::letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cerr << "Please provide a file path as a command line argument." << std::endl; //Error Handling if there is no arg provided
        return 1;
    }

    Calculator calculator;
    calculator.readInput(argv[1]);

    // Other code...

    return 0;
    return 0;
}

