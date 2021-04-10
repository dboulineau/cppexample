#include <string.h>
#include "myclass.hpp"
void somefunc() {
    MyObj *obj = new MyObj("c++");

    obj->speak();
    // we've leaked one object
}
/*
 * This method will overwrite the stack
 */
float overstep(const float& parm) {
    static float ff[10];

    ff[10] = parm; // oops, that's off the end
    float sum = 0;
    for (int ii=0; ii < 10;++ii) 
        sum+=ff[ii];
    // Write off the end of the heap we've been given
    char *buf = new char [20];
    buf[30] = '!';
    delete [] buf;
    return sum;
}
/*
 * This method will overwrite the stack
 */
void copystrings(char buf0[]) {
    char buf1[32];
    strcpy(buf1, buf0);
}
/* This is the entry point for this program */
int main(int argc, char *argv[]) {
    overstep(1.0f);
    somefunc();
    char buff[64];
    strcpy(buff, "The quick brown fox jumped over the lazy dog. ABCDEFGHIJKLMNOPQRSTUV");
    copystrings(buff);
    return 0;
}
