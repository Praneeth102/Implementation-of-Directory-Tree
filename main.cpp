#include <iostream>
//#include "source.h"
#include <stack>
#include <bits/stdc++.h>
#include "functions.h"



int main(){
    node *root=new node;
    root->name="root";
    stack<node*> s;
    node *curr=root;
    while(true){
    string command;
    //">" this symbol tells us to enter command
    cout<<">";
    cin>>command;
    if((command.compare("pwd"))==0){
       pwdcommand(curr);
    }
    else if((command.compare("ls"))==0){
        lscommand(curr);
    }
    else if((command.compare("exists"))==0){
        bool check=false;
        string Name;
        cin.ignore();
        getline(cin,Name);
        existscommand(root,Name,check);
        if(check)
           cout<<Name<<" exists"<<endl;
        else
           cout<<Name<<" does not exist"<<endl;
    }
    else if((command.compare("cd"))==0){
        string Name;
        cin.ignore();
        getline(cin,Name);
        if((Name.compare(".."))==0){
            cdbackcom(curr,s);
       }
       else
         cdcommand(curr,Name,s);
    }
    
    else if((command.compare("mkdir"))==0){
       string Name;
       cin.ignore();
       getline(cin,Name); 
       mkdircommand(curr,Name);
    }
    else if((command.compare("rmdir"))==0){
      string Name;
      cin.ignore();
       getline(cin,Name);
       rmdircommand(curr,Name);
    }
    else if((command.compare("quit"))==0)
         break;

    else if((command.compare("countdir"))==0)
          cout<<countcommand(curr)<<endl;
    
    else if((command.compare("showtree"))==0)
          showtreecmd(curr,0);
    else{
        cout<<"Unknown command"<<endl;
    } 
}   
    return 0;
}