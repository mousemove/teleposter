/*
 * Network.h
 *
 *  Created on: 31 авг. 2020 г.
 *      Author: alab
 */

#ifndef NETWORK_H_
#define NETWORK_H_
#include <string>
#include <iostream>
#include <stdio.h>
#include <curl/curl.h>
#include <string>
#include <fstream>
using namespace std;
enum contentType
{
	AJSON,
	MULTIPART
};
enum telegramResult{
	SUCCESS,
	FAILURY
};
class Network {
private:
	Network();
public:

	Network( const Network& )  = delete;
	Network& operator=( Network& ) = delete;
	static Network& getInstance() {
		static Network  instance;
		return instance;
	}
	struct curl_slist *listAJSON = nullptr;
	struct curl_slist *listMultipart = nullptr;
	string HTTPgetCURL(const char *url);
	string HTTPjsonCURL(const char *url,const char * data);

	telegramResult TGsendMessage(const string & token,const string & channel,const string & message);
	telegramResult TGsendPhoto(const string & token,const string & channel,const string & path,const string & message = "");
	string HTTPrestmultipartCURL(const char *url,const char * data);
	virtual ~Network();
};

#endif /* NETWORK_H_ */
