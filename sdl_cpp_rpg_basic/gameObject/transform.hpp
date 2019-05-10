#ifndef transform_hpp
#define transform_hpp

#include "../primitives/primitives.hpp"

class Transform
{
public:
	Transform();
	void setPosition(float x, float y);
	void setPosition(Vector2 position);
	void translate(float x, float y);
	void translate(Vector2 deltaPosition);
	Vector2 getPosition();
	void setScale(float x, float y);
	void setScale(Vector2 scale);
	Vector2 getScale();
private:
	Vector2 position;
	Vector2 scale;
};

#endif /* transform_hpp */
