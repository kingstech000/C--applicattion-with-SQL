#include <iostream>
using namespace std;

class User{
	public: 
	 char fname[30];
	 char lname[30];
	 char password[16];
	 char cpassword[16];
	 int phone[11];
	 char email[30];
	
};
int main(){
	cout << "Welcome --Enter your credentials to sign in" << endl;
	User user1;
	cout << "Enter Firstname: ";
    cin >> user1.fname;
    cout << '\n';
    cout << "Enter Lastname: ";
    cin >> user1.lname;
    cout << '\n';
    cout << "Enter password: ";
    cin >> user1.password;
    cout << '\n';
    cout << "Confirm password: ";
    cin >> user1.cpassword;
    cout << '\n';
    cout << "Enter phone number: ";
    cout << '\n';
    cout << "Enter email: " << endl;
    cout << "press enter to continue";
    
    cin.get();
    return 0;
}
