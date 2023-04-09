/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** SolarFox
*/

#include "games/solarfox/SolarFox.hpp"

arcade::SolarFox::SolarFox()
{
    _fr.open("assets/map/map_solarfox.txt");
    _gamecf.setConfigFile("config/game.conf");
    _scorecf.setConfigFile("config/highscores.conf");
    _highName = _scorecf.getConfigData()["SolarFoxName"];
    _highscore = std::stoi(_scorecf.getConfigData()["SolarFox"]);
    _playerPos = std::make_pair(offset.first + 16, offset.second + 10);
}

arcade::SolarFox::~SolarFox()
{
}

arcade::Input arcade::SolarFox::event(arcade::Input input)
{
    return arcade::Input::UNDEFINED;
}

void arcade::SolarFox::pushWalls()
{
    arcade::Tile Wall;

    Wall.setTexture("assets/sprite/solarfox/wall_up.png");
    Wall.setCharacter('-');

    std::vector<std::string> content = _fr.getContent();

    for (int y = 0; y < content.size(); y++) {
        for (int x = 0; content.at(y)[x] != '\0'; x++) {
            _borderLimit = {offset.first + content.at(y).size(), offset.second + content.size()};
            _enemies.setLimits(offset.first + content.at(y).size(), offset.second + content.size());
            Wall.setOriginPosition(std::make_pair(offset.first + x, offset.second + y));
            switch (content[y][x]) {
                case '0':
                    Wall.setTexture("assets/sprite/solarfox/wall_up.png");
                    Wall.setCharacter('-');
                    if (x == 0) {
                        Wall.setCharacter('|');
                        Wall.setTexture("assets/sprite/solarfox/wall_left.png");
                    }
                    if (x == content[y].size() - 1) {
                        Wall.setCharacter('|');
                        Wall.setTexture("assets/sprite/solarfox/wall_right.png");
                        }
                    if (y == content.size() - 1) {
                        Wall.setCharacter('-');
                        Wall.setTexture("assets/sprite/solarfox/wall_down.png");
                        }
                        _objs.push_back(std::make_shared<arcade::Tile>(Wall));
                    break;
                case '1':
                    Wall.setCharacter('+');
                    Wall.setTexture("assets/sprite/solarfox/corner_left_up.png");
                    _objs.push_back(std::make_shared<arcade::Tile>(Wall));
                    break;
                case '2':
                    Wall.setCharacter('+');
                    Wall.setTexture("assets/sprite/solarfox/corner_right_up.png");
                    _objs.push_back(std::make_shared<arcade::Tile>(Wall));
                    break;
                case '3':
                    Wall.setCharacter('+');
                    Wall.setTexture("assets/sprite/solarfox/corner_left_down.png");
                    _objs.push_back(std::make_shared<arcade::Tile>(Wall));
                    break;
                case '4':
                    Wall.setCharacter('+');
                    Wall.setTexture("assets/sprite/solarfox/corner_right_down.png");
                    _objs.push_back(std::make_shared<arcade::Tile>(Wall));
                    break;
                case '5':
                    _cells.placeCell(offset.first + x, offset.second + y);
                    break;
            }
        }
    }
    _cells.validateInit();
}

void arcade::SolarFox::setDirection(arcade::Input input)
{
    switch (input) {
        case arcade::Input::RIGHT:
            if (_direction != DIRECTION::DOWN)
                _direction = DIRECTION::UP;
            break;
        case arcade::Input::LEFT:
            if (_direction != DIRECTION::UP)
                _direction = DIRECTION::DOWN;
            break;
        case arcade::Input::DOWN:
            if (_direction != DIRECTION::LEFT)
                _direction = DIRECTION::RIGHT;
            break;
        case arcade::Input::UP:
            if (_direction != DIRECTION::RIGHT)
                _direction = DIRECTION::LEFT;
            break;
        default:
            break;
    }
}

void arcade::SolarFox::changeDirection(arcade::Tile &player)
{
    switch (_direction) {
        case DIRECTION::UP:
            player.setRotation(0);
            _playerPos = {_playerPos.first, _playerPos.second - 1};
            break;
        case DIRECTION::DOWN:
            player.setRotation(180);
            _playerPos = {_playerPos.first, _playerPos.second + 1};
            break;
        case DIRECTION::RIGHT:
            player.setRotation(90);
            _playerPos = {_playerPos.first + 1, _playerPos.second};
            break;
        case DIRECTION::LEFT:
            player.setRotation(-90);
            _playerPos = {_playerPos.first - 1, _playerPos.second};
            break;
    }
    player.setOriginPosition(_playerPos);
    if (_cells.eatCell(_playerPos.first, _playerPos.second))
        _score += 30;
}

