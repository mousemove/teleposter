/*
 * Dispetcher.cpp
 *
 *  Created on: 2 сент. 2020 г.
 *      Author: alab
 */

#include "Dispetcher.h"

Dispetcher::Dispetcher() {
	srand(std::time(0));
	cout << "Loading tasks...." << endl;
	ifstream read("tasks.txt");
	if (read.is_open())
	{
		string x ;
		while(getline(read,x)){
			auto params = split(x,';');
			if(params.size() == 8) {
				cout << "valid task: "+x << endl;
				//make task
				Task task(params);
				tasks.push_back(task);
			}
			else
			{
				cout << "invalid task: "+x << endl;
			}
		}
		read.close();
		remove("newtasks.txt");//удаление файла после считывания - мы завели файлы на новые таски!
	}

}

Dispetcher::~Dispetcher() {



}


void Dispetcher::proceed()
{
	if (tasks.size() == 0) 
	{
		cout << "No tasks. Finish" << endl;
		return;
	}
	while(1)
	{
		
		for(auto & task:tasks)
		{
			task.proceed();
		}
		std::this_thread::sleep_for(std::chrono::microseconds(60000000));
	}

}
