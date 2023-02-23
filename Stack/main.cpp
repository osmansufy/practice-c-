#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

int main(){
    Stack st;
    st.push(10);
    st.push(100);
    st.push(15);


 while(!st.isEmpty()){
       cout<<st.pop()<<endl;
 }
    return 0 ;
;}