//
// Created by Danny on 2/8/2016.
//

#include <iostream>
#include "Token.h"

using namespace std;
int main(int argc, char** argv) {
    Token token;
    // read a token from cin
    token.readToken(&cin);

    if(token.type == 'c'){
        cout << "token character value is " << token.getCharVal() << endl;
    } else if(token.type == 'd'){
        cout << "token double value is " << token.getDoubleVal() << endl;
    }

    // read a token from a file
    ifstream infile;
    infile.open("data.txt");
    Token token2;
    token2.readToken(&infile);
    if(token.type == 'c'){
        cout << "token character value is " << token.getCharVal() << endl;
    } else if(token.type == 'd') {
        cout << "token double value is " << token.getDoubleVal() << endl;
    }



}

