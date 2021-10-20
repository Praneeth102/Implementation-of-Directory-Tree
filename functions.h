#include <iostream>
#include "source.h"
#include <stack>
#include <bits/stdc++.h>


//time complexity of compare function is O(1)

bool compare(node* a,node* b){
    return (a->name < b->name);
}

//time complexity of this function is O(1) in best and worst cases
void pwdcommand(node* curr){
    cout<<curr->name<<endl;
}
//In best case time complexity is O(1) i.e.,number of child nodes is 0
//In worst case time complexity is O(size).Here size is the number of child nodes to the current node
void lscommand(node* curr){
    int size=curr->files.size();
    if(size==0)
       cout<<"This directory is empty"<<endl;
    else{
        for(int i=0;i<size;i++)
           cout<<curr->files[i]->name<<endl;
    }   
}
//this function takes O(N) time complexity in worst case,where N is number of directories in the tree
void existscommand(node* curr,string Name,bool &check){
     if(check==true || curr->files.size()==0)
         return;
     int size=curr->files.size();
     for(int i=0;i<size;i++){
         if(curr->files[i]->name==Name){
           check=true;
           return;
         }
         else{
             existscommand(curr->files[i],Name,check);
         }
            
     }    
}
//this function takes O(size) time complexity,where size is the number of directories/child nodes to current directory
void cdcommand(node* &curr,string Name,stack<node*> &s){
    node* temp=curr;
    int size=temp->files.size();
    for(int i=0;i<size;i++){
        if(Name==temp->files[i]->name){
            s.push(curr);
            curr=temp->files[i];
            return;}
    }
    cout<<Name<<" not found"<<endl;
}
//this function takes O(1) time complexity in best and worst cases
void  cdbackcom(node* &curr,stack<node*> &s){
    if(s.empty()==false){
    curr=s.top();
    s.pop();
    return;
    }
    cout<<"You are in the root directory"<<endl;
}
//this function time complexity depends on sort function time complexity 
//sort function use insertion sort or merge sort algorithms
//insertion sort takes O(N^2) time complexity in worst case.In best case O(N) time complexity
//merge sort takes O(NlogN) time complexity
//Here N is the number of childrens/directories to current node
void mkdircommand(node* curr,string newstring){
    node *temp=new node;
    temp->name=newstring;
    curr->files.push_back(temp);
    sort(curr->files.begin(),curr->files.end(),compare);
}
//this function time complexity depends on sort function time complexity and erase function time complexity
//sort function use insertion sort or merge sort algorithms
//insertion sort takes O(N^2) time complexity in worst case.In best case O(N) time complexity
//merge sort takes O(NlogN) time complexity
//erase function takes O(N) time complexity in worst case O(1) in best case
//Here N is the number of childrens/directories to current node
//overall time complexity of below function is O(NlogN + N)
void rmdircommand(node* curr,string Name){
    node* temp=curr;
    int size=temp->files.size();
    for(int i=0;i<size;i++){
        if(Name==temp->files[i]->name){
            delete temp->files[i];
            temp->files.erase(temp->files.begin()+i);
            sort(curr->files.begin(),curr->files.end(),compare);
            return;}
    }
    cout<<Name<<" not found"<<endl;
}
//time complexity of this function is O(N),where N is the number of descendants
void countdir(node *curr,int &count){
     int size=curr->files.size();
     if(size==0)
        return;

      count=count+size; 
      for(int i=0;i<size;i++){
          countdir(curr->files[i],count);
      } 

      return;

}
//time complexity of this function depends on time complexity of countdir function
//time complexity of countdir function is O(N),where N is the number of descendants
//Hence time complexity of below function is O(N)
int countcommand(node *curr){
    int count=0;
    countdir(curr,count);
    return count+1;
}

//this function undergo recursive call
//time complexity of below function is O(N) where N is total number of descendants

void showtreecmd(node* curr,int depth){
    for(int i=0;i<depth;i++)
         cout<<"    ";
    cout<<curr->name<<endl;
    int size=curr->files.size();
    for(int i=0;i<size;i++){
        showtreecmd(curr->files[i],depth+1);
    }
}