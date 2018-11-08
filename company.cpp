#include "table.h"
#include <cstring>

company::company(){
    cerr << "\nAyyy i'm creatin heeeere\n";
    next = NULL;
    name = NULL;
    addr = NULL;
    key = 0;
    phon = 0;
    lastDate = 0;
    lastPay = 0;
    currDue = 0;
    paid = false;
}
company::~company(){
    delete name;
    delete addr;
}
int company::assignKey(long int inpkey){
    key = inpkey;
    return (key) ? 1 : 0;
}
int company::addValue(company * toAdd){
    int flag = 0;
    if(!toAdd) return flag;
    name = new char[strlen(toAdd->name)+1];
    addr = new char[strlen(toAdd->addr)+1];
    if(strcpy(name, toAdd->name))++flag;//1
    if(strcpy(addr, toAdd->addr))++flag;//2
    phon = toAdd->phon;
    key = toAdd->key;
    acct = toAdd->acct;
    lastDate = toAdd->lastDate;
    lastPay = toAdd->lastPay;
    currDue = toAdd->currDue;
    if(lastDate == toAdd->lastDate)++flag;//3
    if(lastPay == toAdd->lastPay)++flag;//4
    if(currDue == toAdd->currDue)++flag;//5
    if(acct == toAdd->acct)++flag;//6
    if(phon == toAdd->phon)++flag;//7
    return flag;
}
//company is class, to assign hash, need to
//have pub mem func to return name ptr
char * company::getName(company * temp){
    return temp->name;
}
int company::disp(){
   //temp disp, need to switch to write to fed in  
    cerr 
        << "\n==========="
        << "\nName: "<< name
        << "\nAddr: "<< addr
        << "\nPhon: " << phon
        << "\nLastDate: " << lastDate
        << "\nLastPay: " << lastPay
        << "\nCurrDue: " << currDue
        << "===========\n";
   return 0;
}
/*
company::
company::
company::
company::
company::
company::
company::
    int flag = 0;
    return flag;
*/
