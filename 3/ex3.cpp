#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <string>
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
    string letters;

    void readInput(const std::string& filePath){
        ifstream file(filePath);

        if (!file) {
            std::cerr << "Unable to open file " << filePath << std::endl;
            return;
        }

        string line;
        while (getline(file, line)){
            if(line[0] != '(' && letters.find(line[0]) != string::npos ){
                //code that writes CharIntPair's to data_array and checks for assignment errors 
            } else if (line[0] == '(') {
                /* code that checks expression validity and writes to stack*/
            } else {
                cout << line << ": Improper imput format" << endl;
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

