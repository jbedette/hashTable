#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//made my company node a totally public class
//struct is nice, but with all these assigned values
//I wanted the cleanliness of a class's destructor

class company{
    public:
        company();
        ~company();
        int disp(); 
        int addValue(company * toAdd);
        company * next;
        long int key;
        char * name;//1
        char * addr;//2
        long int phon;//3
        int acct;//4
        char * lastDate;//5
        float lastPay;//6
        float currDue;//7
        bool paid;
    private:
};
class table{
    public:
        table();
        ~table();
        int init(int sizeArr);
        int addComp(company * temp);
        int dispAll();
        bool isEmpty();
        bool pay(char term[], float paym);
        int del(char term[]);
        bool disp(char term[]);
        //hash stuff
        long int makeHash(char name[], int max);
        long int sortHash(long int hash, int arrLen);
    private:
        int recDest(company * & head);
        int recAdd(company * & head, company * temp);
        bool recPay(company * & head, char term[], float paym);
        int recDel(company * & head, company * & prev, char term[]);
        int recDisp(company * head, char term[]);
        int recDispAll(company * head);
        company ** companies;
        int size;
};

class client{
    public:
        client();
        ~client();
        //int init(char inpFile[]);//create new arr of companies
        int init();//create new arr of companies
        int populate();
        void dispAll();
        void pay();
        void del();
        void add();
        void disp();
        void menu();
    private:
        table * myTable;
        company * temp;
};




