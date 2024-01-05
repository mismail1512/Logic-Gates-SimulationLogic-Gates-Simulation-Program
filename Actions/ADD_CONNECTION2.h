#pragma once
#include "Action.h"

class ADD_CONNECTION2 : public Action
{
private:
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ADD_CONNECTION2(ApplicationManager *pApp);
	virtual ~ADD_CONNECTION2(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

