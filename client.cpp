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
    return flag;
}
int client::populate(){
    cerr << "\nclient.populate\n";
    company * temp;
    int count = 0;
    ifstream fin;
    fin.open("data2.txt");
    if(!fin) return count;
    int index = 0;
    while(fin && fin >> index && !fin.eof()){
        fin.ignore(100,'|');

        temp = new company;
        char name[50];
        char addr[50];
        char lastDate[50];

        fin.get(addr,49,'|');//1
        fin.ignore(100,'|');
        fin.get(name,49,'|');//2
        fin.ignore(100,'|');
        fin >> temp->acct;//3
        fin.ignore(100,'|');
        fin >> temp->phon;//4
        fin.ignore(100,'|');
        fin.get(lastDate,49,'|');//5
        fin.ignore(100,'|');
        fin >> temp->currDue;//6
        fin.ignore(100,'|');
        fin >> temp->lastPay;//7
        fin.ignore(100,'\n');
        
        //cerr << "\nchar arrs b4 dyn set: " <<name<< ','<< addr<< ','<<lastDate;
        temp->addr = new char[strlen(addr)+1];
        temp->name = new char[strlen(name)+1];
        temp->lastDate = new char[strlen(lastDate) +1];
        strcpy(temp->name,name);
        strcpy(temp->addr,addr);
        strcpy(temp->lastDate,lastDate);
       // cerr << "\nTemp disp: " << temp->disp();

        count += myTable->addComp(temp);
        temp = NULL;
    }
    if(temp){
        delete temp->name;
        delete temp->addr;
        delete temp->lastDate;
        delete temp;
    }
    fin.close();
    return count;
}
void client::dispAll(){
    if(myTable->isEmpty()) cout << "\nTable is totally empty\n";
    int count = myTable->dispAll();
    cout << "\n# of bills: " << count;
}
void client::pay(){
    char term[50];
    float paym = 0; 
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\nPlease enter the EXACT name of the company you would like to make a payment on: ";
    cin.get(term,49,'\n');
    cin.ignore(50,'\n');
    cout <<"\nEnter the amount to be paid: ";
    cin >> paym;
    myTable->pay(term,paym);
}
void client::del(){
    char term[50];
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\nEnter company to delete: ";
    cin.get(term,49,'\n');
    if(myTable->del(term)) cout << "\nCompany deleted";
    else cout << "\nDelete failed, did you enter the correct company name?";
}
void client::add(){
    cin.clear();
    cin.ignore(100,'\n');
    company * temp = new company;
    char name[50];
    char addr[50];
    char lastDate[50];
    cout << "\nPlease enter company...";
    cout << "\n--name: ";
    cin.get(name,49,'\n');
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\n--address: ";
    cin.get(addr,49,'\n');
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\n--phone: ";
    cin >> temp->phon;
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\n--account: ";  
    cin >> temp->acct;
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\n--date of last payment: ";
    cin.get(lastDate,49,'\n');
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\n--amount of last payment: ";
    cin >> temp->lastPay;
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\n--current amount owed: ";
    cin >> temp->currDue;
    cin.clear();
    cin.ignore(100,'\n');
    temp->name = new char[strlen(name) +1];
    temp->addr = new char[strlen(addr) + 1];
    temp->lastDate = new char[strlen(lastDate) +1];
    strcpy(temp->name,name);
    strcpy(temp->addr,addr);
    strcpy(temp->lastDate,lastDate);
    if(!myTable->addComp(temp))cout << "\nError: adding company failed";
    myTable->disp(temp->name);
    temp = NULL; 
}
void client::disp(){
    char term[50];
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\nCompany to display: ";
    cin.get(term,49,'\n');
    cin.clear();
    cin.ignore(100,'\n');
    if(!myTable->disp(term)) cout << "\nCompany not found";
}

void client::menu(){
    char opt = ' ';
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\nWelcome to my hash table, would you like to: ";
    cout << "\n--[D[isplay all bills?";
    cout << "\n--[S]ee only one bill?";
    cout << "\n--[A]dd a new bill?";
    cout << "\n--[P]ay a bill?";
    cout << "\n--[R]emove a bill?";
    cout << "\n--[E]xit?\n";
    cin >> opt;
    cin.clear();
    cin.ignore(100,'\n');
    opt = tolower(opt);
    if(opt ==  'd')dispAll();
    if(opt == 's')disp();
    if(opt == 'a')add();
    if(opt == 'p')pay();
    if(opt == 'r')del();
    if(opt == 'e'){
        cout << "\nGoodbye";
        return;
    }
    return menu();
}



