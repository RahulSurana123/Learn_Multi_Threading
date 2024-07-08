#include "thread"
#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

void game(){
    int count = 1;
    vector<string> name = { "Abdul", "Bart", "Claudia", "Divya" };

    while(true){
        cout << name[(count-1)%4] <<" says ";
        bool isFB = false;
        if(count % 3 == 0) { cout << "Fizz"; isFB = true; }
        if(count % 5 == 0) { cout << "Buzz"; isFB = true; }
        if(isFB){ cout <<"!\n"; }
        else{
            cout << count << "\n";
        }
    }
}

int main(){

    std::thread thr(game);
    thr.join();

}