#include "Connection1.h"

Connection1::Connection1(GraphicsInfo *r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection1::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection1::getSourcePin()
{	return SrcPin;	}


void Connection1::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection1::getDestPin()
{	return DstPin;	}


void Connection1::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection1::Draw(UI* pUI)
{
	pUI->DrawConnection(*m_pGfxInfo);
}

int Connection1::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection1::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection1::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}
