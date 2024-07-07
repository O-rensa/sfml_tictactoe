#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace Sonar {
  class GameState : public State {
    private:
      GameDataRef _data;
      sf::Sprite _background;
      sf::Sprite _pauseButton;
      int turn;
      int gameState;

    public:
      GameState(GameDataRef data);
      void Init();
      void HandleInput();
      void Update(float dt);
      void Draw(float dt);
  };
}