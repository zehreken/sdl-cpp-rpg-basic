#ifndef primitives_hpp
#define primitives_hpp

class Vector2
{
public:
	float x, y;
	Vector2();
	Vector2(float, float);
};

class IntVector2
{
public:
	int x, y;
	IntVector2();
	IntVector2(int, int);
};

class Vector3
{
public:
	float x, y, z;
	Vector3();
	Vector3(float, float, float);
};

int add(int, int);

#endif /* primitives_hpp */
