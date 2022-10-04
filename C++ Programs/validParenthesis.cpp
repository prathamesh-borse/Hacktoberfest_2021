// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution{
    public:
        bool isValid(string s){
            stack<char> stack1;

            if(s.size()%2!=0){
                return false;
            }
    
            for(int i=0; i<s.size(); i++){
                if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                    stack1.push(s[i]);
                }
                else
                {
                    if(!stack1.empty()&&((s[i]==')'&&stack1.top()=='(')||(s[i]=='}'&&stack1.top()=='{')||(s[i]==']'&&stack1.top()=='[')))
                    {
                        stack1.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            if(stack1.empty()){
                return true;
            }
            else{
                return false;
            }
            
        }
};

int main(){
    string str;
    cout<<"Enter the string";
    cin>>str;
    Solution sol;
    sol.isValid(str);
}

 
