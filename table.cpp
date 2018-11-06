#include "table.h"

table::table(){
    companies = NULL;
}
table::~table(){
    delete companies;
}
int table::init(int sizeArr){
    int flag = 0;
    companies = new company[sizeArr+1];
    return flag;
}
//
int table::addComp(company * temp){
    int flag = 0;
    return flag;
}
int table::dispAll(){
    int flag = 0;
    return flag;
}
/*
table::
table::
table::
table::
table::
    int flag = 0;
    return flag;
*/
