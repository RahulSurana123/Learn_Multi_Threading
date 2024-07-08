#include <mutex>
#include <atomic>
#include <iostream>
#include <thread>
#include<vector>

class some_type {
	// ...
public:
	void do_it() { /*...*/ }
};

// make atomic type of some_type* and initialize it with nullptr
std::atomic<some_type*> ptr{nullptr};
std::mutex process_mutex;

// rewrite process() function to use atomic type and initalize ptr with new some_type
void process() {
    
    if (!ptr) {
        std::lock_guard<std::mutex> lk(process_mutex);
        if(!ptr) ptr = new some_type;
        std::cout << " Yeah finally i have been init\n"; 
    }
    
    some_type* x = ptr;
    x->do_it();
    std::cout << "stuff done\n";
}

int main(){
    
    
    std::vector<std::thread> x(100);
    for(int i = 0; i < 100;i++) x[i] = std::thread{process};
    for (auto&t : x) t.join();
    
}