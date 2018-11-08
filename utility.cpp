#include "table.h"
//when using this for float, convert in client
int numExtract(char nums[]){
    int num = 0;
    int len = strlen(nums);
    int powTen =  1;
    for(int i = 0; i < (len-1); ++i){
        powTen *= 10;
    }
    for(int i = 0; i < len; ++i){
        int out =((int)*nums + i) - 48;
        if( out > 9 || out < 0) out = 0;
        num += out * powTen;
        powTen/=10;
    }
    return num;
}