void arcade::SolarFox::pushPlayer()
{
    arcade::Tile player;

    player.setTexture("assets/sprite/solarfox/spaceship.png");
    player.setCharacter('P');
    changeDirection(player);

    _objs.push_back(std::make_shared<arcade::Tile>(player));
}

void arcade::SolarFox::pushGui()
{
    arcade::Text previousGame;
    arcade::Text nextGame;
    arcade::Text previousGraph;
    arcade::Text nextGraph;
    arcade::Text gameName;
    arcade::Text highscoreTxt;
    arcade::Text highName;
    arcade::Text highscore;
    arcade::Text scoreTxt;
    arcade::Text score;

    highscoreTxt.setOriginPosition({70, 10});
    highscoreTxt.setText("HighScore :");

    highName.setOriginPosition({70, 12});
    highName.setText(_highName);

    highscore.setOriginPosition({70, 14});
    highscore.setText(std::to_string(_highscore));

    scoreTxt.setOriginPosition({70, 16});
    scoreTxt.setText("Your score :");

    score.setOriginPosition({70, 18});
    score.setText(std::to_string(_score));

    previousGame.setOriginPosition({2, 45});
    previousGame.setText("'G' previous game");

    nextGame.setOriginPosition({80, 45});
    nextGame.setText("'N' next game");

    previousGraph.setOriginPosition({2, 47});
    previousGraph.setText("'G' previous graph");

    nextGraph.setOriginPosition({80, 47});
    nextGraph.setText("'N' next graph");

    gameName.setOriginPosition({43, 45});
    gameName.setText("SolarFox");

    _objs.push_back(std::make_shared<arcade::Text>(highscoreTxt));
    _objs.push_back(std::make_shared<arcade::Text>(highName));
    _objs.push_back(std::make_shared<arcade::Text>(highscore));
    _objs.push_back(std::make_shared<arcade::Text>(scoreTxt));
    _objs.push_back(std::make_shared<arcade::Text>(score));

    _objs.push_back(std::make_shared<arcade::Text>(nextGame));
    _objs.push_back(std::make_shared<arcade::Text>(previousGame));
    _objs.push_back(std::make_shared<arcade::Text>(nextGraph));
    _objs.push_back(std::make_shared<arcade::Text>(previousGraph));
    _objs.push_back(std::make_shared<arcade::Text>(gameName));

}

void arcade::SolarFox::pushCells()
{
    for (auto cell : _cells.getCells()) {
        _objs.push_back(cell);
    }
}

void arcade::SolarFox::pushEnemies()
{
    _enemies.pushEnemies();
    for (auto enemy : _enemies.getEnemies()) {
        _objs.push_back(enemy);
    }
}

void arcade::SolarFox::winGame()
{
    if (_cells.getCells().size() == 0) {
        restart();
    }
}

void arcade::SolarFox::loseGame()
{

    if (_playerPos.first <= offset.first + 0 || _playerPos.first >= _borderLimit.first
    || _playerPos.second <= offset.second + 0 || _playerPos.second >= _borderLimit.second
    || _enemies.isPlayerTouched(_playerPos.first, _playerPos.second)) {
        restart();
        if (_score > _highscore) {
            _scorecf.saveConfig("SolarFoxName", _gamecf.getConfigData()["name"]);
            _scorecf.saveConfig("SolarFox", std::to_string(_score));
            _highName = _gamecf.getConfigData()["name"];
            _highscore = _score;
        }
        _score = 0;
    }
}

std::vector<std::shared_ptr<arcade::IObject>> arcade::SolarFox::loop(arcade::Input input)
{
    _objs.clear();
    pushWalls();
    setDirection(input);
    pushPlayer();
    pushGui();
    pushCells();
    pushEnemies();
    winGame();
    loseGame();
    return _objs;
}

void arcade::SolarFox::restart()
{
    _cells.resetInit();
    _enemies.restart();
    _playerPos = std::make_pair(offset.first + 16, offset.second + 10);
    _direction = LEFT;
}

std::shared_ptr<arcade::ITile> arcade::SolarFox::createTile()
{

}

std::shared_ptr<arcade::ISound> arcade::SolarFox::createSound()
{

}

std::shared_ptr<arcade::IText> arcade::SolarFox::createText()
{

}

extern "C" arcade::SolarFox *entryPoint() {
    return new (arcade::SolarFox);
}