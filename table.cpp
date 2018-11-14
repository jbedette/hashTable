#include "table.h"
#include <typeinfo>



table::table(){
    cerr << "\ncreating table\n";
    companies = NULL;
    size = 0;
}
table::~table(){
    delete companies;
}
//need to make companies values NULL
int table::init(int tblSize){
    int flag = 0;
    size = tblSize;
    companies = new company * [size];
    for( int i = 0; i < size; ++i){
        companies[i] = NULL;
        if(!companies[i])cerr   << "\nCompanies " << i << " is null: "
                                        << companies[i];
    }
    return flag;
}
//need to  check if i've made anything
bool table::isEmpty(){
    int notNull = 0;
    for(int i = 0; i < size; ++i){
        if (companies[i]) ++notNull;
    }
    return (notNull) ? false : true;
}

int table::addComp(company * temp){
    //cerr << "\ntable.addComp";
    
    int count = 0;
    long int key = makeHash(temp->name,size);
    temp->key = key;
    int index = sortHash(key,size);
    if(!companies[index]){
        cerr << "!head add";
        cerr << "\nHead index: " << index;
        companies[index] = new company;
        companies[index] = temp;
        ++count;
        //cerr << "\nHead->disp: " << companies[index]->disp();
        return 0;
    }else{
        cerr << "\nCompany[ind]: "<<companies[index];
        count += recAdd(companies[index]->next,temp);
    }
    return count;
}
int table::recAdd(company * & head, company * temp){
    //cerr << "\nTable.recAdd";
    if(head) return recAdd(head->next, temp)+1;//if head exists, move on
    head = new company;
    cerr << " added";
    head->addValue(temp);
    return 10000;
}
bool table::pay(char term[],float paym){
    return recPay(companies[sortHash(makeHash(term,size),size)],term, paym);
}
bool table::recPay(company * & head, char term[], float paym){
    if(!head) return false;
    bool succ = false;
    if(!strcmp(head->name,term)){
        head->disp();
        head->currDue -= paym;
        if(head->currDue <= 0) head->paid = true;
        succ = true;
        head->disp();
    }else{
        succ = recPay(head->next, term, paym);
    }
    return succ;
}
int table::dispAll(){
    cerr << "\ncompanies len: " << (sizeof(companies)/sizeof(companies[0]));
    cerr <<"\ndispAll\n";
    //companies[0]->disp();
    int count  = 0;
    for(int i = 0; i < size; ++i){
       count += recDispAll(companies[i]);
    }
    return count;
}
int table::recDispAll(company * head){
    cerr <<"\nRecdispAll\n";
    if(!head) return 0;
    head->disp();
    return recDispAll(head->next) + 1;
}


//hash browns
////make a hash given an arr of chars
long int table::makeHash(char name[], int max){    
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
//end of hashbrowns
