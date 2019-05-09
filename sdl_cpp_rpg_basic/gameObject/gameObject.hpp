#ifndef gameObject_hpp
#define gameObject_hpp

#include "../primitives/primitives.hpp"

class GameObject
{
public:
	GameObject();
	void setPosition(float x, float y);
	void setPosition(Vector2 pos);
	void translate(float x, float y);
	void translate(Vector2 deltaPos);
	Vector2 getPosition();
private:
	Vector2 position;
};

#endif /* gameObject_hpp */
