#include "table.h"
#include <fstream>
//John Bedette, cs163, p3
//client interacts with the user and ext files



//initializes table
client::client(){
    myTable = NULL;
    temp = NULL; 
    init();
}


//starts delete chain
client::~client(){
    delete myTable;
}



//initialize table
//get size to make table
//feeds size into table
//feeds data from ext file into 
//table with populate
int client::init(){
    int count = 0;
    int tblSize = 1;
    cout << "\nHow Big do you want your table: ";
    cin >> tblSize;
    cin.clear();
    cin.ignore(100,'\n');
    myTable = new table;
    myTable->init(tblSize);
    count += populate();
    cout << "\nNumber of items added: " << (count+1)%10000;
    return count;
}




//a real nasty function
//reads data from ext file
//feeds into a temp company
//company is passed into the table
//table ptrs are assigned to the temp
//temp is assigned to null
//then temp is made into a new temp company
//the process repeats
//indicates whether all ext file items are successfully
//read in and returns total count
int client::populate(){
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
        
        temp->addr = new char[strlen(addr)+1];
        temp->name = new char[strlen(name)+1];
        temp->lastDate = new char[strlen(lastDate) +1];
        strcpy(temp->name,name);
        strcpy(temp->addr,addr);
        strcpy(temp->lastDate,lastDate);

        count += myTable->addComp(temp);
        temp = NULL;
    }
    fin.close();
    if(!(count-index)) cout << "\nAll items succesfully added.";
    return count;
}



//essentially wrapper function for table display, checks first if table has been
//filled properly
void client::dispAll(){
    if(myTable->isEmpty()) cout << "\nTable is totally empty\n";
    int count = myTable->dispAll();
    cout << "\n# of bills: " << count;
}



//takes input from user to pass to pay functon
//need payment float * search term
void client::pay(){
    char term[50];
    float paym = 0; 
    cout << "\nPlease enter the EXACT name of the company you would like to make a payment on: ";
    cin.get(term,49,'\n');
    cin.ignore(50,'\n');
    cout <<"\nEnter the amount to be paid: ";
    cin >> paym;
    if(myTable->pay(term,paym)){
        cout << "\nPayment Successful";
        myTable->disp(term);
    }else{ 
        cout << "\nError: payment failed";
    }
}



//takes term to search for for deletion
//displays success and failure 
void client::del(){
    char term[50];
    cout << "\nEnter company to delete: ";
    cin.get(term,49,'\n');
    if(myTable->del(term)) cout << "\nCompany deleted";
    else cout << "\nDelete failed, did you enter the correct company name?";
}



//takes in a client defined company
//passes to table
//displays success/fail
//sets temp to null
void client::add(){
    //possibly get rid of
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
    if(myTable->addComp(temp)){
        cout << "\nCompany Added: ";
        myTable->disp(name);
    }
    else cout << "\nError: adding company failed";
    temp = NULL; 
}



//takes search term from client
//feeds to table
//displays errors
void client::disp(){
    char term[50];
    cout << "\nCompany to display: ";
    cin.get(term,49,'\n');
    cin.clear();
    cin.ignore(100,'\n');
    if(!myTable->disp(term)) cout << "\nCompany not found";
}



//calls itself thru tail recursion if e is not inputted
void client::menu(){
    char opt = ' ';
    while(opt != 'e'){
        opt = ' ';
        cout << "\nWelcome to my hash table, would you like to: ";
        cout << "\n--[D]isplay all bills?";
        cout << "\n--[S]ee only one bill?";
        cout << "\n--[A]dd a new bill?";
        cout << "\n--[P]ay a bill?";
        cout << "\n--[R]emove a bill?";
        cout << "\n--[E]xit?\n";
        cin >> opt;
        cin.clear();
        cin.ignore(100,'\n');
        opt = tolower(opt);
        if(opt == 'd')dispAll();
        if(opt == 's')disp();
        if(opt == 'a')add();
        if(opt == 'p')pay();
        if(opt == 'r')del();
    }
    cout << "\nGoodbye";
}



