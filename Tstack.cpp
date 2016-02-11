//
// Created by Danny on 1/29/2016.
//

#include "Tstack.h"

using namespace std;

/*
 * First, let's define all the contructors we need
 */
Tstack::Tstack() {
    storage = new Token[10];
    this->size = 10;
}
int Tstack::getSize(){
    return top;
}

Tstack::Tstack(int len) {
    if(len <= 0){
        throw string("The length must be more than 0");
    }
    storage = new Token[len];
    this->bufferSize = len;
    this->size = len;
}

Tstack::~Tstack() {
    delete storage;
    delete &bufferSize;
    delete &size;
    delete &top;
}
void Tstack::clear() {
    top = -1;
}
Token Tstack::pop() {
    Token popped = storage[top];
    top -= 1;
    return popped;
}
void Tstack::push(Token token) {
    top += 1;
    if(top==this->size){ // this array is full. We have to allocate more memory
        Token *newMem = new Token[bufferSize + size];
        for(int i=0;i<=this->size;i++){
            newMem[i] = storage[i];
        }
        delete storage;
        storage = newMem;
    }
    storage[top] = token;

}

