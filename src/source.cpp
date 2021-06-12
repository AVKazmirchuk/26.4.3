#include "../include/header.h"

bool cinNoFail()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid data!\n";
        return false;
    }
    else
    {
        if (std::cin.peek() != '\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid data!\n";
            return false;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return true;
}

void Monitor::drawing(int xWindow, int yWindow, int widthWindow, int heightWindow)
{
    for (int i{}; i < widthMonitor + 2; ++i)
        std::cout << '-';

    std::cout << '\n';

    for (int j{}; j < heightMonitor; ++j)
    {
        std::cout << '|';

        for (int i{}; i < widthMonitor; ++i)
        {
            if (j >= yWindow && j <= yWindow + heightWindow - 1 &&
                i >= xWindow && i <= xWindow + widthWindow - 1) std::cout << '1';
            else std::cout << '0';
        }

        std::cout << "|\n";
    }

    for (int i{}; i < widthMonitor + 2; ++i)
        std::cout << '-';

    std::cout << "\n\n";
}

int Monitor::getWidth()
{
    return widthMonitor;
}

int Monitor::getHeight()
{
    return heightMonitor;
}

void Window::move()
{
    while (true)
    {
        std::cout << "Vector-> ";
        int xVector, yVector;
        std::cin >> xVector >> yVector;

        if (cinNoFail())
        {
            int newX = x + xVector;
            int newY = y + yVector;

            if (newX >= 0 && newX <= widthMonitor &&
                newY >= 0 && newY <= heightMonitor &&
                newX + width <= widthMonitor &&
                newY + height <= heightMonitor)
            {
                x = newX;
                y = newY;
                std::cout << "New coordinates accepted: x = " << x << ", y = " << y << '\n';
                break;
            }
            else std::cout << "The coordinates of the window go beyond the screen area!\n";
        }
    }
}

void Window::resize()
{
    while (true)
    {
        std::cout << "New size-> ";
        int newWidth, newHeight;
        std::cin >> newWidth >> newHeight;

        if (cinNoFail())
        {
            if (newWidth > 0 && newHeight > 0 &&
                x + newWidth <= widthMonitor &&
                y + newHeight <= heightMonitor)
            {
                width = newWidth;
                height = newHeight;
                std::cout << "New dimensions accepted: width = " << width << ", height = " << height << '\n';
                break;
            }
            else std::cout << "The dimensions of the window go beyond the screen area!\n";
        }
    }
}

void Window::display()
{
    monitor->drawing(x, y, width, height);
}

void Window::close()
{
    delete monitor;
}

void Window::control()
{
    display();

    std::string command;

    while (true)
    {
        std::cout << "\nCommand: move, resize, display, close: ";

        std::getline(std::cin, command);

        if (command == "move") move();
        else if (command == "resize") resize();
        else if (command == "display") display();
        else if (command == "close")
        {
            close();
            return;
        }
        else std::cout << "Invalid command!\n";
    }
}