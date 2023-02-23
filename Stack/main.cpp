#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

int main(){
    Stack st;
    st.push(10);
    st.push(100);
    st.push(15);

 cout <<st.sizeOfLinkedList<<endl;
 while(!st.isEmpty()){
       cout<<st.pop()<<endl;
 }
 cout <<st.sizeOfLinkedList<<endl;
    return 0 ;
;}