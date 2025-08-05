
#include <iostream>
#include<string>
#include<vector>
using namespace std;

class user{
public:
    string name;
    string phonenumber;
    string  email;



    void input(){
        cin.ignore();
    cout<<"enter name "<<endl;
    getline(cin,name);

    cout<<"enter phonenumber: "<<endl;
    getline(cin,phonenumber);
    cout<<"enter email: "<<endl;
    getline(cin,email);


    }

    void output(){

    cout<<"name is : "<<name<<endl;
    cout<<"phonenumber is :"<<phonenumber<<endl;
    cout<<"email is :"<<email<<endl;


    }



};


class telephonelist{
public:
   vector<user>contacts;

   //create contact
   void createcontact( ){
       user newuser;
       newuser.input();
       contacts.push_back(newuser);
       cout<<"contact create  successfully"<<endl;

   }


   //display contacts

   void getcontact() {
    if (contacts.empty()) {
        cout << "No contact found!" << endl;
        return;
    }

    cout << "All contact lists are:" << endl;
    for (int i = 0; i < contacts.size(); i++) {
        cout << i + 1 << ": ";
        contacts[i].output();
        cout << endl;
    }
}


   //update  contact
   void editcontact(){
       string name;
       bool found=false;
   cout<<"enter contact's name you want to edit: "<<endl;
   cin>>name;
   for( auto itr=contacts.begin();itr!=contacts.end();itr++){
    if(itr->name==name){
        itr->input();
        itr->output();
        found=true;
        break;

    }

   }
   if(found==false){
    cout<<"no contact is found with this name :"<<name;
   }


   }

//delete contact
 void deletecontact() {
        string name;
        cout << "enter the name you want to delete: ";
        cin >> name;

        bool found = false;

        for (auto i= contacts.begin(); i != contacts.end(); i++) {
            if (i->name == name) {
                contacts.erase(i);
                cout << "Contact " << name << " is deleted." << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No contact found with the name :" << name << "." << endl;
        }
    }


void searchcontact(){
    string name;

cout<<"enter name you want to search....."<<endl;
cin>>name;
bool found=false;
for(auto itr=contacts.begin();itr!=contacts.end();itr++){
    if(itr->name==name){
        itr->output();
        found=true;
        break;
    }

}

if(!found){
    cout<<name<<" is not found in your telephone book "<<endl;
}



}


};

int main() {
    loginSystem loginSys;
    telephonelist t;

    int option;
    string username, password;
    bool isLoggedIn = false;

    cout << "Welcome to Telephone Book App" << endl;
    cout << "1. Register\n2. Login\nChoose option: ";
    cin >> option;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (option == 1) {
        if (loginSys.registerUser(username, password)) {
            cout << "Registered Successfully!" << endl;

            // Ask to login after successful registration
            cout << "Please login to continue." << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (loginSys.login(username, password)) {
                cout << "Login successful!" << endl;
                isLoggedIn = true;
            } else {
                cout << "Login failed!" << endl;
                return 0;
            }
        } else {
            cout << "Registration failed!" << endl;
            return 0;
        }
    } else if (option == 2) {
        if (loginSys.login(username, password)) {
            cout << "Login successful!" << endl;
            isLoggedIn = true;
        } else {
            cout << "Login failed!" << endl;
            return 0;
        }
    } else {
        cout << "Invalid option!" << endl;
        return 0;
    }

    //  Only show telephone menu if user is logged in
    if (!isLoggedIn) {
        cout << "You must login first to access contacts." << endl;
        return 0;
    }

    // Now show the telephone book menu
    int choice;
    do {
        cout << "\nTelephone Book Menu:\n";
        cout << "1 -> Create Contact\n";
        cout << "2 -> Display All Contacts\n";
        cout << "3 -> Update Contact\n";
        cout << "4 -> Delete Contact\n";
        cout << "5 -> Search Contact\n";
        cout << "6 -> Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                t.createcontact();
                break;
            case 2:
                t.getcontact();
                break;
            case 3:
                t.editcontact();
                break;
            case 4:
                t.deletecontact();
                break;
            case 5:
                t.searchcontact();
                break;
            case 6:
                cout << "Thanks for using Telephone Book!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

    } while (choice != 6);

    return 0;
}


