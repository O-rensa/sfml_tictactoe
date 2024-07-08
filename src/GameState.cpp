#include <sstream>
#include <iostream>

#include "../include/GameState.hpp"
#include "../include/DEFINITIONS.hpp"
#include "../include/PauseState.hpp"
#include "../include/GameOverState.hpp"

namespace Sonar {
  GameState::GameState(GameDataRef data) : _data(data){}

  void GameState::Init() {
    this->gameState = STATE_PLAYING;
    this->turn = PLAYER_PIECE;
    // Loading Textures
    this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
    this->_data->assets.LoadTexture("Grid Sprite", GRID_SPRITE_FILEPATH);
    this->_data->assets.LoadTexture("X Piece", X_PIECE_FILEPATH);
    this->_data->assets.LoadTexture("O Piece", O_PIECE_FILEPATH);
    this->_data->assets.LoadTexture("Game State Background", GAME_BACKGROUND_FILEPATH);
    // Setting Textures
    this->_background.setTexture(this->_data->assets.GetTexture("Background"));
    this->_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));
    this->_gridSprite.setTexture(this->_data->assets.GetTexture("Grid Sprite"));
    // Setting Positions
    this->_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width, _pauseButton.getPosition().y);
    this->_gridSprite.setPosition((SCREEN_WIDTH / 2) - (_gridSprite.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_gridSprite.getGlobalBounds().height / 2));
    // Initialize GridPieces
    InitGridPieces();

    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 3; y++) {
        gridArray[x][y] = 0;
      }
    }
  }

  void GameState::HandleInput() {
    sf::Event event;
    while (this->_data->window.pollEvent(event)) {
      if (sf::Event::Closed == event.type){
        this->_data->window.close();
      }
      
      if (this->_data->input.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window)){
        this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
      }
    }
  }

  void GameState::Update(float dt) {
    
  }

  void GameState::Draw(float dt) {
    this->_data->window.clear();
    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_pauseButton);
    this->_data->window.draw(this->_gridSprite);
    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 3; y++) {
        this->_data->window.draw(this->_gridPieces[x][y]);
      }
    }
    this->_data->window.display();
  }

  void GameState::InitGridPieces() {
    sf::Vector2u tempSpriteSize = this->_data->assets.GetTexture("X Piece").getSize();

    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 3; y++) {
        _gridPieces[x][y].setTexture(this->_data->assets.GetTexture("X Piece"));
        _gridPieces[x][y].setPosition(_gridSprite.getPosition().x + (tempSpriteSize.x * x) - 7, _gridSprite.getPosition().y + (tempSpriteSize.y * y) - 7);
        _gridPieces[x][y].setColor(sf::Color(255, 255, 255, 0));
      }
    }
  }
}