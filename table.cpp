#include "table.h"
#include <typeinfo>


//set companies ** to null and arr size to 0;
table::table(){
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
//initializes companies **
//takes in table size, sets private member size to inputted size
//then goes through the new company * array and sets each head to null
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
//this is a testing function, if display all fires
//and everything is still null
//this will return a true
bool table::isEmpty(){
    int notNull = 0;
    for(int i = 0; i < size; ++i){
        if (companies[i]) ++notNull;
    }
    return (notNull) ? false : true;
}
//this takes a temp company node created in client
//and finds where it should be sorted based on hash
//goes to that address (companies + post hash sorting)
//then detects if that index has been assigned yet
//if it hasnt makes that index into a new company  and
//assigns it the values from temp
//if it has, it recurses down a LLL and adds to the end
//the length of the LLL is returned as the value of count-10,000
//the 10,000s are indicators of success
//on a larget data set this would be an issue, but for testing, it was nice
int table::addComp(company * temp){
    
    int count = 0;
    long int key = makeHash(temp->name,size);
    temp->key = key;
    int index = sortHash(key,size);
    if(!companies[index]){
        companies[index] = temp;
        ++count;
        return 0;
    }else{
        count += recAdd(companies[index]->next,temp);
    }
    return count;
}
//checks if head is taken
//if it is, immediately moves on, incrementing count in wrapper by 1
//if it isn't, head is assigned to temp and count is incremented by 10,000
int table::recAdd(company * & head, company * temp){
    if(head){
        return recAdd(head->next, temp)+1;//if head exists, move on
    }
    head = temp;
   return 10000;
}
//pay is a wrapper func for the recursive search
//passes search term and payment amout to the recursive pay 
bool table::pay(char term[],float paym){
    return recPay(companies[sortHash(makeHash(term,size),size)],term, paym);
}
//checks for !strcmp (strcmp returns 0, so !0 = true)
//if it pops, bool success is set to true
//currentDue has payment subtracted from it
//if current due is paid in full or overpaid
//the paid bool on the node is set to true
bool table::recPay(company * & head, char term[], float paym){
    if(!head) return false;
    bool succ = false;
    if(!strcmp(head->name,term)){
        head->disp();
        head->currDue -= paym;
        if(head->currDue <= 0) head->paid = true;
        succ = true;
    }else{
        succ = recPay(head->next, term, paym);
    }
    return succ;
}
//iterates through the array of nodes
//returns a count of all nodes found in recursive function
int table::dispAll(){
    int count  = 0;
    for(int i = 0; i < size; ++i){
       count += recDispAll(companies[i]);
    }
    return count;
}
//recurses through the whole hass table
//calling company->disp on each node
//for each node that exists it increments 
//count in the wrapper func
int table::recDispAll(company * head){
    if(!head) return 0;
    head->disp();
    return recDispAll(head->next) + 1;
}
//takes in a search term
//sorts it and checks if that hash has been made
//if it has, it begins recursing 
//if the success count has been incremented it returns true
bool table::disp(char term[]){
   int i = sortHash(makeHash(term,size),size); 
   if(!companies[i]) return false;
   int succ = 0;
   succ += recDisp(companies[i],term);
   return (succ) ? true : false;
}
//if !head, it instantly exits func
//then it checks for match, if match is found it
//return company->disp which has a value of 1;
//else it returns 0 and checks the next value
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
//make a hash given an arr of chars
//takes ascii values of char arr
//converts to int, multiplies them by 
//an increasing power of ten;
//then adds to a total hash long int
//finally multiplies that hash by 7
//could probably switch it out for anything
//7 seems fine
//then returns a long int/the size of the table
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
