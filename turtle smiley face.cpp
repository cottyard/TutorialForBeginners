#include "turtle.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Smiley Face");
	Turtle turtle(window);
	turtle.color(sf::Color::Yellow);
	
	turtle.pd();
	for (int i = 0; i < 360; ++i) {
	    turtle.fd(2);
	    turtle.rt(1);
	}

	turtle.pu();
	turtle.go(300, 250);
	turtle.pd();
	turtle.color(sf::Color::Black);
	for (int i = 0; i < 360; ++i) {
	    turtle.fd(0.5);
	    turtle.lt(1);
	}
	
	turtle.pu();
	turtle.go(500, 250);
	turtle.pd();
	for (int i = 0; i < 360; ++i) {
	    turtle.fd(0.5);
	    turtle.lt(1);
	}
	
	turtle.pu();
	turtle.go(340, 400);
	turtle.color(sf::Color::Black);
	turtle.pd();
	turtle.rt(90);
	for (int i = 0; i < 180; ++i) {
	    turtle.fd(2);
	    turtle.lt(1);
	}
	
	while (window.isOpen()) {
		sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
		}
	    window.clear(sf::Color::White);
	    turtle.draw();
	    window.display();
	}
}
