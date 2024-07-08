#include "thread"
#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>

using namespace std;


int count = 0;

void incrementor(){
    for(int i = 0; i < 100000; i++) count++;
}

int main(){

    int no_of_thread;
    cout << "Enter no of Thread :" << endl;
    cin >> no_of_thread;
    cout <<"\n";
    std::thread thr[no_of_thread];
    for(int i = 0; i < no_of_thread; i++){
        thr[i] = std::thread(incrementor);
    }
    for(int i = 0; i < no_of_thread; i++){
        thr[i].join();
    }
    std::cout << "count is :" << count << " after no of thread" << no_of_thread <<"\n"; 

}