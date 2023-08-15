#include <SFML/Graphics.hpp>
#include <iostream>
#include "values.h"
using namespace sf;
using namespace std;

class AnimatedText{
private:
    int count=0;//count of letters currently displayed
    string temp;//temporary string to display par of the massage
    bool finished=false;//are all letters displayed?
    string letters;//full message

    Font font;
    Clock clock;
    Time time;
    Text message;

    float oneLetterTIme(){
        return duration/(float)(letters.length());//time for one letter to appear
    }
    void refreshMessage(){
        message.setString(temp);
    }
    bool timeCheck() {
        return (time <= clock.getElapsedTime());
    }

public:
    AnimatedText(const string &let){
        font.loadFromFile("arial.ttf");

        message.setFont(font);
        message.setString(temp);
        message.setCharacterSize(60);
        message.setPosition(10,35);
        message.setFillColor(sf::Color::White);
        letters=let;
        time = sf::seconds(oneLetterTIme());
    }
    Text getMessage(){
        return message;
    }
    void Animator(){
        if (!finished) {
            if (timeCheck()) {
                if (count < letters.length()) {
                    temp += letters[count];
                    clock.restart();
                } else finished = true;
                count += 1;
            }
        }
        refreshMessage();
    }
};

int main() {

    AnimatedText object(text);
    RenderWindow window(sf::VideoMode(1500, 170), "SFML Application");

    while (window.isOpen()) {
        Event event{};
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        object.Animator();

        window.clear(Color(237,157,88,0));
        window.draw(object.getMessage());
        window.display();
    }
    return 0;
}
