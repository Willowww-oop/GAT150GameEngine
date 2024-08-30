#include "ObjectComponent.h"
#include "Engine.h"
#include <string>

void ObjectComponent::Read(const json_t& value)
{
	READ_DATA(value, score);
}

void ObjectComponent::Write(json_t& value)
{
	//
}
