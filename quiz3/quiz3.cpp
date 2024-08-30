#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct creditCard {
    int cardNum;
    double balance;
};

vector<creditCard> readCreditCardRec();
creditCard gLB (vector<creditCard>ccV);
string cardNumToRevStr(creditCard cc);

int main ()
{
   vector <creditCard> cc = readCreditCardRec();
   creditCard ccTemp;
   ccTemp = gLB(cc);

   cout << ccTemp.cardNum << " ";
   cout << ccTemp.balance << endl;

   // Test cardNumToRevStr function
    cout << "Reversed Card Number String: " << cardNumToRevStr(ccTemp) << endl;
}

vector<creditCard> readCreditCardRec()
{
    ifstream ccRec;
    ccRec.open("CreditCardRecord.txt");
    creditCard ccTemp;
    vector <creditCard> cc;
    if (ccRec.is_open())
    {
        while (!ccRec.eof())
        {
            ccRec >> ccTemp.cardNum;
            ccRec >> ccTemp.balance;
            cc.push_back(ccTemp);
        }
    }
    else
    {
        cout << "failed";
    }
    ccRec.close();
    return cc;
}

creditCard gLB (vector<creditCard>ccV)
{
    creditCard ccTemp1 = ccV.at(0), ccTemp2;
    for (int i = 1; i < ccV.size();i++)
    {
        ccTemp2 = ccV.at(i);
        if (ccTemp2.balance < ccTemp1.balance)
        {
            ccTemp1 = ccTemp2;
        }
    }
    return ccTemp1;
}

string cardNumToRevStr(creditCard cc)
{
    string result;
    int num = cc.cardNum;
    while (num > 0)
    {
        int digit = num%10;
        result = result + static_cast<char>(digit + 0x30);
        num /= 10;
    }
    return result;
}


