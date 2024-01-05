#ifndef _SAVE_H
#define _SAVE_H
#include"Save.h"
#include "../Actions/Action.h"
#include"../Components/Component.h"
#include"../ApplicationManager.h"

class Save : public Action {

public: 
	Save(ApplicationManager* mAPP);
	virtual ~Save();
	virtual void Execute();
	virtual void Undo() ;

	//To redo this action (code depends on action type)
	virtual void Redo();




};
#endif // !_SAVE_H

