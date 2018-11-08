#include "table.h"



table::table(){
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
    companies = new company[size];
    if(!companies[0].next) cerr << "\nWow i'm drunk/!nextnull\n";
    /*
    for( int i = 0; i < size; ++i){
        companies + i = NULL;
    }
    */
    return flag;
}
bool table::isEmpty(company * head){
    return ( head->name && head->key && head->addr ) ? true : false;
}
int table::addComp(company * temp){
    if(!temp){
        cerr << "\n!temp\n";
        return 0;
    }
    long int key = makeHash(temp->name,size);
    temp->key = key;
    int index = sortHash(key,size);
    company * head = companies + index ;
    if(!head){
        cerr << "\n!head\n";
        return 0;
    }
    if(isEmpty(head)){
        cerr << "\nisEmpty = true\n";
        if(head->addValue(temp)== 7) cout << "\nSuccessfully Added\n";
    }else{
        cerr << "\nisEmpty = false\n";
        recAdd(head->next,temp);
    }
    return 0;
}
int table::recAdd(company * & head, company * temp){
    if(head) return recAdd(head->next, temp)+1;//if head exists, move on
    head = new company;
    head->addValue(temp);
    return 10000;
}
int table::dispAll(){
    cerr <<"\ndispAll\n";
    int count  = 0;
    companies[0].disp();
    /*
    for(int i = 0; i < size; ++i){
       count += recDispAll(companies+i);
    }
    */
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
long int table::makeHash(char name[], int max){    long int hash = 0;
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
/*
//I dont think i need this
int table::setHaskBrkPts(int long maxHash){
    hashBrkPts = new brkpt[size];
    brkpt[0]->min = 0;
    brkpt[0]->max = maxHash/size;

}
*/
