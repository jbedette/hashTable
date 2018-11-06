using namespace std;
/* needed data:
 * mailing address,business, char
 * phone number,businees, int
 * account number, business, int
 * amount currently being paid, bill?
 * last payment amout, business
 * date of last payment, business
 */
//rename table.h

class company{
    public:
        company();
        ~company();
        int addValue(company * toAdd);
        //int disp(company * & toDisp);
        int disp();
    private:
        char * name;
        char * addr;
        int phon;
        int lastDate;
        float lastPay;
        float currDue;
}
class table{
    public:
        table();
        ~table();
        int init(int sizeArr);
        int addComp();
        int dispAll();
        int findHash();
        long int makeHash(char name[], int max);
        long int sortHash(long int hash, int arrLen);
    private:
        int * hashBrkPts;
        company * companies;
};

class client{
    public:
        client();
        ~client();
        int init();//create new arr of companies
    private:
        table * myTable;//placeholder
};




