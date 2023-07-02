#include<SFML/Graphics.hpp>
#include<iostream>
#include"Ludo.h"
#include"Board.h"
#include"Piece.h"
#include<Windows.h>
#include<stdexcept>
using namespace std;
using namespace sf;

void landing_page(RenderWindow& window, int& no_of_players, bool& is_Cheating) {

	Texture imageTexture;
	imageTexture.loadFromFile("ludoking.jpg");

	Sprite imageSprite;
	imageSprite.setTexture(imageTexture);
	imageSprite.setOrigin(0, 0);
	imageSprite.setScale(1.2f, 1.3f);

	Texture imageTextureCopy;
	imageTextureCopy.loadFromFile("ludokingCopy.jpg");

	Sprite imageSpriteCopy;
	imageSpriteCopy.setTexture(imageTextureCopy);
	imageSpriteCopy.setOrigin(0, 0);
	imageSpriteCopy.setScale(1.2f, 1.3f);

	Texture imageTextureCopyCheat;
	imageTextureCopyCheat.loadFromFile("ludokingCopyCheat.png");

	Sprite imageSpriteCopyCheat;
	imageSpriteCopyCheat.setTexture(imageTextureCopyCheat);
	imageSpriteCopyCheat.setOrigin(0, 0);
	imageSpriteCopyCheat.setScale(1.7f, 1.85f);



	Font font;
	font.loadFromFile("ParfaiteValeu.ttf");

	Text playText;
	playText.setFont(font);
	playText.setString("Play");
	playText.setCharacterSize(160);
	playText.setFillColor(Color::White);
	playText.setStyle(Text::Bold);

	FloatRect textBounds = playText.getLocalBounds();
	playText.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
	playText.setPosition(window.getSize().x * 0.20, window.getSize().y * 0.50);



	Text twoPlay;
	twoPlay.setFont(font);
	twoPlay.setString("2 Player");
	twoPlay.setCharacterSize(36);
	twoPlay.setFillColor(Color::White);
	twoPlay.setStyle(Text::Bold);
	twoPlay.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	twoPlay.setPosition(window.getSize().x * .25, window.getSize().y / 2 - 100);

	Text fourPlay;
	fourPlay.setFont(font);
	fourPlay.setString("4 Player");
	fourPlay.setCharacterSize(36);
	fourPlay.setFillColor(Color::White);
	fourPlay.setStyle(Text::Bold);
	fourPlay.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	fourPlay.setPosition(window.getSize().x * .25, window.getSize().y / 2);

	Text sixPlay;
	sixPlay.setFont(font);
	sixPlay.setString("6 Player");
	sixPlay.setCharacterSize(36);
	sixPlay.setFillColor(Color::White);
	sixPlay.setStyle(Text::Bold);
	sixPlay.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	sixPlay.setPosition(window.getSize().x * .25, window.getSize().y / 2 + 100);

	Text cheat;
	cheat.setFont(font);
	cheat.setString("Do you want to cheat?");
	cheat.setCharacterSize(40);
	cheat.setFillColor(Color::White);
	cheat.setStyle(Text::Bold);
	cheat.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	cheat.setPosition(window.getSize().x * .25, window.getSize().y * .45);



	Text yes;
	yes.setFont(font);
	yes.setString("Definetely Yesss!!!");
	yes.setCharacterSize(32);
	yes.setFillColor(Color::White);
	yes.setStyle(Text::Bold);
	yes.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	yes.setPosition(window.getSize().x * .25, window.getSize().y * .80);


	Text no;
	no.setFont(font);
	no.setString("I wanna do a fair game");
	no.setCharacterSize(32);
	no.setFillColor(Color::White);
	no.setStyle(Text::Bold);
	no.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	no.setPosition(window.getSize().x * .25, window.getSize().y * .90);


	bool playing = false;
	bool twoPlaying = false;
	bool fourPlaying = false;
	bool sixPlaying = false;
	bool cheating = false;
	is_Cheating = false;
	bool alldone = false;


	Event event;
	while (window.isOpen() and !alldone) {
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				if (!playing && playText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					window.clear();
					playing = true;
					//iska nichay update marna ha game ko 
					// Display the new image and text
					event.mouseButton.x = 0;
				}

				if (playing && !twoPlaying && twoPlay.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{

					cout << "two player selected";
					no_of_players = 2;
					twoPlaying = true;
				}

				else if (playing && !fourPlaying && fourPlay.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					no_of_players = 4;
					cout << "four player selected";
					fourPlaying = true;

				}

				else if (playing && !sixPlaying && sixPlay.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					cout << "six player selected";
					no_of_players = 6;
					sixPlaying = true;


				}

				if (playing && !is_Cheating && yes.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					cout << "cheating";
					is_Cheating = true;
					alldone = true;
					//play game with cheating
				}

				if (playing && !is_Cheating && no.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					cout << "not cheating";
					is_Cheating = false;
					alldone = true;
					//start the game with whatever number of player selected
				}
			}
		}
		window.clear();

		if (!playing)
		{
			window.draw(imageSprite);
			window.draw(playText);
		}
		if ((!twoPlaying and !fourPlaying and !sixPlaying) and playing and !is_Cheating)
		{
			//window.draw(imageSprite1);
			window.draw(imageSpriteCopy);

			window.draw(twoPlay);
			window.draw(fourPlay);
			window.draw(sixPlay);
		}

		if (((twoPlaying or fourPlaying or sixPlaying) and playing) and !cheating)
		{
			window.clear();
			window.draw(imageSpriteCopyCheat);

			window.draw(cheat);
			window.draw(yes);
			window.draw(no);
		}


		window.display();
	}

}

