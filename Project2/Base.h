#ifndef __BASE__H
#define __BASE__H
#include <string>
#include <vector>
class Base {
private:
	Base* parent;
	std::string name;
	int is_ready = 0;
	std::vector<Base*> children;
public:
	
	Base(Base* p = nullptr, std::string n = "");
	bool setName(std::string newName);
	std::string getName();
	Base* getParent();
	void printTree(int level=0);
	void printTreeReady(int level=0);
	Base* getChildByName(std::string childName);
	Base* getChildByNameOnTree(std::string childName);
	Base* getChildByNameOnBranch(std::string childName);
	void setReady(int num);
};
#endif