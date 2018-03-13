#include <bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
unsigned long long  num;
cin>>num;
unsigned long long  num1=num+2;
unsigned long long  num2=(2*num)+1;
if(num%2==0){
cout<<((num)*num1*num2)/8;
}else{
cout<<((num*(num1)*(num2)-1))/8;

}
cout<<endl;

}
return 0;
}
