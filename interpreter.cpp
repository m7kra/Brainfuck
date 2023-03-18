/**
 * This is an interpreter for the `brainfuck` language created by M7kra. For the
 * full specification, please refer to the readme file.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
using namespace std;

const int DATA_SIZE = 30000;

string read_program(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    string program = read_program(argc, argv);
    int matches[program.size()];
    stack<int> previous;
    for (int i = 0; i < program.size(); i++) {
        if (program[i] == '[') previous.push(i);
        else if (program[i] == ']') {
            int match = previous.top();
            previous.pop();
            matches[i] = match;
            matches[match] = i;
        }
    }

    char data[DATA_SIZE] = {};
    int dp = 0; // Data pointer
    int ip = 0; // Instruction pointer

    while (ip < program.size() && dp >= 0 && dp < DATA_SIZE) {
        switch (program[ip]) {
            case '>':
                dp++;
                break;
            case '<':
                dp--;
                break;
            case '+':
                data[dp]++;
                break;
            case '-':
                data[dp]--;
                break;
            case '.':
                cout << data[dp];
                break;
            case ',': {
                // Wrapping is needed to prevent "Jump to case label" error
                char c = cin.get();
                if (c != '\n') data[dp] = c;
                else data[dp] = 0;
                break;
            }
            case '[':
                if (data[dp]) break;
                ip = matches[ip];
                break;
            case ']':
                if (!data[dp]) break;
                ip = matches[ip];
                break;
        }
        ip++;
    }
}

const string DEFAULT_SOURCE = "./program.bf";
string read_program(int argc, char *argv[]) {
    string filepath;
    if (argc > 1) {
        filepath = argv[1];
    } else filepath = DEFAULT_SOURCE;

    ifstream file;
    file.open(filepath);
    if (!file.is_open()) {
        cout << "File " << filepath << " not found\n";
    }
    
    stringstream tmp;
    tmp << file.rdbuf();
    string program;
    for (char c : tmp.str()) {
        if (c == '>' || c == '<' || c == '+' || c == '-' || c == '.' || c == ',' || c == '[' || c == ']') {
            program += c;
        }
    }
    return program;
}