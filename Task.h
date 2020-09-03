/*
 * Task.h
 *
 *  Created on: 2 сент. 2020 г.
 *      Author: alab
 */

#ifndef TASK_H_
#define TASK_H_
#include "additional.h"
#include <list>
#include "Network.h"
#include <random>
using namespace std;
enum TYPECONTENT {
	PICTUREONLY,
	TEXTONLY,
	PICTURETEXT,
	RANDOM
};


class Task {
private:

	string token;
	string channel;
	unsigned int delay = 1;
	string picturesFolder;
	string textFile;
	TYPECONTENT content = PICTUREONLY;
	bool deleteAfterPost = 0;
	string textTemplate;
	time_t lastTSpost = 0;
	vector<string> pictures;
	vector<string> texts;
public:
	Task(const vector<string> & params );
	virtual ~Task();
	void proceed();
};

#endif /* TASK_H_ */
