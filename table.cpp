#include "table.h"
#include <typeinfo>



table::table(){
    //cerr << "\ncreating table\n";
    companies = NULL;
    size = 0;
}
//both seem to work the same
table::~table(){
    int count = 0;
    for(int i = 0; i < size; ++i){
        if(companies[i]){
            cerr << "\nRecDest: ";
            count += recDest(companies[i]);
        }
    }
    cerr << "\n#destroyed: " << count;
    delete companies;
}
int table::recDest(company * & head){
    if(!head) return 0;
    int flag = 0;
    if(head->next)flag+= recDest(head->next);
    delete head;
    ++flag;
    return flag;
}
/*
table::~table(){
    for(int i = 0; i < size; ++i){
        if(companies[i]){
            delete companies[i];
        }
    }
    delete companies;
}
*/
//need to make companies values NULL
int table::init(int tblSize){
    if(!tblSize)return 0;
    int flag = 0;
    size = tblSize;
    companies = new company * [size];
    for( int i = 0; i < size; ++i){
        companies[i] = NULL;
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
    
    int count = 0;
    long int key = makeHash(temp->name,size);
    temp->key = key;
    int index = sortHash(key,size);
    if(!companies[index]){
        companies[index] = new company;
        companies[index] = temp;
        ++count;
        return 0;
    }else{
        count += recAdd(companies[index]->next,temp);
    }
    return count;
}
int table::recAdd(company * & head, company * temp){
    if(head){
        return recAdd(head->next, temp)+1;//if head exists, move on
    }
    head = new company;
    head = temp;
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
    cerr << "\nDispAll";
    int count  = 0;
    for(int i = 0; i < size; ++i){
       count += recDispAll(companies[i]);
    }
    return count;
}
int table::recDispAll(company * head){
    if(!head) return 0;
    head->disp();
    return recDispAll(head->next) + 1;
}
bool table::disp(char term[]){
   int i = sortHash(makeHash(term,size),size); 
   if(!companies[i]) return false;
   int succ = 0;
   succ += recDisp(companies[i],term);
   return (succ) ? true : false;
}
int table::recDisp(company * head,char term[]){
    if(!head) return 0;
    if(!strcmp(head->name, term))return head->disp();
    else return recDisp(head->next,term) + 0;
}
int table::del(char term[]){
    int i = sortHash(makeHash(term,size),size);
    company * head = companies[i];
    if(!head) return 0;
    if(!head->next){
        delete companies[i];
        companies[i] = NULL;
        return 1;
    }
    int succ = 0;
    succ += recDel(companies[i]->next,companies[i],term);
    return succ;
}
int table::recDel(company * & head, company * & prev,char term[]){
    if(!head) return 0; 
    int flag = 0;
    if(!strcmp(head->name,term)){
        //ll is being broken/changes not saved
        cerr << "\nprev->n: " << prev->next;
        prev->next = head->next;
        cerr << "\nprev->n: " << prev->next;
        delete head; 
        head = NULL;
        ++flag;
    }else{
        recDel(head->next,head,term);
    }
    return flag;
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
