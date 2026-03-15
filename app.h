//
// Created by dell on 3/4/2026.
//

#ifndef INSTANT36_APP_H
#define INSTANT36_APP_H
#include <fstream>
#include <iostream>
using namespace std ;
class App {
public:
    void mainMenu() ;
    void homeView(string &userName) ;
    void fillAuthData(string &name , string &pass) ;
    bool signUp () ;
    bool signIn () ;

};



#endif//INSTANT36_APP_H
