//
// Created by dell on 3/4/2026.
//
#pragma once
#include "app.h"
#include <iostream>
using namespace std ;
void App ::mainMenu(){
    cout << "Hello, Please Choose an Option" << endl;
    cout << "1 - SignIn" << endl;
    cout << "2 - SignUp" << endl;
    cout <<"3 - Exit" << endl;
    char option ;
    cin >> option ;
    if (option == '1'){
        signIn() ;
    }
    else if(option == '2') {

        signUp( ) ;
    }
    else {
        cout << "Thank You !" << endl ;
        return;
    }
}
void App:: homeView(string &userName){
    cout << "Welcome, " << userName<< endl;

}
void App:: fillAuthData(string &name , string &pass) {
    cout << "Enter Your Name" << endl;
    cin >> name ;
    cout << "Enter Your Pass" << endl;
    cin >> pass ;
}
bool App :: signUp (){
    string userName , pass ;
    ofstream output ("user_data.txt" , ios::app ) ;
    if (!output.is_open()){
        cout << "Some thing Went Wrong!" ;
        return false ;
    }
    fillAuthData(userName , pass) ;
    output << userName << " " << pass  << endl;
    cout << "Account Created Successfully" << endl;
    return true ;
}
bool App :: signIn (){
    string userName , pass ;
    string userNameFromData , passFromData ;
    ifstream input("user_data.txt") ;
    input.open("user_data.txt") ;
    if (!input.is_open()){
        cout << "Invalid" << endl;
        return false ;
    }
    input.clear();
    input.seekg(0, ios::beg);
    int counter = 3 ;
    while (counter--) {
        fillAuthData(userName, pass) ;
        bool found = false ;
        while (  input >> userNameFromData >> passFromData) {
            if (userName == userNameFromData && pass == passFromData){
                found = true;
            }
        }


        if (!found) {
            cout << "Wrong Mail Or Pass Please Try Again " << endl;
            cout << "Remine Tries " << counter << endl;
        }
        else {
            homeView(userName) ;
        }
        if (counter == 0) {
            cout << "You Not Have An Account" << endl;
            cout << "Would you Want To Sign Up ?" << endl;
            signUp() ;
        }
    }
    return false ;
}