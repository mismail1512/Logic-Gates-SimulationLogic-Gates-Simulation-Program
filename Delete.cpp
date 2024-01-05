#include "Delete.h"
#include "ApplicationManager.h"




Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{
}

Delete::~Delete()
{
}

void Delete::Execute()
{
	int X, Y;
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("You selected Delete.");
	pUI->GetPointClicked(X, Y);
	pUI->ClearStatusBar();
}

void Delete::Undo()
{
}

void Delete::Redo()
{
}
