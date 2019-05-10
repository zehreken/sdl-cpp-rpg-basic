#ifndef gameObject_hpp
#define gameObject_hpp

#include "../primitives/primitives.hpp"
#include "transform.hpp"

class GameObject
{
public:
	GameObject();
private:
	Transform *transform;
};

#endif /* gameObject_hpp */
