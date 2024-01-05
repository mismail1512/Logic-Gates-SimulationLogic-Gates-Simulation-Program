#include "NAND2.h"


NAND2::NAND2(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut)
{
}


void NAND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void NAND2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawNAND2(*m_pGfxInfo,selected);
}

//returns status of outputpin
int NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void NAND2::setselected(bool state)
{
	selected = state;
}

bool NAND2::getselected() const
{
	return selected;
}

GraphicsInfo * NAND2::get_component_PGInfo()
{
	return m_pGfxInfo;
}

void NAND2::SaveComponent(ofstream & savefile)
{
	savefile << 3 << endl;// number to indicate which gate we are using 
	int x1 = get_component_PGInfo()->PointsList[0].x;
	int x2 = get_component_PGInfo()->PointsList[1].x;
	int y1 = get_component_PGInfo()->PointsList[0].y;
	int y2 = get_component_PGInfo()->PointsList[1].y;
	savefile << x1 << endl << x2 << endl << y1 << endl << y2 << endl;
}
