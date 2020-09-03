//============================================================================
// Name        : telePoster.cpp
// Author      : Alab
// Version     :
// Copyright   : (c) github.com/mousemove
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Dispetcher.h"
using namespace std;

int main() {
	//		cout << Network::getInstance().HTTPrestmultipartCURL("https://api.telegram.org/bot1326690964:AAH4RSxJ_4FaLybtNvU02XsVdrIMOtAFn-k/sendPhoto",
	//				//"{\"chat_id\":\"@rngnature\",\"text\":\"55899\"}"
	//				"{\"chat_id\":\"@rngnature\",\"photo\":\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADAAAAAwCAYAAABXAvmHAAAAAXNSR0IArs4c6QAAAqhJREFUaAXtWc1qFEEQro4RkogIEQ+ioDcxCgEDgje96dlD8OIPePTgZENmJrO7DJKIcWHjQXPJIRf1oAT0CYzgC/gQRhQ2GAV3wvyU1QsDnTG17ExvZvfQDctWV3d1fV9V9exON4BpJgImAiYCg4yA6Obc8pbOQBQ8B4E3EOF0t7n9HxPbBG4LRscWVper37j1WQISPMbtr4BwkjMuRS+gJY6MT3MkRjgQGAeNgYOX4GQAZRUwjSUgAK8zNuWrqYQ5p6PcQLbmX6wss+XGraGjf2x7mNpnsaR6+c1mQJ00zLIhMOjsmAyYDGhGwJSQZgC1zU0GtEOouYDJgGYAtc1Lz4BtPzuhjVpZoFQCc0799p7488VqNscVDFpiaQQWqtULiPEGvaBchh87r7RQK8Z9IVBxajOW519V1t0nzjcax8IQNukP/nE5gIAP5uza3X2TCna0CVi+P5kAbkIcfugcAhwAJGrtrhPoS+oQQrJGWbmo6orIWgR83x+BIHqDiOc6b01x8DFb35ZTewSId7LgKBsyK+9pjYnsWJ6+FoHfQVQn8DdThyTP4M+djbQ/79auISbNtJ/9lln5FYRa+6Ewgcpi/VaCWM+ComjPWrZXdd2np6IE39H40f/mqAqE+5br3VNVeeRCBBzHP5/EyWtydOCLPpXHk3by9zNt17O9gEEUaxXXn+plbnZObgJUs2N7GNITBSeziyl9Ioa9b1DEiQTDQvshN4HddvSSInxFAdsXkR4CU0X2A3suxKFaXVl6SGPyMxQtdwaGArUCwhBQgjEQkd0DQsB39UxSPassH6nY5nzyJYTiE2dUtp6eyVucT54A3YzQz1SLMyxNLzFILExjCcgbEXkzIkC8leXE2B+aWvrs+O5yO3Nozs3CJgImAiYCPUfgH8mf2QU09MCIAAAAAElFTkSuQmCC\",\"caption\":\"тесто\"}"
	//				//"{\"chat_id\":\"@rngnature\",\"photo\":\"https://images.netpeak.net/blog/nuzno-podklucit-bota-ifttt.png\",\"caption\":\"тесто\"}"
	//
	//
	//		) << endl; // prints
	//cout << Network::getInstance().TGsendMessage("1326690964:AAH4RSxJ_4FaLybtNvU02XsVdrIMOtAFn-k","rngnature","Привет");
	//cout << Network::getInstance().TGsendPhoto("1326690964:AAH4RSxJ_4FaLybtNvU02XsVdrIMOtAFn-k","rngnature","clint_bellanger_rbga.png","Описание");
	Dispetcher d;
	d.proceed();

	return 0;
}
