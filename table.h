#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
/* needed data:
 * mailing address,business, char
 * phone number,businees, int
 * account number, business, int
 * amount currently being paid, bill?
 * last payment amout, business
 * date of last payment, business
 */

//made my company node a totally public class
//struct is nice, but with all these assigned values
//I wanted the cleanliness of a class's destructor

class company{
    public:
        company();
        ~company();
        int addValue(company * toAdd);
        int disp(); 
        //if class needs to be private
        ////because company is a class, need func to retrieve name
        int assignKey(long int inpkey);
        char * getName(company * temp);
        long int getKey();
        //
        company * next;
        long int key;
        char * name;//1
        char * addr;//2
        long int phon;//3
        int acct;//4
        int lastDate;//5
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
        int recAdd(company * & head, company * temp);
        int dispAll();
        int recDispAll(company * head);
        int findHash();
        long int makeHash(char name[], int max);
        long int sortHash(long int hash, int arrLen);
        int setHashBrkPts();
        bool isEmpty();
        bool pay(char term[], float paym);
        bool recPay(company * & head, char term[], float paym);
    private:
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
    private:
        table * myTable;
        company * temp;
};




