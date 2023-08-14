#include <SFML/Graphics.hpp>
#include <iostream>
#include "values.h"
using namespace sf;
using namespace std;

int main() {
    char letters[]=text;

    int count=0;//count of letters currently displayed
    string temp;//temporary string to display par of the massage
    temp+=letters[0];
    bool finished =false;//are all letters displayed?

    Time time = sf::seconds(duration/(float)(sizeof(letters)-1));
    Clock clock;

    RenderWindow window(sf::VideoMode(1500, 170), "SFML Application");

    Font font;
    font.loadFromFile("arial.ttf");

    Text message;
    message.setFont(font);
    message.setString(temp);
    message.setCharacterSize(60);
    message.setPosition(10,35);
    message.setFillColor(sf::Color::White);



    while (window.isOpen()) {
        Event event{};
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        if (!finished) {
            if (time <= clock.getElapsedTime()) {
                count += 1;
                if (count < sizeof(letters)-1) {
                    temp += letters[count];
                    clock.restart();
                } else finished = true;
            }
        }
        message.setString(temp);
        window.clear(Color(237,157,88,0));
        window.draw(message);
        window.display();
    }
    return 0;
}
