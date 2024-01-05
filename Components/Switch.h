#ifndef _Switch_H
#define _Switch_H

/*
  ClassSwicth
  -----------
  represent the -inputSwicth
*/

#include "Gate.h"

class Switch :public Gate
{
public:
	Switch(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(UI*);	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	void setselected(bool state = false);
	bool getselected() const;
	 GraphicsInfo* get_component_PGInfo();
	 virtual void SaveComponent(ofstream&);


};

#endif
