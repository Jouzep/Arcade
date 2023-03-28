/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** IGames
*/

#include "../../../../include/IGames.hpp"
#include "../../../../include/games/Music.hpp"
#include "../../../../include/games/Tile.hpp"
#include "../../../../include/games/Text.hpp"
#include <array>

namespace arcade {
    class Sound : virtual public ISound {
        public:
            Sound() {};
            ~Sound() {};
            std::string getSoundPath() {
                return _soundPath;
            }
            float getVolume() {
                return _volume;
            }
            void setSoundPath(std::string path) {
                _soundPath = path;
            }
            void setVolume(float volume) {
                _volume = volume;
            }
            void pauseSound() {};
            void playSound() {};
            void stopSound() {};
        protected:
        private:
            std::string _soundPath;
            float _volume;
    };

    class MenuLib : public IGames {
        public:
            MenuLib();
            ~MenuLib();

            // Menu selector's enum
            enum SELECTOR {
                PLAY,
                SELECT,
                CREDITS,
                QUIT
            };
            enum SCENE {
                MENU_SCENE,
                SELECTOR_SCENE,
                CREDITS_SCENE,
                SETTINGS_SCENE
            };
            // Games selector's enum
            enum GAMES_SELECT {
                PACMAN,
                SNAKE
            };
            void initSettings();
            void initSelections();
            arcade::Input event(arcade::Input input);
            std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
            void restart();
            std::shared_ptr<arcade::ITile> createTile();
            std::shared_ptr<arcade::ISound> createSound();
            std::shared_ptr<arcade::IText> createText();
            void setSelector(int pos);
            void setGameSelector(int pos);
            void setGamePlaceholder();
            std::vector<std::shared_ptr<arcade::IObject>> doNextAction();
        protected:
        private:
            //** Objects **//
            arcade::Tile _background;
            arcade::Music _menuMusic;
            arcade::Text _settingsText;
            arcade::Tile _settings;
            arcade::Text _gameTitle;
            arcade::Text _volumeText;
            arcade::Tile _emptyVolumeTile;
            arcade::Tile _filledVolumeTile;
            arcade::Text _backText;
            arcade::Text _pacmanText;
            arcade::Text _snakeText;
            arcade::Tile _gamePlaceholder;
            arcade::Text _gamePlaceholderText;

            //** Create selectors **//
            // Menu selector
            std::array<arcade::Text, 4> _inputObjs;
            std::array<arcade::Input, 4> _inputEvts;
            int _selectorPos = 0;

            // Games selector
            std::array<arcade::Tile, 2> _gamesObjs;
            std::array<arcade::Input, 2> _gamesEvts;
            std::array<std::string, 2> _gamesName;
            std::array<std::string, 2> _gamesPlaceholderTextures;
            int _gameSelectorPos = 0;

            //** Scenes objects **//
            arcade::MenuLib::SCENE _scene = MENU_SCENE;
            std::vector<std::shared_ptr<arcade::IObject>> _objs;
            std::vector<std::shared_ptr<arcade::IObject>> _menuObjs;
            std::vector<std::shared_ptr<arcade::IObject>> _settingsObjs;
            std::vector<std::shared_ptr<arcade::IObject>> _selectionsObjs;
    };
}

