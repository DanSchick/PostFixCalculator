//
// Created by Danny on 2/4/2016.
//

#ifndef HELLOWORLD_POSTFIXCALC_H
#define HELLOWORLD_POSTFIXCALC_H


#include "Tstack.h"

class PostFixCalc {
public:
    /*
     * Constructor for a post-fix calculator object with default stream of cin
     */
    PostFixCalc();
    /*
     * Constructor with a file input stream
     */
    PostFixCalc(std::ifstream *in);
    /*
     * Method that runs the calculator. Handles everything.
     */
    int turnOn();

private:
    std::istream *stream;


};


#endif //HELLOWORLD_POSTFIXCALC_H
