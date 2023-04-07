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
            void initCredits();
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
            std::array<arcade::Text, 4> _creditTexts;

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
            std::vector<std::shared_ptr<arcade::IObject>> _creditsObjs;
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
    _settings.setName("settings_icon");

    _gameTitle.setText("Arcade");
    _gameTitle.setOriginPosition(std::make_pair(2, 2));

    _inputObjs[PLAY].setOriginPosition(std::make_pair(2, 30));
    _inputObjs[PLAY].setText("Play");
    // _inputObjs[PLAY].enableClick();
    _inputObjs[PLAY].setColorText(arcade::Color::RED);
    _inputObjs[PLAY].setEvent(arcade::Input::PLAY_GAME);
    _inputEvts[PLAY] = arcade::Input::PLAY_GAME;

    _inputObjs[SELECT].setOriginPosition(std::make_pair(2, 35));
    _inputObjs[SELECT].setText("Select a game");
    // _inputObjs[SELECT].enableClick();
    _inputObjs[SELECT].setEvent(arcade::Input::SELECT_GAME);
    _inputEvts[SELECT] = arcade::Input::SELECT_GAME;

    _inputObjs[CREDITS].setOriginPosition(std::make_pair(2, 40));
    _inputObjs[CREDITS].setText("Credits");
    // _inputObjs[CREDITS].enableClick();
    // _inputObjs[CREDITS].setEvent(arcade::Input::PLAY_GAME);
    _inputEvts[CREDITS] = arcade::Input::CREDITS;

    _inputObjs[QUIT].setOriginPosition(std::make_pair(2, 45));
    _inputObjs[QUIT].setText("Quit");
    // _inputObjs[QUIT].enableClick();
    _inputObjs[QUIT].setEvent(arcade::Input::EXIT);
    _inputEvts[QUIT] = arcade::Input::EXIT;

    _backText.setOriginPosition(std::make_pair(5, 45));
    _backText.setText("Back");
    // _backText.enableClick();
    _backText.setEvent(arcade::Input::MENU);

    _gamePlaceholder.setTexture("assets/gui/menu_game_placeholder.jpg");
    _gamePlaceholder.setName("game_placeholder");
    _gamePlaceholder.setOriginPosition(std::make_pair(50, 23));

    _gamePlaceholderText.setOriginPosition(std::make_pair(55, 20));
    _gamePlaceholderText.setText("No game selected");

    initSettings();
    initSelections();
    initCredits();
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
    _pacmanText.setOriginPosition(std::make_pair(7, 7));

    _gamesObjs[PACMAN].setTexture("assets/gui/pacman_banner.jpg");
    _gamesObjs[PACMAN].setOriginPosition(std::make_pair(3, 10));
    _gamesObjs[PACMAN].setOriginScale(std::make_pair(1.05, 1.05));
    _gamesObjs[PACMAN].setName("pacman_banner");
    // _gamesObjs[PACMAN].enableClick();
    _gamesObjs[PACMAN].setEvent(arcade::Input::PACMAN);
    _gamesEvts[PACMAN] = arcade::Input::PACMAN;
    _gamesName[PACMAN] = "Pacman";
    _gamesPlaceholderTextures[PACMAN] = "assets/gui/menu_pacman_placeholder.jpg";

    _snakeText.setText("Snake");
    _snakeText.setOriginPosition(std::make_pair(35, 7));

    _gamesObjs[SNAKE].setTexture("assets/gui/snake_banner.jpg");
    _gamesObjs[SNAKE].setOriginPosition(std::make_pair(30, 10));
    // _gamesObjs[SNAKE].enableClick();
    _gamesObjs[SNAKE].setEvent(arcade::Input::SNAKE);
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

void arcade::MenuLib::initCredits()
{
    _creditTexts[0].setText("Developpers:");
    _creditTexts[0].setOriginPosition(std::make_pair(37, 5));

    _creditTexts[1].setText("Joseph Yu");
    _creditTexts[1].setOriginPosition(std::make_pair(38, 10));

    _creditTexts[2].setText("Steven Dong");
    _creditTexts[2].setOriginPosition(std::make_pair(38, 15));

    _creditTexts[3].setText("Vincent Shao");
    _creditTexts[3].setOriginPosition(std::make_pair(38, 20));

    _creditsObjs.push_back(std::make_shared<arcade::Tile>(_background));
    for (auto txt : _creditTexts) {
        _creditsObjs.push_back(std::make_shared<arcade::Text>(txt));
    }
}

arcade::Input arcade::MenuLib::event(arcade::Input input)
{
    if (input == ACTION1) {
        switch (_scene) {
            case CREDITS_SCENE:
                _scene = MENU_SCENE;
                setSelector(-2);
                _objs = _menuObjs;
                break;
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
            _objs = _creditsObjs;
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
    return std::make_shared<arcade::Tile>();
}

std::shared_ptr<arcade::ISound> arcade::MenuLib::createSound()
{
    return std::make_shared<arcade::Music>();
}

std::shared_ptr<arcade::IText> arcade::MenuLib::createText()
{
    return std::make_shared<arcade::Text>();
}


extern "C" arcade::MenuLib *entryPoint() {
    return new (arcade::MenuLib);
}
