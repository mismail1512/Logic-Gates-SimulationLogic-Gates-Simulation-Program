#include "Load.h"
#include"Action.h"
#include"../ApplicationManager.h"
#include"../Components/AND2.h"
#include"../UI/UI.h"
#include <fstream>
#include"../Components/BUFFER2.h"
#include"../Components/Connection.h"
#include"../Components/LED.h"
#include"../Components/NAND2.h"
#include"../Components/NOR2.h"
#include"../Components/NOT2.h"
#include"../Components/OR2.h"
#include"../Components/Switch.h"
#include"../Components/XNOR2.h"
#include"../Components/XOR2.h"
#include"../Components/Connection.h"
OutputPin * out = new OutputPin(1);
InputPin * in = new InputPin();
Load::Load(ApplicationManager* pAPP): Action(pAPP)
{
}
Load::~Load()
{
}
void Load::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg(" write the file name to be loaded");
    string LoadedFileName=pUI->GetSrting();
	ifstream fileinput(LoadedFileName.c_str(), ios::in);
	if (fileinput.fail())
	{
		pUI->PrintMsg("File failed to start");
	}
	else 
	{   
		Component* pComponent;
		while (!fileinput.eof())
		{
			int flag, x1, x2, y1, y2;
			fileinput >>flag >>x1>>x2>>y1>>y2;
			GraphicsInfo * pts = new GraphicsInfo(2);
			pts->PointsList[0].x=x1;
			pts->PointsList[1].x=x2;
			pts->PointsList[0].y=y1;
			pts->PointsList[1].y=y2;

			switch (flag)
			{
			case 0: {

				pComponent = new AND2(pts, 5); pManager->AddComponent(pComponent);;
				break; 
			case 1:
			{	pComponent = new BUFFER2(pts, 5); pManager->AddComponent(pComponent); break;
			}
			case 2:
			{	pComponent = new LED(pts, 5); pManager->AddComponent(pComponent); break; }
			case 3:
			{	pComponent = new NAND2(pts, 5); pManager->AddComponent(pComponent); break; }
			case 4:
			{	pComponent = new NOR2(pts, 5); pManager->AddComponent(pComponent); break; }
			case 5:
			{	pComponent = new NOT2(pts, 5); pManager->AddComponent(pComponent); break; }
			case 6:
			{	pComponent = new OR2(pts, 5); pManager->AddComponent(pComponent); break; }
			case 7:
			{	pComponent = new Switch(pts, 5); pManager->AddComponent(pComponent); break; }
			case 8:
			{	pComponent = new XNOR2(pts, 5); pManager->AddComponent(pComponent); break; }
			case 10:
			{	pComponent = new Connection(pts,out,in); pManager->AddComponent(pComponent); break; }
			
			}
			case 9:
			{	pComponent = new XOR2(pts, 5); pManager->AddComponent(pComponent); break; }
			}

		}
	
	}
	fileinput.close();
}
void Load::Undo()
{
}

void Load::Redo()
{
}
