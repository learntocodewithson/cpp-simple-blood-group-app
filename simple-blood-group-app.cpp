#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class User {
 string name, blood_group;
 int age, height, user_position = 0;

 public:
  User(){}
  User(string _name, int _age, int _height, string _blood_group) {
   name = _name;
   age = _age;
   height = _height;
   blood_group = _blood_group;
  }

  // getter
  string getName(){
   return name;
  }

  string getBloodGroup(){
   return blood_group;
  }

  int getAge(){
   return age;
  }

  int getHeight(){
   return height;
  }

  // setter
  void setName(string _name){
   name = _name;
  }

  void setBloodGroup(string _blood_group){
   blood_group = _blood_group;
  }

  void setAge(int _age){
   age = _age;
  }

  void setHeight(int _height){
   height = _height;
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

  void displayAll(){
   cout << "\nList of Users\n";
   string row_data;
   int counter = 0;

   ifstream Users("users.csv");
   cout << "\nPosition\tName\tAge\tHeight\tBlood Group\n";
   while(getline(Users, row_data)){
    counter++;

    istringstream scanner(row_data);
    string _age, _height;

    getline(scanner, name, ',');
    getline(scanner, _age, ',');
    getline(scanner, _height, ',');
    getline(scanner, blood_group);

    age = stoi(_age);
    height = stoi(_height);
 
    cout << counter << ".)\t\t" << name << "\t" << age << "\t" << height << "\t" << blood_group << endl;
 
   }

   Users.close();
  }

  string findRecordByPosition(int _user_position){
   ifstream Users("users.csv");
   string row_data, user_info = "";
   int counter = 0;

   while(getline(Users, row_data)){
    counter++;
    if(counter == _user_position){
      istringstream scanner(row_data);
      string _age, _height;
      user_position = _user_position;

      getline(scanner, name, ',');
      getline(scanner, _age, ',');
      getline(scanner, _height, ',');
      getline(scanner, blood_group);

      age = stoi(_age);
      height = stoi(_height);
   
      user_info = "\nFOUND USER\nName: " + name + "\nAge: " + _age + "\nHeight: " + _height + "\nBlood Group: " + blood_group + "\n";
    }
   }
   Users.close();

   return user_info;
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
 User user;
 int position_choice;
 string _name, _age, _height, _blood_group;
 // system("clear");
 cout << "==== Editing Record ====\n";
 user.displayAll();
 cout << "Enter the user's position: ";
 cin >> position_choice;
 cout << user.findRecordByPosition(position_choice);
 
 cout << "\nEdit name(" << user.getName() << ")[Type: N to keep the actual value]: ";
 cin >> _name;
 if(_name != "N" || _name != "n"){
  user.setName(_name);
 }

 cout << "\nEdit age(" << user.getAge() << ")[Type: N to keep the actual value]: ";
 cin >> _age;
 if(_age != "N" || _age != "n"){
  user.setAge(_age);
 }

 cout << "\nEdit height(" << user.getHeight() << ")[Type: N to keep the actual value]: ";
 cin >> _height;
 if(_height != "N" || _height != "n"){
  user.setHeight(_height);
 }

 cout << "\nEdit blood group(" << user.getBloodGroup() << ")[Type: N to keep the actual value]: ";
 cin >> _blood_group;
 if(_blood_group != "N" || _blood_group != "n"){
  user.setBloodGroup(_blood_group);
 }

 user.update();
}

void update(){
 // list users - loop and store data in struct array
 // open a new file users.csv
 // loop struct array (data)
 // loop and start adding the data again
 // while looping - match the position replace with new edited record
 // wait until the new record completed
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
