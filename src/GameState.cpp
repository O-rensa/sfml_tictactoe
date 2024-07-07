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
    this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
    this->_data->assets.LoadTexture("Game State Background", GAME_BACKGROUND_FILEPATH);
    this->_background.setTexture(this->_data->assets.GetTexture("Background"));
    this->_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));

    this->_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width, _pauseButton.getPosition().y);
  }

  void GameState::HandleInput() {
    sf::Event event;
    while (this->_data->window.pollEvent(event)) {
      if (sf::Event::Closed == event.type){
        this->_data->window.close();
      }
      
      if (this->_data->input.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window)){
        //this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
        this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
      }
    }
  }

  void GameState::Update(float dt) {
    
  }

  void GameState::Draw(float dt) {
    this->_data->window.clear();
    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_pauseButton);
    this->_data->window.display();
  }
}