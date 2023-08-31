#include<iostream>
#include<string> 
using namespace std;

struct Account{
    string name;
    Account (const string &s):name(s){}
    virtual ~Account() {}
    void showName(){
        cout<<"Account name is"<<name<<endl;
    }
    void adminStuff(){
        cout<<"not implemented"<<endl;
    }
   
};
struct UserAccount:Account{
    UserAccount(const string &s):Account(s){}
    virtual ~UserAccount(){}
    void adminStuff(){
        cout<<"Admin not premitted for user account"<<endl;
    }
};
struct AdminAccount:Account{
    AdminAccount(const string &s):Account(s){}
    virtual ~AdminAccount(){
    }
    void adminStuff(){
        cout<<"would do admin work in context of:"<<this->name<<endl;
    }
};

int main(int argc,const char *argv[]){
    UserAccount *user=new UserAccount(" us ");
    AdminAccount *admin=new AdminAccount(" adm");

    cout<<" admin check:"<<endl;
    admin->showName();
    admin->adminStuff();

    cout<<" user check"<<endl;
    user->showName();
    user->adminStuff();

    Account* account=static_cast<Account*> (user);
    AdminAccount *admin_it=static_cast<AdminAccount*>(account);

    admin_it->showName();
    cout<<"cfi should prevent the actions below:"<<endl;
    admin_it->adminStuff();

    return 0;
}