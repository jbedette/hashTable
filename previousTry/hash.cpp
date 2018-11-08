#include "table.h"


long int table::makeHash(char name[], int max){//make a hash given an arr of chars
    long int hash = 0;
    int len = strlen(name);
    int powOfTen = 1;
    for(int i = 0; i < len; ++i){
        hash += (int)*name + i * powOfTen;
        powOfTen *= 10; 
    }
    hash *= 7;//arbitrary prime
    return hash / max; //make sure it's within arr bounds
}; 

//will output an index number given a hash
long int table::sortHash(long int hash, int arrLen){
    return hash % arrLen;
}
