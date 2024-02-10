#include<iostream>
#include<string>
#include <sstream>
#include <fstream>
using namespace std;

class User {
 string name, blood_group;
 int age, height;

 public: 
  User(string _name, int _age, int _height, string _blood_group) {
   name = _name;
   age = _age;
   height = _height;
   blood_group = _blood_group;
  }

  void save(){
   ofstream Users("users.csv", ios::app);
   if(Users.is_open()){
    Users << name << "," << age << "," << height << "," << blood_group << endl;
    
    Users.close();
    
    cout << "\nNew record has been successfully added.\n";
   }else {
    cerr << "\nUnable to create and open a file";
   }
  }
};


void displayMenu(){
 cout << "\n1. Add New Record\n2. Edit Record\n3. Delete Record\n4. Search Record by group\n5. Exit";
}

void addNewRecord(){
 string name, blood_group;
 int age, height;

 cout << "==== Adding New Record ====";
 
 cout << "\nEnter your name: ";
 cin >> name;

 cout << "Enter your age: ";
 cin >> age;

 cout << "Enter your height: ";
 cin >> height;

 cout << "Enter your Blood Group: ";
 cin >> blood_group;

 User user(name, age, height, blood_group);

 user.save();
}

void editRecord(){
 cout << "==== Editing Record ====";
}

void deleteRecord(){
 cout << "==== Deleting Record ====";
}

void searchRecordByGroup(){
 cout << "==== Search Record By Group ====";
}

int main() {
 int choice;
 bool exit_choice = 0;

 cout << "==== Simple Blood Group APP ====";
 
 do {
  displayMenu();
  cout << "\nEnter Your Choice: ";
  cin >> choice;

  switch(choice){
   case 1:
    addNewRecord();
    break;
   case 2:
    editRecord();
    break;
   case 3: 
    deleteRecord();
    break;
   case 4:
    searchRecordByGroup();
    break;
   default:
    exit_choice = 1;
    cout << "\nThank your for using this app.";
  }

 } while(!exit_choice);
 
 return 0;
}
