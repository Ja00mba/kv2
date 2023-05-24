#include "Base.h"
#include <string>
#include <vector>
#include <iostream>
Base::Base(Base* p, std::string n) : parent(p), name(n) {
	if (p != nullptr) {p -> children.push_back(this);
	};
};
bool Base::setName(std::string newName) {
	if (!parent) {
		name = newName;
		return true;
	}
	for (auto child : parent->children) {
		if (child != this && child->getName() == newName) {
			return false;
		};
	};
	name = newName;
	return true;
};
std::string Base::getName() { return name; };
Base* Base::getParent() { return parent; };

void Base::printTree(int level) {
	for (int i = 0; i < level; i++) { std::cout << "    "; }
	std::cout << name << std::endl;
	for (auto child : children) {
		child->printTree(level + 1);
	};
};

void Base::printTreeReady(int level) {
	for (int i = 0; i < level; i++) { std::cout << "    "; }
	std::cout << name;
	if (is_ready != 0) {
		std::cout << " is ready";
	}
	else {
		std::cout << " is not ready";
	}
	for (auto child : children) {
		std::cout << std::endl;
		child->printTreeReady(level + 1);
	};
};
Base* Base::getChildByName(std::string childName) {
	for (auto child : children) {
		if (child->getName() == childName) {
			return child;
		};
	};
	return nullptr;
};
Base* Base::getChildByNameOnTree(std::string childName) {
	Base* obj = this;
	while (obj->getParent()) { obj = obj->getParent(); };
	return obj->getChildByNameOnBranch(childName);
};

Base* Base::getChildByNameOnBranch(std::string name) {
	int n = 0;
	Base* obj;
	Base* result_obj = nullptr;
	std::vector <Base*> a;
	a.push_back(this);
	while (a.size() > 0) {
		obj = a.back();
		a.pop_back();
		if (obj->name == name) {
			n++;
			result_obj = obj;
		}
		for (int i = 0; i < obj->children.size(); i++) {
			a.push_back(obj->children[i]);
		}
	}
	if (n == 1) {
		return result_obj;
	}
	return nullptr;
}

void Base::setReady(int num) {
	if (num) {
		if (parent) {
			if (parent->is_ready) { is_ready = 1; };
		}
		else { is_ready = 1; };
	}
	else {
		is_ready = 0;
		for (auto c : children) {
			c->setReady(0);
		};
	};
};