arcade::MenuLib::MenuLib()
{
    _background.setTexture("assets/gui/menu_bg.jpg");
    _background.setName("menu_bg");

    _menuMusic.setSoundPath("assets/sounds/menu.ogg");

    _settings.setTexture("assets/gui/settings.png");
    _settings.setOriginScale(std::make_pair(0.1, 0.1));
    _settings.setOriginPosition(std::make_pair(145, 5));
    // _settings.enableClick();
    _settings.setEvent(arcade::Input::SETTINGS);
    _settings.setSize(std::make_pair(50, 50));
    _settings.setName("settings_icon");

    _gameTitle.setText("Arcade");
    _gameTitle.setOriginPosition(std::make_pair(50, 50));

    _inputObjs[PLAY].setOriginPosition(std::make_pair(50, 600));
    _inputObjs[PLAY].setText("Play");
    // _inputObjs[PLAY].enableClick();
    _inputObjs[PLAY].setColorText(arcade::Color::RED);
    _inputObjs[PLAY].setEvent(arcade::Input::PLAY_GAME);
    _inputObjs[PLAY].setSize(std::make_pair(140, 40));
    _inputObjs[PLAY].setOriginPosition(std::make_pair(50, 600));
    _inputEvts[PLAY] = arcade::Input::PLAY_GAME;

    _inputObjs[SELECT].setOriginPosition(std::make_pair(50, 700));
    _inputObjs[SELECT].setText("Select a game");
    // _inputObjs[SELECT].enableClick();
    _inputObjs[SELECT].setEvent(arcade::Input::SELECT_GAME);
    _inputObjs[SELECT].setSize(std::make_pair(420, 40));
    _inputEvts[SELECT] = arcade::Input::SELECT_GAME;

    _inputObjs[CREDITS].setOriginPosition(std::make_pair(50, 800));
    _inputObjs[CREDITS].setText("Credits");
    // _inputObjs[CREDITS].enableClick();
    // _inputObjs[CREDITS].setEvent(arcade::Input::PLAY_GAME);
    _inputObjs[CREDITS].setSize(std::make_pair(200, 40));
    _inputEvts[CREDITS] = arcade::Input::CREDITS;

    _inputObjs[QUIT].setOriginPosition(std::make_pair(50, 900));
    _inputObjs[QUIT].setText("Quit");
    // _inputObjs[QUIT].enableClick();
    _inputObjs[QUIT].setEvent(arcade::Input::EXIT);
    _inputObjs[QUIT].setSize(std::make_pair(140, 40));
    _inputEvts[QUIT] = arcade::Input::EXIT;

    _backText.setOriginPosition(std::make_pair(50, 900));
    _backText.setText("Back");
    // _backText.enableClick();
    _backText.setEvent(arcade::Input::MENU);
    _backText.setSize(std::make_pair(140, 40));

    _gamePlaceholder.setTexture("assets/gui/menu_game_placeholder.jpg");
    _gamePlaceholder.setName("game_placeholder");
    _gamePlaceholder.setOriginPosition(std::make_pair(85, 23));

    _gamePlaceholderText.setOriginPosition(std::make_pair(1100, 380));
    _gamePlaceholderText.setText("No game selected");

    initSettings();
    initSelections();
    _menuObjs.push_back(std::make_shared<arcade::Tile>(_background));
    _menuObjs.push_back(std::make_shared<arcade::Music>(_menuMusic));
    _menuObjs.push_back(std::make_shared<arcade::Tile>(_settings));
    _menuObjs.push_back(std::make_shared<arcade::Text>(_inputObjs[PLAY]));
    _menuObjs.push_back(std::make_shared<arcade::Text>(_inputObjs[SELECT]));
    _menuObjs.push_back(std::make_shared<arcade::Text>(_inputObjs[CREDITS]));
    _menuObjs.push_back(std::make_shared<arcade::Text>(_inputObjs[QUIT]));
    _menuObjs.push_back(std::make_shared<arcade::Text>(_gameTitle));
    _menuObjs.push_back(std::make_shared<arcade::Text>(_gamePlaceholderText));
    _menuObjs.push_back(std::make_shared<arcade::Tile>(_gamePlaceholder));

    _objs = _menuObjs;
}

arcade::MenuLib::~MenuLib()
{

}

