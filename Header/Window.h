#include "curses.h"

class Window {
private:
	int Width;
	int Height;
	WINDOW *window;

public:
	Window(int height, int width, int posY, int posX);
	~Window();
	
	WINDOW *getWindow();
	void setWindow(WINDOW *newWindow);

	int getHeight();
	void setHeight(int newHeight);

	int getWidth();
	void setWidth(int newWidth);
	


};