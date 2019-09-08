#include "input.h"

namespace kidsnow {

Input::Input()
{
}


Input::Input(const Input& other)
{
}


Input::~Input()
{
}


void Input::initialize()
{
	int i;


	// Initialize all the keys to being released and not pressed.
	for (i = 0; i < 256; i++)
	{
		m_keys[i] = false;
	}

	return;
}


void Input::keyDown(KEYVALUE input)
{
	// If a key is pressed then save that state in the key array.
	m_keys[(unsigned int)input] = true;
	return;
}


void Input::keyUp(KEYVALUE input)
{
	// If a key is released then clear that state in the key array.
	m_keys[(unsigned int)input] = false;
	return;
}


bool Input::isKeyDown(KEYVALUE key)
{
	// Return what state the key is in (pressed/not pressed).
	return m_keys[(unsigned int)key];
}

}