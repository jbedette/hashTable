#include "table.h"
#include <cstring>

company::company(){
    next = NULL;
    name = NULL;
    addr = NULL;
    lastDate = NULL;
    key = 0;
    phon = 0;
    lastPay = 0;
    currDue = 0;
    paid = false;
}
company::~company(){
    //cerr << "->dest:" << name;
    if(name) delete name;
    if(addr) delete addr;
    if(lastDate) delete lastDate;
}
//addVal is probs unnecessary
//it's a relic of an older version
//where company had private members
//THE AGE OF PRIVACY IS OVER
//ALL HAIL BIG DATA
int company::addValue(company * toAdd){
    int flag = 0;
    if(!toAdd) return flag;
    name = new char[strlen(toAdd->name)+1];
    addr = new char[strlen(toAdd->addr)+1];
    lastDate = new char[strlen(toAdd->lastDate) + 1];
    if(strcpy(name, toAdd->name))++flag;//1
    if(strcpy(addr, toAdd->addr))++flag;//2
    if(strcpy(lastDate,toAdd->lastDate))++flag;//3
    phon = toAdd->phon;
    key = toAdd->key;
    acct = toAdd->acct;
    lastPay = toAdd->lastPay;
    currDue = toAdd->currDue;
    if(lastPay == toAdd->lastPay)++flag;//4
    if(currDue == toAdd->currDue)++flag;//5
    if(acct == toAdd->acct)++flag;//6
    if(phon == toAdd->phon)++flag;//7
    return flag;
}
//company display
//fairly self explanatory
//seemed kinda crazy to feed values to client
//decided a disp on here cout'ing data was fine
int company::disp(){ 
    cout 
        << "\nName: "<< name
        << "\n==========="
        << "\nAddr: "<< addr
        << "\nPhon: " << phon
        << "\nLastDate: " << lastDate
        << "\nLastPay: " << lastPay
        << "\nCurrDue: " << currDue
        << "\nPaid: ";
    (paid) ? cout << "true" : cout << "false";
    cout << "\n===========\n";
   return 1;
}
