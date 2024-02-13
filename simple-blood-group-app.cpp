#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class User {
 string name, blood_group;
 int age, height, user_position, users_count;

 public:
  User(){
    user_position = 0;
  }

  User(string _name, int _age, int _height, string _blood_group) {
   name = _name;
   age = _age;
   height = _height;
   blood_group = _blood_group;
   user_position = 0;
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

  void setUsersCount(){
    users_count = 0;
    string row_data;

    ifstream ReadUsers("users.csv");
    while(getline(ReadUsers, row_data)){ users_count++; }
    ReadUsers.close();
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

  void update(){

    setUsersCount();

    string row_data, temp_users[users_count];
    string formatted_user_data = name + "," + to_string(age) + "," + to_string(height) + "," + blood_group;
 
    int counter = 0;
    // read users.csv and store data in array of string
    ifstream ReadUsers("users.csv");
    while(getline(ReadUsers, row_data)){
      // while reading, when counter is match on the current position, replace
      if(counter == (user_position-1)){
        temp_users[counter] = formatted_user_data;
      }else{
        temp_users[counter] = row_data;
      }
      counter++;
    }
    ReadUsers.close();

    // open new users.csv
    ofstream WriteUsers("users.csv");

    if(WriteUsers.is_open()){
       // loop the updated array of string and put to users.csv
       for(int i = 0; i < users_count; i++){
          WriteUsers << temp_users[i] << endl;
        }
      WriteUsers.close();

      cout << "\nUpdated succesfully\n"; 
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

 // update the local database
 user.update();
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
