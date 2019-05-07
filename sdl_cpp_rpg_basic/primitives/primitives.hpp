#ifndef primitives_hpp
#define primitives_hpp

class Vector2
{
public:
	float x, y;
	Vector2();
	Vector2(float, float);
//	~Vector2();
};

class IntVector2
{
public:
	int x, y;
	IntVector2();
	IntVector2(int, int);
//	~IntVector2();
};

class Vector3
{
public:
	float x, y, z;
	Vector3();
	Vector3(float, float, float);
	~Vector3();
};

int add(int, int);

#endif /* primitives_hpp */
