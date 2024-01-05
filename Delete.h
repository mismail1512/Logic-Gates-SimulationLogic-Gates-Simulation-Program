#pragma once
#include "Actions/Action.h"
class Delete : public Action
{
public:
	
	Delete(ApplicationManager* pApp);
	virtual ~Delete(void);
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

