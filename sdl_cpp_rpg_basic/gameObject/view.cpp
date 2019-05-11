#include "view.hpp"

View::View(GameObject *p_parent)
{
	_p_parent = p_parent;
}

View::~View()
{
    
}

void View::render()
{
    
}

GameObject *View::p_parent()
{
	return _p_parent;
}
