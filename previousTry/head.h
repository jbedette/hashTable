#include <iostream>
#include <cstring>
/*
 * mailing address,business, char
 * phone number,businees, int
 * account number, business, int
 * amount currently being paid, bill?
 * last payment amout, business
 * date of last payment, business
 * 
 */
using namespace std;
//keypair
struct keypair{
    int key;
    char * text;
    int intVal;
    float floatVal;
};
//node class
class node{
    public:
        node();
        ~node();
        int add(node * toAdd);
        int removeNode();
    private:
        node * next;
        char * addr;
        char * comp;
        int key;
        int phon;
        int acct;
        int lastDate;
        float currPay;
        float lastPay;
};
//takes care of adding removing calls
class table{
    public:
        table();
        ~table();
        int init();
        int add(node * toAdd);
    private:
        node * head;
};
//interacts with user
//handles data input
//might not need this
class client{
    public:
        client();
        ~client();
        int init();
        int populate();
    private:
        table * myTable;
};





