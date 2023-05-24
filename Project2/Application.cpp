#include <string>
#include <iostream>
#include <vector>
#include "Application.h"
#include "Base.h"
#include "Child_1.h"
#include "Cl_2.h"
#include "Cl_3.h"
#include "Cl_4.h"
#include "Cl_5.h"


Application::Application() : Base(nullptr, "") {};

void Application::create() {
	std::string root_name, child_name;
	int class_number;
	std::cin >> root_name;
	std::vector<Base*> created;
	this->setName(root_name);
	created.push_back(this);
	std::cin >> root_name >> child_name >> class_number;
	while (true) {
		for (auto c : created) {
			if (c->getName() == root_name & !c->getChildByName(child_name)) {
				if (class_number == 2) {
					Base* n = new Child_1(c, child_name);
					created.insert(created.begin(), n);
					break;
				}
				else if (class_number == 3) {
					Base* n = new Cl_2(c, child_name);
					created.insert(created.begin(), n);
					break;
				}
				else if (class_number == 4) {
					Base* n = new Cl_3(c, child_name);
					created.insert(created.begin(), n);
					break;
				}
				else if (class_number == 5) {
					Base* n = new Cl_4(c, child_name);
					created.insert(created.begin(), n);
					break;
				}
				else if (class_number == 6) {
					Base* n = new Cl_5(c, child_name);
					created.insert(created.begin(), n);
					break;
				}
			};
		};
		std::cin >> root_name;
		if (root_name == "endtree") {
			break;
		}
		std::cin >> child_name >> class_number;
	};
	while (std::cin >> root_name >> class_number) {
		Base* tmp = this->getChildByNameOnBranch(root_name);
		if (tmp) {
			tmp->setReady(class_number);
		};
	};
};
int Application::execApp() {
	std::cout << "Object tree" << std::endl;
	this->printTree(0);
	std::cout << "The tree of objects and their readiness" << std::endl;
	this->printTreeReady(0);
	return 0;
};