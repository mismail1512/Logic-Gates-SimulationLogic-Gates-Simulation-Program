#ifndef _SELECT_H
#define _SELECT_H
#include "./Action.h"

class SELECT1 : public Action
{

private:
	int k, y;

public:
	SELECT1(ApplicationManager* pApp);
	virtual ~SELECT1(void);
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif 