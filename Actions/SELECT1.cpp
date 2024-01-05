#include "SELECT1.h"
#include "../ApplicationManager.h"



SELECT1::SELECT1(ApplicationManager* pApp) :Action(pApp)
{
}


SELECT1::~SELECT1()
{
}

void SELECT1::Execute()
{
	UI* pUI = pManager->GetUI();

	pUI->GetPointClicked(k, y);
	Component** z = pManager->GetCompList();
	int l = pManager->GetCompCount();
	for (int i = 0; i < l; i++)
	{

		if (z[i]->get_component_PGInfo()->PointsList[0].x <= k && z[i]->get_component_PGInfo()->PointsList[1].x >= k)
		{
			if (z[i]->get_component_PGInfo()->PointsList[0].y <= y && z[i]->get_component_PGInfo()->PointsList[1].y >= y)
			{
				pUI->PrintMsg("Selection");

				if (z[i]->getselected() == false)
				{
					z[i]->setselected(true);
				}
				else
					z[i]->setselected(false);	


			}
		}
	}

}

void SELECT1::Undo()
{
}

void SELECT1::Redo()
{
}
