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

int main()
{

    telephonelist t;
    int choice;
    do{

       cout<<endl<<"telephone book list: "<<endl;
       cout<<" 1 -> create contact"<<endl;
       cout<<"2 ->  display all contact "<<endl;
       cout<<"3-> update contact"<<endl;
       cout<<"4-> Delete contact "<<endl;
       cout<<"5 -> search contact "<<endl;
       cout<<"6 -> exit "<<endl;
       cout<<"Enter your choice :"<<endl;
       cin>>choice;

       switch(choice){
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
        t.editcontact();
        break;

       case 5:
        t.searchcontact();
        break;

       case 6:
        cout<<"thanks for visting "<<endl;
        break;

         default:
        cout<<"invalid choice!"<<endl;
        break;
       }



    }
    while(choice<=6);


}
