#include "head.h"

node::node(){
    key = 0;//int
    next = NULL;//ptr
    addr = NULL;//ptr
    comp = NULL;//ptr
    phon = 0;//int
    acct = 0;//int
    lastDate = 0;//int
    currPay = 0;//float
    lastPay = 0;//float
}

node::~node(){
    delete next;
    delete addr;
    delete comp;
}

int node::add(node * toAdd){
    int flag = 0;
    return flag;
}

int node::remove(){
    int flag = 0;
    return flag;
}
