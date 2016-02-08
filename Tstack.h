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
     * Copy contstructor for a deep copy
     */
    Tstack(const Tstack &obj);
    /*
     * Destructor for when copying or terminating
     */
    ~Tstack();
    /*
     * Clear the stack by setting top to 0
     */
    void clear();

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
    Token *storage;
    int size = 0;
    int top = -1;
    int bufferSize = 10;



};


#endif //HELLOWORLD_TSTACK_H
