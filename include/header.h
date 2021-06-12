#pragma once

#include <iostream>
#include <string>

bool cinNoFail();

class Monitor
{
private:

    const int widthMonitor = 80;
    const int heightMonitor = 50;

public:

    void drawing(int xWindow, int yWindow, int widthWindow, int heightWindow);

    int getWidth();

    int getHeight();
};

class Window
{
private:

    int x = 10, y = 10;
    int width = 10, height = 10;

    Monitor* monitor = new Monitor;
    int widthMonitor = monitor->getWidth();
    int heightMonitor = monitor->getHeight();

public:

    void move();

    void resize();

    void display();

    void close();

    void control();
};