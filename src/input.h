#pragma once

namespace kidsnow {

enum class KEYVALUE
{
	NUM_0,
	NUM_1,
	NUM_2,
	NUM_3,
	NUM_4,
	NUM_5,
	NUM_6,
	NUM_7,
	NUM_8,
	NUM_9,
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	SPECIAL_SHIFT,
	SPECIAL_CONTROL,
	SPECIAL_ALT,
};

class Input
{
public:
	Input();
	Input(const Input&);
	~Input();

	void initialize();

	void keyDown(KEYVALUE);
	void keyUp(KEYVALUE);

	bool isKeyDown(KEYVALUE);

private:
	bool m_keys[256];
};

} // end of kidsnow