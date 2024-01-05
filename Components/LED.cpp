#include "LED.h"

LED::LED(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut)
{
}


void LED::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input LED gate
void LED::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawLED(*m_pGfxInfo,selected);
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void LED::setselected(bool state)
{
	selected = state;
}

bool LED::getselected() const
{
	return selected;
}

GraphicsInfo * LED::get_component_PGInfo()
{
	return m_pGfxInfo;
}

void LED::SaveComponent(ofstream &savefile)
{
	savefile << 2 << endl;// number to indicate which gate we are using 
	int x1 = get_component_PGInfo()->PointsList[0].x;
	int x2 = get_component_PGInfo()->PointsList[1].x;
	int y1 = get_component_PGInfo()->PointsList[0].y;
	int y2 = get_component_PGInfo()->PointsList[1].y;
	savefile << x1 << endl << x2 << endl << y1 << endl << y2 << endl;
}
