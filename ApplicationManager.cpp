#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include <iostream>
#include ".\Components\Connection.h"
#include ".\Actions\ADD_CONNECTION2.h"
#include"./Actions/SELECT1.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddNOTgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddBUFFERgate2.h"
#include "Actions\AddSwitch.h"
#include "Actions\AddLED.h"
#include"./Actions/Save.h"
#include"Actions/Load.h"
#include "Delete.h"
#include "Copy.h"
#include "Cut.h"


using namespace std;

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction();
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;
	case ADD_OR_GATE_2:
		pAct = new AddORgate2(this);
		break;
	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		break;
	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		break;
	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		break;
	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		break;
	case ADD_Buff:
		pAct = new AddBUFFERgate2(this);
		break;
	case ADD_NOT_GATE_2:
		pAct = new AddNOTgate2(this);
		break;
	case ADD_LED:
		pAct = new AddLED(this);
		break;
	case ADD_Switch:
		pAct = new AddSwitch(this);
		break;

	case ADD_CONNECTION://ADD_CONNECTION:
	
		pAct = new ADD_CONNECTION2(this);
	break;

	case SELECT:
	pAct = new SELECT1(this);

	break;

	case DEL:
	pAct = new Delete(this);
	break;

	case EDIT_Label:
	pAct = new Copy(this);
	break;

	case MOVE:
	pAct = new Cut(this);
	break;
	case EXIT:
		///TODO: create ExitAction here
		break;
	case SAVE:

		{   //ApplicationManager* uspManager = this;	//Actions needs AppMngr to do their job

		   // UI* pUI = uspManager->GetUI();

			pAct = new Save(this);

			break;
		}
	case LOAD:
		{pAct = new Load(this);
		break;
		}
	}
	if (pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->Draw(pUI);

}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;

}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)	
	delete CompList[i];
    
	delete pUI;

}
int ApplicationManager::GetCompCount()
{
	return CompCount;
}

Component** ApplicationManager::GetCompList()
{
	
	return CompList;
}