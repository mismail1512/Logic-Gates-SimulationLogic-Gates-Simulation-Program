#ifndef _LOAD_
#define _LOAD_
#include"../Actions/Action.h"
#include"../ApplicationManager.h"

class Load : public Action {

public:
	Load(ApplicationManager* pAPP);
	virtual ~Load();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();



};


#endif // !_LOAD_
