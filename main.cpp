#include <iostream>
using namespace std;
class BankAccount
{
private:
    int AccountNumber;
    string Name;
    int Balance;
public:
    BankAccount (int a=0,string b="0",int c=0)
    {

    }
    void OpenAccount()
    {
        cout<<"Insert the account number\n";cin>>AccountNumber;
        cout<<"Insert your name\n";cin>>Name;
        cout<<"Insert your opening balance\n";cin>>Balance;
    }
    void Deposit()
    {
        int a;
        cout<<"How much amount to be add to balance\n";
        cin>>a;
        Balance=Balance+a;
    }
    void Withdrawal()
    {
        int a;
        cout<<"How much amount to be withdrawn\n";
        cin>>a;
        if(a<=Balance)
            Balance=Balance-a;
        else
           {
            cout<<"You don't have available balance\n";
            while(a>Balance){
            cout<<"How much amount to be withdrawn\n";
            cin>>a;
           }
           Balance=Balance-a;
           }
    }
    int GetA()
    {
       return AccountNumber;
    }
    string GetN()
    {
        return Name;
    }
    int GetB()
    {
        return Balance;
    }
    void Search()
    {
        cout<<"The information for record "<<AccountNumber<<endl;
        cout<<"The name is "<<Name<<" ,the final balance is "<<Balance<<endl;
    }
};
class SaveAccount :public BankAccount
{
    double Rate=0.023;
    double Min_Balance=500.0;
public:
    void calcInterest()
    {
        double interest=0;
        if(GetB()>Min_Balance)
        {
          interest=GetB()*Rate;
          cout<<"The interest is "<<interest<<endl;
        }
        else
          cout<<"The interest is "<<interest<<endl;
    }
};
int main()
{
    SaveAccount s;
    s.OpenAccount();
    int ch;
    do
    {
    cout<<"When you want to deposit enter 1\n"
        <<"When you want to Withdrawal enter 2\n"
        <<"When you want to search your account enter 3\n"
        <<"When you want to see the interest enter 4\n"
        <<"When you want to exit enter 5\n";
    cin>>ch;
    if(ch==1)
        s.Deposit();
    else if(ch==2)
        s.Withdrawal();
    else if(ch==3)
        s.Search();
    else if(ch==4)
        s.calcInterest();
    cout<<"*******************\n";
    }while(ch!=5);

    return 0;
}