int main() {
	int n = 0;
	int dice_selection = -99;
	bool six = false;
	bool WrongDice = false;
	int nop =0;
	bool isCheating = false;

	sf::RenderWindow window(sf::VideoMode(2150, 1340), "Wehsi Ludo");
	window.setPosition(sf::Vector2i(200, 0));

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		landing_page(window, nop, isCheating);
		break;
	}

	Ludo game(nop,isCheating);

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed and game.cheating and n == 0 and game.CheatRollDice(window, event.key.code - 26, six))
			{
				game.Ps[game.turn]->moves++;
				if (!six) {
					n = 1;
				}
				if (game.three_sixes()) {
					game.Ps[game.turn]->moves = 0;
					game.dice_no.clear();
					game.changeTurn();
					n = 0;
				}

			}
			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
				sf::Vector2f click = window.mapPixelToCoords(mousePosition);
				int C_pos = game.Selection(click);
				cout << click.x << " " << click.y << endl;
				if (n == 0 and !game.cheating and game.RollDice(window, click, six)) {
					game.Ps[game.turn]->moves++;
					if (!six) {
						n = 1;
					}
					click.x = 0;
					if (game.three_sixes()) {
						game.Ps[game.turn]->moves = 0;
						game.dice_no.clear();
						game.changeTurn();
						n = 0;
					}
				}

				if (n == 1) {

					if (game.dice_no.size() == 1) {
						dice_selection = 1;
						n++;
						if (!game.canMakeAMove(dice_selection - 1)) {
							game.Ps[game.turn]->moves = 0;
							game.dice_no.clear();
							game.changeTurn();
							n = 0;
						}
					}
					else {
						dice_selection = game.selectDices(click);
						if (dice_selection != -99)
							n++;
					}
				}


				if (n == 2) {

					int C_pos = game.Selection(click);
					cout << "\n-----------\n";
					cout << game.no_of_Players << endl;
					cout << game.board.pieces.size() << endl;
					cout<<"Pos: " << C_pos << endl;
					if (game.isValidSelection(C_pos, game.dice_no[dice_selection - 1], WrongDice)) {
						if (game.canMakeAMove(dice_selection - 1)) {
							game.board.move(game.dice_no[dice_selection - 1], C_pos, game.turn, game.piece_moved,game.no_of_Players);
							game.Ps[game.turn]->moves--;
							game.dice_no.erase(game.dice_no.begin() + (dice_selection - 1));
							if (game.areAllMovesDone()) {
								game.dice_no.clear();
								game.changeTurn();
								n = 0;
							}
							else
								n = 1;
							if (game.is_being_killed()) {
								game.kill();
							}
						}
						game.is_Done();
					}
					else if (WrongDice) {
						cout << "done\n";
						n = 1;
					}
				}
			}
		}

		window.clear();
		game.board.printBoard(window,game.no_of_Players);
		game.displayDice(window);
		game.printTurn(window);
		game.print_positions(window);
		window.display();
	}

	return 0;
}