void arcade::MenuLib::initSettings()
{
    _settingsText.setText("Settings");
    _settingsText.setOriginPosition(std::make_pair(50, 50));

    _volumeText.setOriginPosition(std::make_pair(50, 150));
    _volumeText.setText("Volume");

    _emptyVolumeTile.setOriginPosition(std::make_pair(300, 155));
    _emptyVolumeTile.setTexture("assets/sprite/empty_volume.png");

    _filledVolumeTile.setOriginPosition(std::make_pair(300, 155));
    _filledVolumeTile.setTexture("assets/sprite/filled_volume.png");

    _settingsObjs.push_back(std::make_shared<arcade::Tile>(_background));
    _settingsObjs.push_back(std::make_shared<arcade::Music>(_menuMusic));
    _settingsObjs.push_back(std::make_shared<arcade::Text>(_settingsText));
    _settingsObjs.push_back(std::make_shared<arcade::Text>(_volumeText));
    _settingsObjs.push_back(std::make_shared<arcade::Tile>(_emptyVolumeTile));
    _settingsObjs.push_back(std::make_shared<arcade::Tile>(_filledVolumeTile));
    _settingsObjs.push_back(std::make_shared<arcade::Text>(_backText));
}

void arcade::MenuLib::initSelections()
{
    _pacmanText.setText("Pacman");
    _pacmanText.setOriginPosition(std::make_pair(150, 100));

    _gamesObjs[PACMAN].setTexture("assets/gui/pacman_banner.jpg");
    _gamesObjs[PACMAN].setOriginPosition(std::make_pair(5, 10));
    _gamesObjs[PACMAN].setOriginScale(std::make_pair(1.05, 1.05));
    _gamesObjs[PACMAN].setName("pacman_banner");
    // _gamesObjs[PACMAN].enableClick();
    _gamesObjs[PACMAN].setEvent(arcade::Input::PACMAN);
    _gamesObjs[PACMAN].setSize(std::make_pair(400, 600));
    _gamesEvts[PACMAN] = arcade::Input::PACMAN;
    _gamesName[PACMAN] = "Pacman";
    _gamesPlaceholderTextures[PACMAN] = "assets/gui/menu_pacman_placeholder.jpg";

    _snakeText.setText("Snake");
    _snakeText.setOriginPosition(std::make_pair(650, 100));

    _gamesObjs[SNAKE].setTexture("assets/gui/snake_banner.jpg");
    _gamesObjs[SNAKE].setOriginPosition(std::make_pair(45, 10));
    // _gamesObjs[SNAKE].enableClick();
    _gamesObjs[SNAKE].setEvent(arcade::Input::SNAKE);
    _gamesObjs[SNAKE].setSize(std::make_pair(400, 600));
    _gamesObjs[SNAKE].setName("snake_banner");
    _gamesEvts[SNAKE] = arcade::Input::SNAKE;
    _gamesName[SNAKE] = "Snake";
    _gamesPlaceholderTextures[SNAKE] = "assets/gui/menu_snake_placeholder.jpg";

    _selectionsObjs.push_back(std::make_shared<arcade::Tile>(_background));
    _selectionsObjs.push_back(std::make_shared<arcade::Music>(_menuMusic));
    _selectionsObjs.push_back(std::make_shared<arcade::Text>(_backText));
    _selectionsObjs.push_back(std::make_shared<arcade::Text>(_pacmanText));
    _selectionsObjs.push_back(std::make_shared<arcade::Text>(_snakeText));
    _selectionsObjs.push_back(std::make_shared<arcade::Tile>(_gamesObjs[PACMAN]));
    _selectionsObjs.push_back(std::make_shared<arcade::Tile>(_gamesObjs[SNAKE]));
}

arcade::Input arcade::MenuLib::event(arcade::Input input)
{
    if (input == ACTION1) {
        switch (_scene) {
            case MENU_SCENE:
                return _inputEvts[_selectorPos];
            case SELECTOR_SCENE:
                _scene = MENU_SCENE;
                setSelector(-1);
                setGamePlaceholder();
                _objs = _menuObjs;
                return _gamesEvts[_gameSelectorPos];
        }
    }
    return arcade::Input::UNDEFINED;
}

