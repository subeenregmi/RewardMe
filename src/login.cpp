#include <SFML/Graphics.hpp>

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

	while (window.isOpen()){
		sf::Event event;

		while(window.pollEvent(event)){

			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		window.clear();
		window.draw(bg);
		window.draw(title);
		window.display();
	}
}
