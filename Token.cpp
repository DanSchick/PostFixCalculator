//
// Created by Danny on 1/28/2016.
//

#include <iostream>
#include <stdexcept>
#include "Token.h"

using namespace std;

Token::Token(void) {
}

int Token::readToken(){
    // we need to check if it's a number or symbl
    char x;
    cin >> x; // read it into a char holder
    if(isdigit(x)){ // if it is a number, we put it back and read it as a double
        cin.putback(x);
        type = 'd';
        cin >> double_val;
    } else { // else we put it back and read it as a char
        if(x == '='){
            return 1;
        }
        cin.putback(x);
        cin >> char_val;
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
        throw "Error: accessing the wrong type";
    }
}

double Token::getDoubleVal() {
    if(double_val != -1000) {
        return double_val;
    } else {
        cerr << "Error: accessing the wrong type" << endl;
        throw "Error: accessing the wrong type";
    }
}


