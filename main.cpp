// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include "Lexer.h"

int main(int argc, char* argv[]) {
    Lexer theLex;
    string lexString;
    string filename = argv[1];
    ifstream myfile;
    myfile.open(filename);
    if (myfile.is_open())
    {
        while (myfile.peek()!=EOF)
        {

            char line;
            line = myfile.get();
            lexString.push_back(line);

        }
        myfile.close();
        theLex.run(lexString);
    }

    else cout << "Unable to open file";
    return 0;
}

/*
 * COMMENT

UNDEF VALUE
 block comment does termin undef (when "#" and then you hit the end of the file)
 copy string auto to make block comment automata

string doesn't termin undef (when "'''" and then you hit the end of the file)


 Undefined tokens are:

A single character that cannot be the first character of a valid token.
A string that is not terminated.
A comment that is not terminated.

GOING TO NEED THREE differ undefined automata header files

 */