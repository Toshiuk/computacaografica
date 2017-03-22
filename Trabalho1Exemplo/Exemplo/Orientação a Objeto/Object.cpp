#pragma once
#include "Object.h"
#include "Scene.h"

Object::Object() :r(0), g(0), b(0)
{
	Scene::addObject(this);
}


Object::~Object()
{
}


void Object::rotate()
{
}

void Object::translate()
{

}

void Object::scale()
{

}

void Object::color(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
}
