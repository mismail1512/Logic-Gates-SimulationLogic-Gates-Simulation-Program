#ifndef _BUFFER2_H
#define _BUFFER2_H

/*
  Class BUFFER2
  -----------
  represent the 2-input BUFFER2 gate
*/

#include "Gate.h"

class BUFFER2 :public Gate
{
public:
	BUFFER2(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the BUFFER2 gate
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
