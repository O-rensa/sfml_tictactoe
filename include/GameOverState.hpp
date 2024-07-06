#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace Sonar {
  class GameOverState: public State {
    private:
      GameDataRef _data;
      sf::Sprite _retryButton;
      sf::Sprite _homeButton;

    public:
      GameOverState(GameDataRef _data);
      void Init();
      void HandleInput();
      void Update(float dt);
      void Draw(float dt);
  };
}