void arcade::MenuLib::setSelector(int pos)
{
    if (_selectorPos + pos < 0 || _selectorPos + pos >= _inputObjs.size())
        return;
    for (int i = 0; i < _inputObjs.size(); i++) {
        _menuObjs.erase(_menuObjs.begin() + 3 + i);
        _inputObjs[i].setColorText(arcade::Color::WHITE);
        _menuObjs.insert(_menuObjs.begin() + 3 + i, std::make_shared<arcade::Text>(_inputObjs[i]));
    }
    _selectorPos += pos;
    _menuObjs.erase(_menuObjs.begin() + 3 + _selectorPos);
    _inputObjs[_selectorPos].setColorText(arcade::Color::RED);
    _menuObjs.insert(_menuObjs.begin() + 3 + _selectorPos, std::make_shared<arcade::Text>(_inputObjs[_selectorPos]));
    _objs = _menuObjs;
}

void arcade::MenuLib::setGameSelector(int pos)
{
    if (_gameSelectorPos + pos < 0 || _gameSelectorPos + pos >= _gamesObjs.size())
        return;
    for (int i = 0; i < _gamesObjs.size(); i++) {
        _selectionsObjs.erase(_selectionsObjs.begin() + 5 + i);
        _gamesObjs[i].setScale(std::make_pair(1, 1));
        _selectionsObjs.insert(_selectionsObjs.begin() + 5 + i, std::make_shared<arcade::Tile>(_gamesObjs[i]));
    }
    _gameSelectorPos += pos;
    _selectionsObjs.erase(_selectionsObjs.begin() + 5 + _gameSelectorPos);
    _gamesObjs[_gameSelectorPos].setScale(std::make_pair(1.05, 1.05));
    _selectionsObjs.insert(_selectionsObjs.begin() + 5 + _gameSelectorPos, std::make_shared<arcade::Tile>(_gamesObjs[_gameSelectorPos]));
    _objs = _selectionsObjs;
}

void arcade::MenuLib::setGamePlaceholder()
{
    std::string selected_txt = "Selected : ";

    _gamePlaceholderText.setText(selected_txt.append(_gamesName[_gameSelectorPos]));
    _gamePlaceholder.setTexture(_gamesPlaceholderTextures[_gameSelectorPos]);
    _menuObjs.pop_back();
    _menuObjs.pop_back();
    _menuObjs.push_back(std::make_shared<arcade::Text>(_gamePlaceholderText));
    _menuObjs.push_back(std::make_shared<arcade::Tile>(_gamePlaceholder));
}

std::vector<std::shared_ptr<arcade::IObject>> arcade::MenuLib::doNextAction()
{
    switch (_inputEvts[_selectorPos]) {
        case arcade::Input::PLAY_GAME:
            break;
        case arcade::Input::SELECT_GAME:
            _scene = SELECTOR_SCENE;
            _objs = _selectionsObjs;
            break;
        case arcade::Input::CREDITS:
            _scene = CREDITS_SCENE;
            break;
        case arcade::Input::EXIT:
            break;
        default:
            break;
    }
    return _objs;
}

std::vector<std::shared_ptr<arcade::IObject>> arcade::MenuLib::loop(arcade::Input input)
{
    // Desordered because key base was in ncurse
    switch (input) {
        // case arcade::Input::UP:
        case arcade::Input::RIGHT:
            if (_scene == MENU_SCENE)
                setSelector(-1);
            break;
        // case arcade::Input::DOWN:
        case arcade::Input::LEFT:
            if (_scene == MENU_SCENE)
                setSelector(1);
            break;
        // case arcade::Input::LEFT:
        case arcade::Input::UP:
            if (_scene == SELECTOR_SCENE)
                setGameSelector(-1);
            break;
        // case arcade::Input::RIGHT:
        case arcade::Input::DOWN:
            if (_scene == SELECTOR_SCENE)
                setGameSelector(1);
            break;
        case arcade::Input::ACTION1:
            _objs = doNextAction();
            break;
        default:
            break;
    }
    return _objs;
}

void arcade::MenuLib::restart()
{

}

std::shared_ptr<arcade::ITile> arcade::MenuLib::createTile()
{

}

std::shared_ptr<arcade::ISound> arcade::MenuLib::createSound()
{

}

std::shared_ptr<arcade::IText> arcade::MenuLib::createText()
{

}


extern "C" arcade::MenuLib *entryPoint() {
    return new (arcade::MenuLib);
}
