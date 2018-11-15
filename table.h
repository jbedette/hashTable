#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
// John Bedette, cs163, project 3
/* flow, client interacts with user and ext files
 * feeds data to table class
 * table manages an array of company class object pointers
 */


//company struct
//needs to be versatile and public
struct company{
        company();//create and set values to null/0
        ~company();//deallocate all dyn arrs
        int disp(); //displays a node's values
        company * next;//node functionality
        long int key;//big nasty hash key
        char * name;//1
        char * addr;//2
        long int phon;//3
        int acct;//4
        char * lastDate;//5
        float lastPay;//6
        float currDue;//7
        bool paid;//is there outstanding balance
};


//all data flows through and is protected by the table function
class table{
    public:
        table();//init table to null, size to 0;
        ~table();//destroy table arr, make sure to totally scrape clean ll
        int init(int sizeArr);//takes size from client, sets mytable to new company * arr[size]
        int addComp(company * temp);//general adding func, takes temp company, assigns pointer to that
        int dispAll();//show everything, calls recursive functions,wrapper
        bool isEmpty();//test to make sure table thing is empty
        bool pay(char term[], float paym);//edits reuquested node, wrapper
        int del(char term[]);//deletes specific node, wrapper
        bool disp(char term[]);// displays specific node, wrapper
        //hash stuff
        long int makeHash(char name[], int max);//outputs a large integer based on company name
        long int sortHash(long int hash, int arrLen);//outputs an index within array bounds
    private:
        //recursives
        int recDest(company * & head);//recursive destroy. better safe than sorry
        int recAdd(company * & head, company * temp);//tests if node is valid for insertion, inserts
        bool recPay(company * & head, char term[], float paym);//finds correct node, modifies it
        int recDel(company * & head, char term[]);//find correct node, removes it
        int recDisp(company * head, char term[]);//finds correct node, displays it
        int recDispAll(company * head);//finda all
        //
        company ** companies;
        int size;//array size
};

class client{
    public:
        client();//init table & populate
        ~client();//begins destroy chain
        int init();//create new arr of companies
        int populate();//reads from ext, feeds into tbl
        void dispAll();//wrapper, displays all
        void pay();//takes search term, passes to table
        void del();//takes serch term, passes to table
        void add();//user inputs a new company, passes temp to table
        void disp();//takes search term, passes to table
        void menu();//user interface
    private:
        table * myTable;
        company * temp;
};




