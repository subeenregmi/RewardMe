#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include <button.hpp>

int main(){
	sf::RenderWindow window(sf::VideoMode(400, 400), "button test");
	Padding p;
	p.x = 10;
	p.y = 10;
	sf::Font f;
	f.loadFromFile("../assets/fonts/WorkSans.ttf");
	Button b("Login", &f, sf::Color::Black, sf::IntRect(150, 150, 150, 90), sf::Color::Blue, p);

	while (window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}

			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if(event.type == sf::Event::MouseButtonPressed){
				if(event.mouseButton.button == sf::Mouse::Left){
					b.handleMouse(mousePos, true);
				}
				else{
					b.handleMouse(mousePos, false);
				}
			}
			else{
				b.handleMouse(mousePos, false);
			}

			if(b.buttonPressed){
				std::cout << "Button Pressed!" << std::endl;
			}

			if(event.type == sf::Event::MouseButtonReleased){
				if(event.mouseButton.button == sf::Mouse::Left){
					b.buttonPressed = false;
				}
			}
		}
		window.clear(sf::Color::White);
		window.draw(b.button);
		window.draw(b.text);
		window.display();
	}
}

