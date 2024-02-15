#include "SimpleBloodGroup.h"

void addNewRecord(User &user);
void editRecord(User &user);
void deleteRecord(User &user);
void searchRecordByBloodGroup(User &user);
void displayAllUsers(User &user);

int main() {
 User user;
 int choice;
 bool exit_choice = 0;

 cout << "==== Simple Blood Group APP ====";
 
 do {
  cout << user.displayMenu();
  cout << "\nEnter Your Choice: ";
  cin >> choice;
  system("clear");
  switch(choice){
   case 1:
    addNewRecord(user);
    break;
   case 2:
    editRecord(user);
    break;
   case 3:
    deleteRecord(user);
    break;
   case 4:
    searchRecordByBloodGroup(user);
    break;
   case 5:
    displayAllUsers(user);
    break;
   default:
    exit_choice = 1;
    cout << "\nThank your for using this app.";
  }

 } while(!exit_choice);
 
 return 0;
}

void addNewRecord(User &user){
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

 user.setName(name);
 user.setAge(age);
 user.setHeight(height);
 user.setBloodGroup(blood_group);
 user.save();
}

void editRecord(User &user){
 int position_choice;
 string _name, _age, _height, _blood_group;
 
 cout << "==== Editing Record ====\n";
 user.displayAll();
 cout << "Enter the user's position: ";
 cin >> position_choice;
 cout << user.findRecordByPosition(position_choice);
 
 cout << "\nEdit name(" << user.getName() << ")[Type: N or n to keep the actual value]: ";
 cin >> _name;
 if(_name != "N" && _name != "n"){
  user.setName(_name);
 }

 cout << "\nEdit age(" << user.getAge() << ")[Type: N or n to keep the actual value]: ";
 cin >> _age;
 if(_age != "N" && _age != "n"){
  user.setAge(stoi(_age));
 }

 cout << "\nEdit height(" << user.getHeight() << ")[Type: N or n to keep the actual value]: ";
 cin >> _height;
 if(_height != "N" && _height != "n"){
  user.setHeight(stoi(_height));
 }

 cout << "\nEdit blood group(" << user.getBloodGroup() << ")[Type: N or n to keep the actual value]: ";
 cin >> _blood_group;
 if(_blood_group != "N" && _blood_group != "n"){
  user.setBloodGroup(_blood_group);
 }

 user.update();
}

void deleteRecord(User &user){
 int position_choice;
 string yes_or_no;
 bool yes_or_no_answer = 0;

 cout << "==== Deleting Record ====";
 user.displayAll();

 cout << "Enter the user's position: ";
 cin >> position_choice;

 cout << user.findRecordByPosition(position_choice);

 while(!yes_or_no_answer){
  cout << "Are you sure you want to delete " << user.getName() << "? <yes or no>: ";
  cin >> yes_or_no;

  if(yes_or_no == "yes"){
    user.deleteUser();
    cout << endl << user.getName() << " is now deleted.\n";
    yes_or_no_answer = 1;
  }else if (yes_or_no == "no"){
    cout << endl << user.getName() << " is not deleted.\n";
    yes_or_no_answer = 1;
  }else{
    cout << endl << "Please answer yes or no only.\n\n";
  }
 }
}

void displayAllUsers(User &user){
  cout << "==== All Users ====";
  user.displayAll();
}

void searchRecordByBloodGroup(User &user){
 string blood_group;
 cout << "==== Search Record By Blood Group ====";
 cout << "\nEnter Blood Group: ";
 cin >> blood_group;

 user.searchRecordsByBloodGroup(blood_group);
}
