/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** IGames
*/

#include "../../../../include/IGames.hpp"
#include "../../../../include/games/menu/Music.hpp"
#include "../../../../include/games/menu/Tile.hpp"
#include "../../../../include/games/menu/Text.hpp"

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
            std::vector<std::shared_ptr<arcade::IObject>> _objs;
    };
}

arcade::MenuLib::MenuLib()
{
    _background.setTexture("assets/gui/menu_bg.jpg");
    _menuMusic.setSoundPath("assets/sounds/menu.ogg");
    _settings.setTexture("assets/gui/settings.png");
    _settings.setOriginScale(std::make_pair(0.1, 0.1));
    _settings.setOriginPosition(std::make_pair(1100, 50));
    _settings.unableClick();
    _settings.setEvent(arcade::Input::SETTINGS);
    _gameTitle.setText("Arcade");
    _gameTitle.setPosition(std::make_pair(50, 50));
    _settingsText.setText("Settings");
    _settingsText.setPosition(std::make_pair(50, 50));

    _objs.push_back(std::make_shared<arcade::Tile>(_background));
    _objs.push_back(std::make_shared<arcade::Music>(_menuMusic));
    _objs.push_back(std::make_shared<arcade::Tile>(_settings));
    _objs.push_back(std::make_shared<arcade::Text>(_gameTitle));
}

arcade::MenuLib::~MenuLib()
{

}

void arcade::MenuLib::event()
{

}

std::vector<std::shared_ptr<arcade::IObject>> arcade::MenuLib::loop(arcade::Input input)
{
    if (input == arcade::Input::SETTINGS) {
        _objs.erase(_objs.begin() + 2);
        _objs.erase(_objs.begin() + 3);
        _objs.push_back(std::make_shared<arcade::Text>(_settingsText));
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
