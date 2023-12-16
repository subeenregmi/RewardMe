#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(){
	auto window = sf::RenderWindow{{1920u, 1080u}, "CMAKE Test"};
	while (window.isOpen()){
		for (auto event = sf::Event{}; window.pollEvent(event);){
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		window.clear();
		window.display();
	}
}
