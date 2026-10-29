#include <iostream>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>

int main() {
	std::cout << "Play A Tune? \n Type Y to play! \n";

	std::string Prompt = "";
	std::cin >> Prompt;
	sf::Music tunes;

	if (Prompt == "Y" || Prompt == "y") {
		if (!tunes.openFromFile("filename")) {
			std::cout << "Tune invalid.";
			system("pause");
			return -1;
		}

		tunes.setLooping(true);
		tunes.play();
		std::cout << "Jamming!\n";

		while (true) {
			std::cout << "[P]ause  [R]esume  [Q]uit \n";
			std::cin >> Prompt;

			if (Prompt == "P" || Prompt == "p") {
				tunes.pause();
				std::cout << "Tune paused. \n";
			}
			else if (Prompt == "R" || Prompt == "r") {
				tunes.play();
				std::cout << "Resuming! \n";
			}
			else if  (Prompt == "Q" || Prompt == "q") {
				break;
			}
		}
	}

	return 0;
}