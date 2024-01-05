#include "Connection.h"
#include <iostream>
#include "../ApplicationManager.h"
#include<fstream>

using namespace std;

Connection::Connection(GraphicsInfo *r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*m_pGfxInfo,selected);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}
GraphicsInfo * Connection::get_component_PGInfo()
{
	return m_pGfxInfo;
}
/*
GraphicsInfo * Connection::get_component_PGInfo()
{
	return m_pGfxInfo;
}*/
void Connection::setselected(bool state)
{
	selected = state;

}

bool Connection::getselected() const
{
		return selected;
}

void Connection::SaveComponent(ofstream &savefile)
{
	savefile << 10 << endl;// number to indicate which gate we are using 
	int x1 = get_component_PGInfo()->PointsList[0].x;
	int x2 = get_component_PGInfo()->PointsList[1].x;
	int y1 = get_component_PGInfo()->PointsList[0].y;
	int y2 = get_component_PGInfo()->PointsList[1].y;
	savefile << x1 << endl << x2 << endl << y1 << endl << y2 << endl;
	
}
