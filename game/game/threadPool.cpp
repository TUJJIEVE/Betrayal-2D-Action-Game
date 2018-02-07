#include "threadPool.h"
#include <functional>

#include<condition_variable>
threadPool::threadPool(int n) {
	isWorkToDo = 0;
	isJobQueueEmpty = 1;
	totalThreads = 0;
	myThreads.reserve(n+2);

	for (int i = 0; i < n; i++)
	{
		myThreads.push_back(std::thread(&threadPool::loopingFunction,this));
	}

}

int threadPool::loopingFunction() {
	//std::condition_variable c;
	std::unique_lock<std::mutex> lock(m1);
	
	while (true) {
		//totalThreads += 1;
		while (jobQueue.size() == 0 && !isStop) {
			c.wait(lock);// , [this]() {return !jobQueue.size() == 0; });
		
		}
		if (isStop) return 0;
		
		std::function<int()> job = jobQueue.front();
		jobQueue.pop();
		isWorkToDo -= 1;
		if (isWorkToDo == 0) isJobQueueEmpty = 1;
		job();
		//std::this_thread::sleep_for(std::chrono::seconds(4));
	}
}
//template<typename T1, typename T2>

//template<typename T1,typename T2>
int threadPool::addJob(std::function<int()> newJob) {  // If mulitple threads will be acessing then see that it is locked
	
	std::unique_lock<std::mutex> lock(m1);
	jobQueue.push(newJob);
	isWorkToDo += 1;
	isJobQueueEmpty = 0;
	c.notify_one();

	return 1;
}
//template<typename T1, typename T2>
void threadPool::destroy() {
	isStop = 1;
	c.notify_all();
	for (int i = 0; i < 10; i++) {
		if (myThreads[i].joinable()) myThreads[i].join();
	}
}
