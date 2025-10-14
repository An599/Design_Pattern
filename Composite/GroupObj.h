#pragma once
#include <iostream>
#include <vector>
#include <cstring>

struct GraphicObject
{
	virtual void draw() = 0;
};

struct Circle : GraphicObject
{
	void draw() override
	{
		std::cout << " circle " << std::endl;
	}
};

struct Rectangle : GraphicObject
{
	void draw() override
	{
		std::cout << " rectangle " << std::endl;
	}
};

struct Triangle: GraphicObject
{
	void draw() override
	{
		std::cout << " triangle " << std::endl;
	}
};

struct Group :GraphicObject
{
	std::string name;

	explicit Group(const std::string& name) : name(name) {}

	void draw() override
	{
		std::cout << "Group  -" << name.c_str() << "  contains: " << std::endl;
		for (auto&& o : objects)
			o->draw();
	}
	std::vector<GraphicObject*> objects;
};
