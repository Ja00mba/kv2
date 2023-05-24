#ifndef __CHILD_1__H
#define __CHILD_1__H
#include "Base.h"

class Child_1 : public Base {

public:
	Child_1(Base* p = nullptr, std::string n = "");
};
#endif