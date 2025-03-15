#include <bits/stdc++.h>
using namespace std;
enum {n=10};

int buffer[n];
int writeIndex-0;
int readIndex=0;

int put(int item){
    if((writeIndex+1)%n==readIndex){
        return 0;
    }
    buffer[writeIndex]=item;
    writeIndex=(writeIndex+1)%n;
    return 1;
}

int get(int *value){
    if(readIndex==writeIndex){
        return 0;
    }
    *value=buffer[readIndex];
    readIndex=(readIndex+1)%N;
}
int main(){
    int value=1001;
    while(put(value++));
    while(get(&value){
        cout<<value<<endl;
    })
}
