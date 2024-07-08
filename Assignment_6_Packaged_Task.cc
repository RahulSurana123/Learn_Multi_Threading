// Packaged task example
// Executes the task in a new thread
#include <future>
#include <iostream>
#include <chrono>
#include <functional>

using namespace std::literals;


std::future<int> tasker(std::function<int(int,int)> adder,int a, int b){
	return std::async(std::launch::async,adder,std::move(a),std::move(b))
}


void collector(std::future<int> f){
	int result = f.get();
	std::cout << " and Here are Results for you : " << result <<"\n";
}

int main() {

	// The promise object is an std::promise<int>
	// Get the future associated with it
	auto fut = tasker([](int a, int b){ return a+b; },5,9);



	// Start a new thread
	// The packaged task will be its entry point
	std::thread thr1(collector, std::move(fut));

	thr1.join();

}