#ifndef __APPLICATION__H
#define __APPLICATION__H
#include "Base.h"
#include <string>
class Application : public Base { /* �� ������� �������, ������ �����
�����������
�� �������� � �������������� ��� ����������� �����
*/
public:
	Application();
	void create();
	int execApp();
};

#endif