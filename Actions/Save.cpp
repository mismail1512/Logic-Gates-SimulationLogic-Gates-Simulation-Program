#include "Save.h"
#include "../ApplicationManager.h"
#include"../Actions/Action.h"

Save::Save(ApplicationManager* mAPP): Action(mAPP)
{

}

Save::~Save()
{
}


void Save::Undo()
{
}

void Save::Redo()
{
}

void Save::Execute()
{
	 
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg(" Write file name ");
	int numberOfComponents = pManager->GetCompCount();
	Component** newcomplist = pManager->GetCompList();

	string filename = pUI->GetSrting();
	ofstream savefile(filename.c_str(),ios::out);

	for (int i = 0; i < numberOfComponents; i++)
	{
		newcomplist[i]->SaveComponent(savefile);
	}
		savefile.close();



	

}
