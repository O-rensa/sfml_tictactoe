set(src_files 
  AssetManager.cpp
  Game.cpp
  InputManager.cpp
  SplashState.cpp
  StateMachine.cpp
  MainMenuState.cpp
  GameState.cpp
  PauseState.cpp
  GameOverState.cpp
)

add_library(srclib
  ${src_files}
)

target_link_libraries( srclib
  sfml-system
  sfml-window
  sfml-graphics
)

target_include_directories(
  srclib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)