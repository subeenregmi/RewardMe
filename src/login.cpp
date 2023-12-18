#include <SFML/Graphics.hpp>
#include <button.hpp>
#include <iostream>

int main(){
	sf::RenderWindow window(sf::VideoMode(275, 500), "RewardMe", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	sf::Texture bgTexture;
	bgTexture.loadFromFile("../assets/images/loginBackground.jpg");
	//bgTexture.setSmooth(true);

	sf::Sprite bg;
	bg.setTexture(bgTexture);

	sf::Font font;
	font.loadFromFile("../assets/fonts/WorkSans.ttf");
	font.setSmooth(true);

	sf::Text title("RewardMe", font, 40); 
	title.setFillColor(sf::Color::White);
	title.setOutlineColor(sf::Color(47, 45, 46));
	title.setOutlineThickness(7.5f);
	title.setPosition(40, 40);

	Padding p;
	p.x = 10; p.y = 10;
	Button loginButton("Login", &font, sf::Color::White, sf::IntRect(87, 250, 100, 50), sf::Color(88, 99, 248), p);

	while (window.isOpen()){
		sf::Event event;

		while(window.pollEvent(event)){

			if (event.type == sf::Event::Closed){
				window.close();
			}
			
			// Button handling
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (event.type == sf::Event::MouseButtonPressed){
				if (event.mouseButton.button == sf::Mouse::Left){
					loginButton.handleMouse(mousePos, true);
				}
				else{
					loginButton.handleMouse(mousePos, false);
				}
			}
			else{
				loginButton.handleMouse(mousePos, false);
			}
			/*
			if (event.type == sf::Event::MouseButtonReleased){
				if (event.mouseButton.button == sf::Mouse::Left){
					loginButton.buttonPressed = false;
				}
			}
			*/

			if (loginButton.buttonPressed){
				// Oauth logic here
			}
			
		}
		window.clear();
		window.draw(bg);
		window.draw(loginButton.button);
		window.draw(loginButton.text);
		window.draw(title);
		window.display();
	}
}
