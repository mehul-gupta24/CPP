// 93. Restore IP Addresses
// Solved
// Medium
// Topics
// Companies
// A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

 

// Example 1:

// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
// Example 2:

// Input: s = "0000"
// Output: ["0.0.0.0"]
// Example 3:

// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

// Constraints:

// 1 <= s.length <= 20
// s consists of digits only.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void fun(vector<string> &ans,string &s,int no_of_dots,int index,string temp){
        if(no_of_dots==4 && index==s.length()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        if(no_of_dots==4 && index<s.length()){
            return;
        }
        if(index+1<=s.length()){
            fun(ans,s,no_of_dots+1,index+1,temp+s.substr(index,1)+'.');
        }

        if(index+2 <=s.length()){
            string s_1=s.substr(index,2);
            if(s_1[0]=='0'){
                return;
            }
            fun(ans,s,no_of_dots+1,index+2,temp+s.substr(index,2)+'.');
        }

        if(index+3 <=s.length()){
            string s_2=s.substr(index,3);
            int val=stoi(s_2);
            if(s_2[0]=='0' || val>255){
                return;
            }
            fun(ans,s,no_of_dots+1,index+3,temp+s.substr(index,3)+'.');
        }

        return;
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.length()>12){
            return {};
        }
        vector<string> ans;
        string temp="";
        int no_of_dots=0;
        int index=0;
        fun(ans,s,no_of_dots,index,temp);
        return ans;
    }
};