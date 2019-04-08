#pragma once
class Input
{
private:
	struct Mouse
	{
		int x, y;
		bool left;
	};
public:
	Input();
	~Input();

	void setKeyDown(int key);
	void setKeyUp(int key);
	bool isKeyDown(int key);

	void setMouseX(int lx);
	void setMouseY(int ly);
private:
	bool keys[256]{ false };
	bool LeftMouseButton = false;
	bool RightMouseButton = false;
	Mouse mouse;
};

