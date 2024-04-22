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
    static std::string letters;
    static std::string operators;

    void readInput(const std::string& filePath){
        ifstream file(filePath);

        if (!file) {
            std::cerr << "Unable to open file " << filePath << std::endl;
            return;
        }

        std::string line;
        while (getline(file, line)){
            bool allDigits = all_of(line.begin() + 2, line.end(), [](char c){ return isdigit(c); }); //check if everything after = is a digit
            bool A_Z = (letters.find(line[0]) != std::string::npos); // check if the variable declaration meets the imposed rules
            
            if((line[0] != '(') && (line[1] == '=') && (A_Z) && (allDigits)){
                //code that writes CharIntPair's to data_array and checks for assignment errors 
                size_t equalPos = line.find('=');
                char c = line[0]; //we get the var name
                int n = stoi(line.substr(equalPos + 1)); //we get the var value
                
                // Create a CharIntPair and add it to data_arr
                CharIntPair my_tuple = CharIntPair(c, n);
                data_arr.push_back(my_tuple);
                
            } else if (line[0] == '(') {
                /* code that checks expression validity and writes to stack*/
                // needed implementation to check if arithmetic expression is valid !!!
                for (int i = 0; i < line.size(); i++)
                {
                    expressionStack.push(line[i]);
                }
                //to make this code work with more than one expression per file we would 
                //need to have a queue or a list where we would add a different instance 
                //of this stack everytime
                
            } else {
                cout << line << ": Improper input format" << endl;
                expressionStack = stack <char>();
                data_arr = vector<CharIntPair>();
                break;
            }
        }
    }

    int execute(){
        // code that calculates the contents of data_arr
    }

    void writeOutput(){
        ofstream outputFile("output.txt");

        if (!outputFile) {
            cerr << "Unable to open output file." << endl;
            return;
        }

        int result = execute();
        outputFile << "Result: " << result << endl;

        outputFile.close();
    }

    Calculator(/* args */);
    ~Calculator();
};
std::string Calculator::letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string Calculator::operators = "+-*/%";


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

