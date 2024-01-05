#pragma once
#ifndef _ADD_Switch_GATE_H
#define _ADD_Switch_GATE_H

#include "action.h"
#include "..\Components\Switch.h"

class AddSwitch : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddSwitch(ApplicationManager* pApp);
	virtual ~AddSwitch(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif