#include <string>
#include <curses.h>

class Window {
private:
	int width;
	int height;
	WINDOW *window;

public:
	Window();
	~Window();
	
	WINDOW *getWindow();
	void setWindow(WINDOW *newWindow);

	int getHeight();
	void setHeight(int newHeight);

	int getWidth();
	void setWidth();



};