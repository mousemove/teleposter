/*
 * Task.cpp
 *
 *  Created on: 2 сент. 2020 г.
 *      Author: alab
 */

#include "Task.h"

Task::Task(const vector<string> & params) {
	token = params[0];
	channel = params[1];
	delay = stoi(params[2]);
	picturesFolder = params[3];
	textFile = params[4];
	content = (TYPECONTENT)stoi(params[5]);
	deleteAfterPost = (bool)stoi(params[6]);
	textTemplate = params[7];

	if(content != TEXTONLY)
	{
		pictures =  taskImages(picturesFolder.c_str());
	}
	if(content != PICTUREONLY)
	{
		texts =  taskStrings(textFile.c_str());
	}



}

Task::~Task() {
	// TODO Auto-generated destructor stub
}


void Task::proceed()
{

	//Network::getInstance().TGsendMessage(token,channel,texts[rand() % texts.size()]);
	auto now = std::time(0) ;
	if(now  > lastTSpost + delay*60 )
	{

		unsigned randomText;
		unsigned randomPicture;
		TYPECONTENT _contentCurrent = (content == RANDOM) ? (TYPECONTENT)(rand() %3) : content;

		if ( (texts.size() == 0) && (_contentCurrent == TEXTONLY || _contentCurrent == PICTURETEXT) ) {
			cout << "Error!Text file empty: " << textFile << ". Please, add text and reboot teleposter" << endl ;
			return;
		}
		else if ((_contentCurrent == TEXTONLY || _contentCurrent == PICTURETEXT))
		{
			randomText = rand() % texts.size();
		}

		if ((pictures.size() == 0) && (_contentCurrent == PICTUREONLY || _contentCurrent == PICTURETEXT)) {
			cout << "Error!Pictures folder empty: " << textFile << ". Please, add pictures and reboot teleposter" << endl ;
			return;
		}
		else if((_contentCurrent == PICTUREONLY || _contentCurrent == PICTURETEXT))
		{
			randomPicture	= rand() % pictures.size();
		}




		if (_contentCurrent == TEXTONLY)
		{
			cout << "wanna post1ng TEXT... " << _contentCurrent << endl;
			if (Network::getInstance().TGsendMessage(token,channel,replaceAll(textTemplate,"$TEXT",texts[randomText])) == FAILURY)
			{
				cout << "Send error at task with token = " << token << " and channel = " << channel << endl ;
				return;
			}
		}
		if (_contentCurrent == PICTUREONLY)
		{

			if (Network::getInstance().TGsendPhoto(token,channel,picturesFolder+"/"+pictures[randomPicture],"") == FAILURY)
			{
				cout << "Send error at task with token = " << token << " and channel = " << channel << endl ;
				return;
			}
		}
		if (_contentCurrent == PICTURETEXT)
		{

			if (Network::getInstance().TGsendPhoto(token,channel,picturesFolder+"/"+pictures[randomPicture],replaceAll(textTemplate,"$TEXT",texts[randomText])) == FAILURY)
			{
				cout << "Send error at task with token = " << token << " and channel = " << channel << endl ;
				return;
			}
		}

		if(deleteAfterPost)//toDo крайне спорное решение с удалением из вектора и пересохранением если файл со строками большой, переделать
		{
			if (_contentCurrent == TEXTONLY  || _contentCurrent == PICTURETEXT)
			{
				texts.erase(texts.begin()+randomText);
				saveStringVectorToFile(textFile,texts);

			}
			if (_contentCurrent == PICTUREONLY  || _contentCurrent == PICTURETEXT)
			{
				string fileAddress  = picturesFolder+"/"+pictures[randomPicture];
				remove(fileAddress.c_str());
				pictures.erase(pictures.begin()+randomPicture);
				saveStringVectorToFile(textFile,texts);

			}


		}


		lastTSpost = now;

	}
}
