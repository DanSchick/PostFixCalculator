//
// Created by Danny on 2/8/2016.
//

#include <iostream>
#include "Tstack.h"

using namespace std;
int main(int argc, char** argv) {
    cout << "Enter 5 numbers to make this easier to show dynamic allocation: " << endl;
    Tstack stack = Tstack(5); // construct with specified length
    // now let's test that the stack will dynamically allocate
    Token tok1;
    tok1.readToken(&cin);
    stack.push(tok1);
    Token tok2;
    tok2.readToken(&cin);
    stack.push(tok2);
    Token tok3;
    tok3.readToken(&cin);
    stack.push(tok3);
    Token tok4;
    tok4.readToken(&cin);
    stack.push(tok4);
    Token tok5;
    tok5.readToken(&cin);
    stack.push(tok5);


    // print out results of stack.pop() 5 times
    cout << "flag" << endl;
    for(int i=0;i<5;i++){
        tok1 = stack.pop();
        cout << "Popped Token Value: " << tok1.getDoubleVal() << endl;
    }

    return 0;


}
