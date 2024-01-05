#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;
}

GraphicsInfo * Component::get_component_PGInfo()
{
	return m_pGfxInfo;
}

/*GraphicsInfo* Component::get_component_PGInfo()
{
	return m_pGfxInfo;
}
*/
Component::Component()
{}

Component::~Component()
{
	m_pGfxInfo->~GraphicsInfo();
};

