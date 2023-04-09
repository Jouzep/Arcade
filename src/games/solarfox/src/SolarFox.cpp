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
            _borderLimit = {content.at(y).size(), content.size()};
            _enemies.setLimits(content.at(y).size(), content.size());
            Wall.setOriginPosition(std::make_pair(x, y));
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
                    _cells.placeCell(x, y);
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
    _cells.eatCell(_playerPos.first, _playerPos.second);
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
        _cells.resetInit();
        _playerPos = std::make_pair(16, 10);
        _direction = LEFT;
        std::cout << "win" << std::endl;
    }
}

void arcade::SolarFox::loseGame()
{

    if (_playerPos.first <= 0 || _playerPos.first >= _borderLimit.first
    || _playerPos.second <= 0 || _playerPos.second >= _borderLimit.second
    || _enemies.isPlayerTouched(_playerPos.first, _playerPos.second)) {
        _cells.resetInit();
        _playerPos = std::make_pair(16, 10);
        _direction = LEFT;
        std::cout << "lose" << std::endl;
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