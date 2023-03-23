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

            void initSettings();
            void initSelections();
            void event();
            std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input);
            void restart();
            std::shared_ptr<arcade::ITile> createTile();
            std::shared_ptr<arcade::ISound> createSound();
            std::shared_ptr<arcade::IText> createText();
        protected:
        private:
            arcade::Tile _background;
            arcade::Music _menuMusic;
            arcade::Text _settingsText;
            arcade::Tile _settings;
            arcade::Text _gameTitle;
            arcade::Text _playText;
            arcade::Text _selectGameText;
            arcade::Text _creditsText;
            arcade::Text _quitText;
            arcade::Text _volumeText;
            arcade::Tile _emptyVolumeTile;
            arcade::Tile _filledVolumeTile;
            arcade::Text _backText;
            arcade::Text _pacmanText;
            arcade::Tile _pacmanBanner;
            arcade::Text _snakeText;
            arcade::Tile _snakeBanner;
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
    _settings.unableClick();
    _settings.setEvent(arcade::Input::SETTINGS);
    _settings.setSize(std::make_pair(50, 50));
    _settings.setName("settings_icon");

    _gameTitle.setText("Arcade");
    _gameTitle.setOriginPosition(std::make_pair(50, 50));

    _playText.setOriginPosition(std::make_pair(50, 300));
    _playText.setText("Play");
    _playText.unableClick();
    _playText.setEvent(arcade::Input::PLAY_GAME);
    _playText.setSize(std::make_pair(140, 40));

    _selectGameText.setOriginPosition(std::make_pair(50, 400));
    _selectGameText.setText("Select a game");
    _selectGameText.unableClick();
    _selectGameText.setEvent(arcade::Input::SELECT_GAME);
    _selectGameText.setSize(std::make_pair(250, 40));

    _creditsText.setOriginPosition(std::make_pair(50, 500));
    _creditsText.setText("Credits");
    _creditsText.unableClick();
    // _creditsText.setEvent(arcade::Input::PLAY_GAME);
    _creditsText.setSize(std::make_pair(200, 40));

    _quitText.setOriginPosition(std::make_pair(50, 600));
    _quitText.setText("Quit");
    _quitText.unableClick();
    _quitText.setEvent(arcade::Input::EXIT);
    _quitText.setSize(std::make_pair(140, 40));

    _backText.setOriginPosition(std::make_pair(50, 600));
    _backText.setText("Back");
    _backText.unableClick();
    _backText.setEvent(arcade::Input::MENU);
    _backText.setSize(std::make_pair(140, 40));

    initSettings();
    initSelections();
    _menuObjs.push_back(std::make_shared<arcade::Tile>(_background));
    _menuObjs.push_back(std::make_shared<arcade::Music>(_menuMusic));
    _menuObjs.push_back(std::make_shared<arcade::Tile>(_settings));
    _menuObjs.push_back(std::make_shared<arcade::Text>(_playText));
    _menuObjs.push_back(std::make_shared<arcade::Text>(_selectGameText));
    _menuObjs.push_back(std::make_shared<arcade::Text>(_creditsText));
    _menuObjs.push_back(std::make_shared<arcade::Text>(_quitText));
    _menuObjs.push_back(std::make_shared<arcade::Text>(_gameTitle));

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

    _pacmanBanner.setTexture("assets/gui/pacman_banner.jpg");
    _pacmanBanner.setOriginPosition(std::make_pair(5, 10));
    _pacmanBanner.setName("pacman_banner");
    // _pacmanBanner.unableClick();
    // _pacmanBanner.setEvent(arcade::Input::SETTINGS);
    // _pacmanBanner.setSize(std::make_pair(400, 600));

    _snakeText.setText("Snake");
    _snakeText.setOriginPosition(std::make_pair(650, 100));

    _snakeBanner.setTexture("assets/gui/snake_banner.jpg");
    _snakeBanner.setOriginPosition(std::make_pair(45, 10));
    _snakeBanner.setName("snake_banner");

    _selectionsObjs.push_back(std::make_shared<arcade::Tile>(_background));
    _selectionsObjs.push_back(std::make_shared<arcade::Music>(_menuMusic));
    _selectionsObjs.push_back(std::make_shared<arcade::Text>(_backText));
    _selectionsObjs.push_back(std::make_shared<arcade::Text>(_pacmanText));
    _selectionsObjs.push_back(std::make_shared<arcade::Tile>(_pacmanBanner));
    _selectionsObjs.push_back(std::make_shared<arcade::Text>(_snakeText));
    _selectionsObjs.push_back(std::make_shared<arcade::Tile>(_snakeBanner));
}

void arcade::MenuLib::event()
{

}

std::vector<std::shared_ptr<arcade::IObject>> arcade::MenuLib::loop(arcade::Input input)
{
    if (input == arcade::Input::SETTINGS) {
        _objs = _settingsObjs;
    }
    if (input == arcade::Input::MENU) {
        _objs = _menuObjs;
    }
    if (input == arcade::Input::SELECT_GAME) {
        _objs = _selectionsObjs;
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
