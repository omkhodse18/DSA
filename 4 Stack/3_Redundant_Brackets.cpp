// https://www.naukri.com/code360/problems/redundant-brackets_975473?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
using namespace std;

bool findRedundantBrackets(string &s){
    stack<char>store;
    int i =0;

    while(i<s.size()){
        if(s[i]=='('){
            store.push(s[i]);
        }
        else if(s[i]==')'){
            bool check = false;
            while(store.top()!='('){
                char temp = store.top();
                if(temp=='+' || temp=='-' || temp=='*' || temp =='/'){
                    check = true;
                }

                store.pop();

            }

            if(check == false) return true;
            store.pop();
        }
        else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' ){
            if(!store.empty()){
                store.push(s[i]);
            }
        }
        i++;
    }

    if(!store.empty()) 
        return true;

    return false;
}