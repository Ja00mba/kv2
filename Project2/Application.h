#ifndef __APPLICATION__H
#define __APPLICATION__H
#include "Base.h"
#include <string>
class Application : public Base { /* По условию задания, данный класс
наследуется
от базового и соответственно это производный класс
*/
public:
	Application();
	void create();
	int execApp();
};

#endif