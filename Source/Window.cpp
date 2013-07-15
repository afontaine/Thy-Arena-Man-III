#include "../Header/curses.h"
#include <string>
#include "../Header/Gui.h"
#include "../Header/Window.h"

using namespace std;

Window::Window(int height, int width, int posY, int posX) {
	this->Width = width;
	this->Height = height;
	this->window = newwin(height, width, posY, posX);
}

Window::~Window() {
	delwin(this->window);
}

WINDOW *Window::getWindow() {
	return this->window;
}
void Window::setWindow(WINDOW *newWindow) {
	delwin(this->window);
	this->window = newWindow;
}

int Window::getHeight() {
	return this->Height;
}

void Window::setHeight(int newHeight) {
	this->Height = newHeight;
}

int Window::getWidth() {
	return this->Width;
}

void Window::setWidth(int newWidth) {
	this->Width = newWidth;
}