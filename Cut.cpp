#include "Cut.h"
#include "ApplicationManager.h"




Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
}

Cut::~Cut()
{
}

void Cut::Execute()
{
	int X, Y;
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("You selected Cut");
	pUI->GetPointClicked(X, Y);
	pUI->ClearStatusBar();

}

void Cut::Undo()
{
}

void Cut::Redo()
{
}
