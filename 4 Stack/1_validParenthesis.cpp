#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s)
   {
  stack<char>sk;
  for( char x :s)
  {
    if(x=='(')
    sk.push(x);
    else if(x=='[')
    sk.push(x);
    else if(x=='{')
    sk.push(x);
    else if(x==')'&&!sk.empty()&&sk.top()=='(')
    sk.pop();
    else if(x==']'&&!sk.empty()&&sk.top()=='[')
    sk.pop();
    else if(x=='}'&&!sk.empty()&&sk.top()=='{')
    sk.pop();
    else
    return false;
  }   
  if(sk.empty()) return true;
                 return false;  
       
    }
};