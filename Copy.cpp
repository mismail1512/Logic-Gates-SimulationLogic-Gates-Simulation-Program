#include "Copy.h"
#include "ApplicationManager.h"




Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
}

Copy::~Copy()
{
}

void Copy::Execute()
{
	int X, Y;
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("You selected Copy");
	pUI->GetPointClicked(X, Y);
	pUI->ClearStatusBar();
}

void Copy::Undo()
{
}

void Copy::Redo()
{
}
