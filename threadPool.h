#pragma once
#include <thread>
#include <vector>
#include <mutex>
#include <queue>
#include<functional>
#include <iostream>
#include <condition_variable>
class threadPool {
	public:
		threadPool(int);
		~threadPool() {
			std::cout << "Destroyed" << std::endl;
		}
		//std::thread getWorkerThread();
		int addJob(std::function<int(int)>);
		void dispatch();
		void destroy();
	private:
		int isJobQueueEmpty;
		std::mutex m1, m2;
		int totalThreads;
		int isStop;
		int remainingThreads;
		int loopingFunction();
		std::vector<std::thread> myThreads;
		std::condition_variable c;
		std::queue<std::function<int(int)>> jobQueue;
		int flag;
		int isWorkToDo;

		

};