#include "ADD_CONNECTION2.h"
#include "..\ApplicationManager.h"
#include "../Components/InputPin.h"
#include "../Components/OutputPin.h"
#include "../Components/Connection.h"




ADD_CONNECTION2::ADD_CONNECTION2(ApplicationManager * adcomp): Action(adcomp)
{
}

ADD_CONNECTION2::~ADD_CONNECTION2(void)
{
}

void ADD_CONNECTION2::Execute()
{
	UI* pUI = pManager->GetUI();

	GraphicsInfo* connectp = new GraphicsInfo(2); //Gfx info to be used to draw the connection line
	pUI->PrintMsg("select the first point");
	pUI->GetPointClicked(x1, y1);
	pUI->ClearStatusBar();

	pUI->PrintMsg("select the second point");
	pUI->GetPointClicked(x2, y2);

	pUI->ClearStatusBar();

	connectp->PointsList[0].x = x1;
	connectp->PointsList[0].y = y1;
	connectp->PointsList[1].x = x2;
	connectp->PointsList[1].y = y2;

	OutputPin * out = new OutputPin(1);
	InputPin * in = new InputPin();
	Connection* wire = new Connection(connectp, out, in);
	pManager->AddComponent(wire);

}
void ADD_CONNECTION2::Undo()
{
}
void ADD_CONNECTION2::Redo()
{
}

