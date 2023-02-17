#include<bits/stdc++.h>
using namespace std;

int main()
    {
        string s; cin>>s;
        int contador = 0 ;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='4' || s[i]=='7')  contador++;
            
            if(contador>7){
                cout<<"NO"<<endl;
                return 0;
            }
            
        }
            
        
        if(contador==4 || contador ==7){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        return 0;
    }