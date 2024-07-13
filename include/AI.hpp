#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>

#include "Game.hpp"

namespace Sonar {
  class AI {
    private:
      int aiPiece;
      int playerPiece;
      std::vector<std::array<int, 6>> checkMatchVector;
      GameDataRef _data;

      void CheckSection(int x1, int y1, int x2, int y2, int X, int Y, int pieceToCheck, int (*gridArray)[3][3], sf::Sprite gridPieces[3][3]);
      void CheckIfPieceIsEmpty(int X, int Y, int (*gridArray)[3][3], sf::Sprite gridPieces[3][3]);
    public:
      AI (int playerPiece, GameDataRef data);
      void PlacePiece(int (*gridArray)[3][3], sf::Sprite gridPieces[3][3], int *gameState);
  };
}