#include "table.h"
#include <fstream> //probably goes here


client::client(){
    myTable = NULL;
    temp = NULL; 
    init();
}



client::~client(){
    delete myTable;
}

//file comes in at init
//go through entire system, 
//populate array
//int client::init(char inpFile[]){
int client::init(){
    int flag = 0;
    int tblSize = 0;
    cout << "\nHow Big do you want your table: ";
    cin >> tblSize;
    cin.clear();
    myTable = new table;
    //while there are new lines, keep firing table init
    //maybe a second populate functiong
    myTable->init(tblSize);
    populate();
    //populate(inpFile,tblSize);
    return flag;
}
//need to add eof stop
//int client::populate(char inpFile[],int tblSize){
int client::populate(){
    company * temp = new company;
    int flag = 0;
    ifstream fin;
    fin.open("data.txt");
    //fin.open(inpFile);
    if(!fin) return flag;
    while(fin && !fin.eof()){
        for(int i = 0; i < 10;++i){

            temp->addr = new char[50];
            temp->name = new char[50];
            char numToExtract[100];

            fin.get(temp->name,49,'|');//1
            fin.ignore(100,'|');

            fin.get(temp->addr,49,'|');//2
            fin.ignore(100,'|');

            fin.get(numToExtract,15,'|');//3
            fin.ignore(100,'|');
            temp->phon = numExtract(numToExtract);

            fin.get(numToExtract,15,'|');//4
            fin.ignore(100,'|');
            temp->acct = numExtract(numToExtract);

            fin.get(numToExtract,15,'|');//5
            fin.ignore(100,'|');
            temp->lastDate = numExtract(numToExtract);

            fin.get(numToExtract,15,'|');//6 float
            temp->currDue = numExtract(numToExtract)/100;
            fin.ignore(100,'|');

            fin.get(numToExtract,15,'|');//7 float
            temp->lastPay = numExtract(numToExtract)/100;

            myTable->addComp(temp);
            temp->disp();
            temp = NULL;
            ++flag;
        }
    }
    delete temp;
    fin.close();
    return flag;
}
void client::dispAll(){
    myTable->dispAll();
}





