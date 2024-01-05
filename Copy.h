#pragma once
#include "Actions/Action.h"
class Copy : public Action
{
public:
	
	Copy(ApplicationManager* pApp);
	virtual ~Copy(void);
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

