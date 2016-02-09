//
// Created by Danny on 1/28/2016.
//

#include <iostream>
#include <stdexcept>
#include "Token.h"

using namespace std;

Token::Token() {
    //this->readToken(&std::cin);
}

Token::Token(std::ifstream *newStream) {
    //this->readToken(newStream);
}

int Token::readToken(istream *stream){
    // we need to check if it's a number or symbol
    char x;
    *stream >> x; // read it into a char holder
    if(isdigit(x)){ // if it is a number, we put it back and read it as a double
        stream->putback(x);
        type = 'd';
        *stream >> double_val;
    } else { // else we put it back and read it as a char
        if(x == '='){
            return 1;
        }
        stream->putback(x);
        *stream >> char_val;
        type = 'c';
    }
    return 0;
}

void Token::setDouble(double d){
    double_val = d;
}

char Token::getCharVal() {
    if(char_val != '|') {
        return char_val;
    } else {
        cerr << "Error: accessing wrong type" << endl;
    }
}

double Token::getDoubleVal() {
    if(double_val != -1000) {
        return double_val;
    } else {
        cerr << "Error: accessing the wrong type" << endl;
    }
}


