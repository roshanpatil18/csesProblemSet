#include <bits/stdc++.h>
using namespace std;


int main(){


    int n;
    cin>>n;

    vector<int>num;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        num.push_back(a);
    }


    stack<int>st;

     
       vector<int>ans;
       

    for(int i=0;i<num.size();i++ ){


        while(!st.empty() && num[st.top()]>=num[i]){
            st.pop();
        }
        if(st.empty()){
             ans.push_back(0);
        }else{
            ans.push_back(st.top()+1);
        }

        st.push(i);
    }

    for(auto it:ans){
        cout<<it<<" ";
    }

}