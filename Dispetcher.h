/*
 * Dispetcher.h
 *
 *  Created on: 2 сент. 2020 г.
 *      Author: alab
 */

#ifndef DISPETCHER_H_
#define DISPETCHER_H_
#include <iostream>
#include "additional.h"
#include "Task.h"

using namespace std;
class Dispetcher {
private:
	vector<Task> tasks;
public:
	Dispetcher();

	void proceed();
	virtual ~Dispetcher();
};

#endif /* DISPETCHER_H_ */
