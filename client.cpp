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
    int tblSize = 1;
    cout << "\nHow Big do you want your table: ";
    cin >> tblSize;
    cin.clear();
    myTable = new table;
    myTable->init(tblSize);
    cout << "\nNumber of items added: " << populate();
    //populate(inpFile,tblSize);
    return flag;
}
//int client::populate(char inpFile[],int tblSize){
int client::populate(){
    cerr << "\nclient.populate\n";
    company * temp;
    int count = 0;
    ifstream fin;
    fin.open("data2.txt");
    //fin.open(inpFile);
    if(!fin) return count;
    int index = 0;
    while(fin && fin >> index && !fin.eof()){
        fin.ignore(100,'|');
        temp = new company;
        //cerr <<"\nTemp: "<< temp;
        temp->addr = new char[50];
        temp->name = new char[50];


        fin.get(temp->addr,49,'|');//1
        fin.ignore(100,'|');

        fin.get(temp->name,49,'|');//2
        fin.ignore(100,'|');

        fin >> temp->acct;//3
        fin.ignore(100,'|');
        fin >> temp->phon;//4
        fin.ignore(100,'|');
        fin >> temp->lastDate;//5
        fin.ignore(100,'|');
        fin >> temp->currDue;//6
        fin.ignore(100,'|');
        fin >> temp->lastPay;//7
        fin.ignore(100,'\n');
        //cerr << "\nTemp.disp\n";
        //temp->disp();
        count += myTable->addComp(temp);
        temp = NULL;
    }
    delete temp;
    fin.close();
    return count;
}
void client::dispAll(){
    if(myTable->isEmpty()) cout << "\nTable is totally empty, fuck\n";
    cout << "\n# of bills: " << myTable->dispAll();
}
void client::pay(){
    char term[50];
    float paym = 0; 
    cout << "\n------->>Please enter the EXACT name of the company you would like to make a payment on: ";
    cin.get(term,49,'\n');
    cin.ignore(50,'\n');
    cout <<"\nEnter the amount to be paid: ";
    cin >> paym;
    myTable->pay(term,paym);
}


