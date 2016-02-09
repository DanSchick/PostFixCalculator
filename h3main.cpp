/*
 * Author: Danny Schick
 *
 * Created on January 18, 2016, 4:57 PM
 */

#include <cstdlib>
#include <iostream>
#include "PostFixCalc.h"

using namespace std;

int main(int argc, char** argv) {
    // first we test using interactive mode
    PostFixCalc calc;
    calc.turnOn();


    // now we test using files

    // get the input file
    ifstream infile;
    string input;
    cout << "Enter the name of the infile: " << endl;
    cin >> input;
    infile.open(input);


    // now get the output and redirect cout and cerr to the outfile using freopen()
    ofstream outfile;
    cout << "Enter the name of the outfile: " << endl;
    cin >> input;
    const char * c = input.c_str();
    freopen(c, "w", stdout);
    freopen(c, "w", stderr);

    // and turn on the calculator with a reference to the infile
    PostFixCalc calc2 = PostFixCalc(&infile);
    calc2.turnOn();

    return 0;
}

