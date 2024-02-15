#ifndef SIMPLEBLOODGROUP_H
#define SIMPLEBLOODGROUP_H
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

  void deleteUser(){
    setUsersCount();

    string row_data, temp_users[users_count];
    int counter = 0;

    // read users.csv and store data in array of string
    ifstream ReadUsers("users.csv");
    while(getline(ReadUsers, row_data)){
      if(counter != (user_position-1)){
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
           if(temp_users[i] != ""){
            WriteUsers << temp_users[i] << endl;
           }
        }
      WriteUsers.close();
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

  void searchRecordsByBloodGroup(string blood_grp){
    cout << "\nList of Users in Blood Group " + blood_grp;
    string row_data;
    int counter = 0;

    ifstream Users("users.csv");
    cout << "\nPosition\tName\tAge\tHeight\tBlood Group\n";
      while(getline(Users, row_data)){
        istringstream scanner(row_data);
        string _age, _height;

        getline(scanner, name, ',');
        getline(scanner, _age, ',');
        getline(scanner, _height, ',');
        getline(scanner, blood_group);

        age = stoi(_age);
        height = stoi(_height);

        if(blood_grp == blood_group){
          counter++;
          cout << counter << ".)\t\t" << name << "\t" << age << "\t" << height << "\t" << blood_group << endl;
        }
      }

    Users.close();
  }

  string displayMenu(){
   return "\n1. Add New Record\n2. Edit Record\n3. Delete Record\n4. Search Record by Blood Group\n5. Display All Users\n6. Exit";
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
#endif