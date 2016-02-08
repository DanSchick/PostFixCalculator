//
// Created by Danny on 1/28/2016.
//

#ifndef HELLOWORLD_TOKEN_H
#define HELLOWORLD_TOKEN_H


class Token {
public:
    /* Constructor for a token object */
    Token();

    char type; // this is the type of token. 'd' for double, 'c' for char

    /*
     * This will read the last token from cin
     */
    int readToken();

    /*
     * This sets the double field to the given value.
     * Used to set a specific result in the post-fix loop
     * @param d: number to set double to
     */
    void setDouble(double d);

    /*
     * Will return a char value if it exists
     * @return: char representing a symbol (+, -, *, etc)
     */
    char getCharVal();
    /*
     * Will return a double value if it exists
     * @return: the number this class holds
     */
    double getDoubleVal();
private:
    char char_val = '|'; // holds a char value if the token is a symbol. defaults to | to check if there's a value
    double double_val = -1000 ; // holds a double value if the token is a number. defaults to -1000 to check if there's a value
};


#endif //HELLOWORLD_TOKEN_H
