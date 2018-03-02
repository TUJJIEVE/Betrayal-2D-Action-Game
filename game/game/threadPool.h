#pragma once
#include <thread>
#include <vector>
#include <mutex>
#include <queue>
#include<functional>
#include <iostream>
#include <condition_variable>
#include <stdarg.h>
class threadPool {
	public:
		threadPool(int);
		~threadPool() {
			std::cout << "Destroyed" << std::endl;
		}
		//std::thread getWorkerThread();
		int addJob(int count,std::function<int()>,...);
	//	void dispatch();
		void destroy();
		int waitFinished();
	private:
		int isJobQueueEmpty;
		std::mutex m1, m2;
		int totalThreads;
		int isStop;
		int remainingThreads;
		int loopingFunction();
		std::vector<std::thread> myThreads;
		std::condition_variable c,w;
		std::queue<std::function<int()>> jobQueue;
		int flag;
		int isWorkToDo;

		

};