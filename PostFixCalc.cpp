//
// Created by Danny Schick
//

#include <iostream>
#include "PostFixCalc.h"

using namespace std;

PostFixCalc::PostFixCalc() {
    stream = &std::cin;
}


PostFixCalc::PostFixCalc(ifstream *in) {
    stream = in;

}

int PostFixCalc::turnOn() {
    // we need to define constants we'll need for the main loop
    int length = 15; // length of the stack we want
    Tstack tokenStack = Tstack(length);
    // we have to define two tokens that will hold operands for operations
    Token operand1;
    Token operand2;
    double result; // this double will hold results of calculations
    bool error = false; // this variable will be true is there is and error
    bool newExpression = true; // this variable is to see if we should exit. It's true only for the first loop of a new expression
    Token tokenResult; // this token will hold the result of operations

    // this is the main while calculator loop
    while(true){
        Token token;
        // First thing we do is read the next token
        // if the token isn't an equals sign, it will return 0
        if(token.readToken(stream) == 0) {
            newExpression = false; // after we read one token that's not equals, it's not a new expression
            if (token.type == 'd') {
                // if the token is a double, we push it
                tokenStack.push(token);
                tokenResult = tokenStack.pop(); // we pop it and push it so we still have a reference to the variable
                tokenStack.push(tokenResult);
            } else if (token.type == 'c') {
                // if the token is a character: we do the operation it tells
                // first we pop out the two operands to do our operator on
                operand2 = tokenStack.pop();
                operand1 = tokenStack.pop();

                // we need to check for errors in the expression
                // check if trying to operate on non-numbers (ex: '4 + - =')
                if(operand1.type != 'd' or operand2.type != 'd') {
                    error = true;
                    cerr << "ERROR: attempting to operate on two non-numbers" << endl;
                } else if (token.getCharVal() == '+') {
                    // if there's no errors, we start the if else statements to figure out what operator to do
                    result = operand1.getDoubleVal() + operand2.getDoubleVal();
                } else if (token.getCharVal() == '-') {
                    result = operand1.getDoubleVal() - operand2.getDoubleVal();
                } else if (token.getCharVal() == '*') {
                    result = operand1.getDoubleVal() * operand2.getDoubleVal();
                } else if (token.getCharVal() == '/') {
                    result = operand1.getDoubleVal() / operand2.getDoubleVal();
                } else {
                    // If we reach this, then the token is not an operation we support
                    // so we designate the expression as an error
                    cerr << "ERROR: Operator not supported. Only + - * / are supported" << endl;
                    error = true;
                }
                if(!error){ // if no errors
                    tokenResult.setDouble(result);
                    tokenStack.push(tokenResult);
                }

            }
        } else{ // token.readToken() returned 1, meaning the token was an = AND there is no errors
            if(tokenStack.getSize() > 0){
                // there is still tokens in the stack, meaning there were extra numbers
                // example: '1 2 3 + ='
                cerr << "ERROR: too many numbers in the expression" << endl;
                std::cout << "Enter a valid post-fix expression, with a = at the end. Type in '=' to exit: " << std::endl;
                error = true;
            }
            if(error){ // if there are errors
                // we clear the stack and prepare for a new expression
                tokenStack.clear();
                newExpression = true;
                error = false;
            }
            else if(newExpression){
                // we need to exit because the user typed in our = sentinel
                cout << "Exiting... " << endl;
                return 0;
            } else {
                // it's the end of an expression. Get the result and print it out
                tokenResult = tokenStack.pop();
                std::cout << "RESULT: " << tokenResult.getDoubleVal() << std::endl;
                // then we prepare for a new expression
                std::cout << "Enter a valid post-fix expression, with a = at the end. Type in '=' to exit: " << std::endl;
                newExpression = true;
            }
        }

    }
    return 1;

}

