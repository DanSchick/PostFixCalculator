//
// Created by Danny on 1/29/2016.
//

#ifndef HELLOWORLD_TSTACK_H
#define HELLOWORLD_TSTACK_H


#include "Token.h"

class Tstack {
public:
    /*
     * Basic constructor with default size of 10
     */
    Tstack();

    /*
     * Constructor that allows a specified starting size
     */
    Tstack(int len);

    /*
     * Destructor for when copying or terminating
     */
    ~Tstack();

    /*
     * Clear the stack by setting top to 0
     */
    void clear();

    /*
     * @return the current size of the stack. This will be the top variable
     */
    int getSize();

    /*
     * pop off top element
     */
    Token pop();
    /*
     * add new token element to stack
     */
    void push(Token token);

private:
    Token *storage; // this is the list that holds the tokens
    int size = 0; // variable representing size
    int top = -1; // variable represnting current top object
    int bufferSize = 10; // this will add it's value to the size of the array if it gets too big



};


#endif //HELLOWORLD_TSTACK_H
