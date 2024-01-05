#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include<fstream>

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo *m_pGfxInfo;	//The parameters required to draw a component
	bool selected = false;

public:

	Component(GraphicsInfo *r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(UI*) = 0;	//for each component to Draw itself


	virtual int GetOutPinStatus() = 0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n) = 0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s) = 0;	//set status of Inputpin # n, to be used by connection class.
	virtual GraphicsInfo* get_component_PGInfo();

	Component();
	virtual void SaveComponent(ofstream&) = 0; 
	virtual void setselected(bool state)=0;
	virtual bool getselected() const = 0;

	//Destructor must be virtual
	virtual ~Component();
};

#endif
