#include "table.h"
#include <cstring>

company::company(){
    name = NULL;
    addr = NULL;
    key = 0;
    phon = 0;
    lastDate = 0;
    lastPay = 0;
    currDue = 0;
}
company::~company(){
    delete name;
    delete addr;
}
int company::addValue(company * toAdd){
    int flag = 0;
    if(!toAdd) return flag;
    name = new char[strlen(toAdd->name)+1];
    addr = new char[strlen(toAdd->addr)+1];
    if(strcpy(name, toAdd->name))++flag;
    if(strcpy(addr, toAdd->addr))++flag;
    phon = toAdd->phon;
    lastDate = toAdd->lastDate;
    lastPay = toAdd->lastPay;
    currDue = toAdd->currDue;
    if(phon == toAdd->phon)++flag;
    if(lastDate == toAdd->lastDate)++flag;
    if(lastPay == toAdd->lastPay)++flag;
    if(currDue == toAdd->currDue)++flag;
    return flag;
}
//I guess I could feed in somethign from client to disp
//int company::disp(company * & toDisp){
int company::disp(){
   //temp disp, need to switch to write to fed in  
    cerr 
        << "\nName: "<< name
        << "\nAddr: "<< addr
        << "\nPhon: " << phon
        << "\nLastDate: " << lastDate
        << "\nLastPay: " << lastPay
        << "\nCurrDue: " << currDue
        << "\n";
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
