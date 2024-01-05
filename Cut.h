#pragma once
#include "Actions/Action.h"
class Cut : public Action
{
public:
	
	Cut(ApplicationManager* pApp);
	virtual ~Cut(void);
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

