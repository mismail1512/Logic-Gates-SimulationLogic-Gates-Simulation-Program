#pragma once
#include "NOR2.h"

NOR2::NOR2(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut)
{
}


void NOR2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input NOR gate
void NOR2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawNOR2(*m_pGfxInfo,selected);
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void NOR2::setselected(bool state)
{
	selected = state;
}

bool NOR2::getselected() const
{
	return selected;
}

GraphicsInfo * NOR2::get_component_PGInfo()
{
	return m_pGfxInfo;
}

void NOR2::SaveComponent(ofstream &savefile)
{
	savefile << 4 << endl;// number to indicate which gate we are using 
	int x1 = get_component_PGInfo()->PointsList[0].x;
	int x2 = get_component_PGInfo()->PointsList[1].x;
	int y1 = get_component_PGInfo()->PointsList[0].y;
	int y2 = get_component_PGInfo()->PointsList[1].y;
	savefile << x1 << endl << x2 << endl << y1 << endl << y2 << endl;
}
