#include "table.h"
#include <cstring>
//John Bedette, cs163, p3
//a totally open company node class, contains a disp



//initializes and sets to null/0
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



//gets in there and deletes dyn arrs
company::~company(){
    if(name) delete name;
    if(addr) delete addr;
    if(lastDate) delete lastDate;
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
