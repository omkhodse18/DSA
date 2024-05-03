// https://www.naukri.com/code360/problems/two-stacks_983634?interviewProblemRedirection=true&search=stack&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
using namespace std;
class TwoStack {
    int *arr; 
    int size; 
    int tp1; 
    int tp2; 

    public:
        // Initialize TwoStack.
        TwoStack(int s) {
            arr = new int[s]; 
            this->size = s; 
            this->tp1 = -1; 
            this->tp2 = s;
        }
        
        // Push in stack 1.
        void push1(int num) {
            if(tp1+1 != tp2){
                arr[++tp1] = num;
            }
        }

        // Push in stack 2.
        void push2(int num) {
            if(tp2-1 != tp1){
                arr[--tp2] =  num;
            }
        }

        // Pop from stack 1 and return popped element.
        int pop1() {
            if(tp1!= -1){
                int val  = arr[tp1];
                tp1--; 
                return val;
            }
            return  -1; 
        }

        // Pop from stack 2 and return popped element.
        int pop2() {
            if(tp2 !=size ){
                int val = arr[tp2];
                tp2++; 
                return  val;
            }
            return  -1;
        }
};