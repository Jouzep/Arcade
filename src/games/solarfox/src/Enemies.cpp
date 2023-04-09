/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Enemies
*/

#include "games/solarfox/Enemies.hpp"

arcade::Enemies::Enemies() :  _gen(std::random_device{}())
{
}

arcade::Enemies::~Enemies()
{
}

void arcade::Enemies::setLimits(int x, int y)
{
    if (x != _borderLimit.first && y != _borderLimit.second) {
        _borderLimit = {x, y};
        _enemyPos = {
            std::make_pair(0, 0),
            std::make_pair(_borderLimit.first, 0),
            std::make_pair(_borderLimit.first, _borderLimit.second),
            std::make_pair(0, _borderLimit.second)
            };
    }
}

void arcade::Enemies::moveProjectiles()
{
    // std::vector<arcade::Tile> tmp = _projectiles;
    // _projectiles.clear();
    for (int i = 0; i < _projectiles.size(); i++) {
        switch (_projectilesDirection[i]) {
            case DIRECTION::UP:
                _projectiles[i].setOriginPosition({_projectiles[i].getOriginPosition().first, _projectiles[i].getOriginPosition().second - 1});
                // if (_projectiles[i].getOriginPosition().second <= 0) {
                //     _projectiles.erase(_projectiles.begin() + i);
                //     i--;
                // }
                break;
            case DIRECTION::RIGHT:
                _projectiles[i].setOriginPosition({_projectiles[i].getOriginPosition().first + 1, _projectiles[i].getOriginPosition().second});
                // if (_projectiles[i].getOriginPosition().first >= _borderLimit.first) {
                //     _projectiles.erase(_projectiles.begin() + i);
                //     i--;
                // }
                break;
            case DIRECTION::DOWN:
                _projectiles[i].setOriginPosition({_projectiles[i].getOriginPosition().first, _projectiles[i].getOriginPosition().second + 1});
                // if (_projectiles[i].getOriginPosition().second >= _borderLimit.second) {
                //     _projectiles.erase(_projectiles.begin() + i);
                //     i--;
                // }
                break;
            case DIRECTION::LEFT:
                _projectiles[i].setOriginPosition({_projectiles[i].getOriginPosition().first - 1, _projectiles[i].getOriginPosition().second});
                // if (_projectiles[i].getOriginPosition().first <= 0) {
                //     _projectiles.erase(_projectiles.begin() + i);
                //     i--;
                // }
                break;
        }
    }
}

void arcade::Enemies::createProjectile(DIRECTION direction, std::pair<int, int> pos)
{
    arcade::Tile missile;

    missile.setTexture("assets/sprite/solarfox/missile.png");
    missile.setOriginPosition(pos);
    switch (direction) {
        case DIRECTION::UP:
            missile.setRotation(270);
            break;
        case DIRECTION::RIGHT:
            missile.setRotation(0);
            break;
        case DIRECTION::DOWN:
            missile.setRotation(90);
            break;
        case DIRECTION::LEFT:
            missile.setRotation(180);
            break;
    }

    _projectilesDirection.push_back(direction);
    _projectiles.push_back(missile);
}

void arcade::Enemies::enemyShoot()
{
    std::uniform_int_distribution<> dis(0, 15);
    std::array<int, 4> randomShot = {dis(_gen), dis(_gen), dis(_gen), dis(_gen)};
    for (int i = 0; i < 4; i++) {
        if (randomShot[i] == 1) {
            switch (i) {
                case 0:
                    createProjectile(DIRECTION::DOWN, _enemyPos[i]);
                    break;
                case 1:
                    createProjectile(DIRECTION::LEFT, _enemyPos[i]);
                    break;
                case 2:
                    createProjectile(DIRECTION::UP, _enemyPos[i]);
                    break;
                case 3:
                    createProjectile(DIRECTION::RIGHT, _enemyPos[i]);
                    break;
            }
        }
    }
    moveProjectiles();
    for (auto project : _projectiles)
        _objs.push_back(std::make_shared<arcade::Tile>(project));

}

void arcade::Enemies::restart()
{
    _projectiles.clear();
    _projectilesDirection.clear();
}

bool arcade::Enemies::isPlayerTouched(int x, int y)
{
    for (int i = 0; i < _projectiles.size(); i++) {
        switch (_projectilesDirection[i]) {
            case DIRECTION::UP:
                if (_projectiles[i].getOriginPosition().first == x
                && _projectiles[i].getOriginPosition().second >= y - 1 &&  _projectiles[i].getOriginPosition().second <= y) {
                    restart();
                    return true;
                }
                break;
            case DIRECTION::RIGHT:
                if (_projectiles[i].getOriginPosition().first >= x && _projectiles[i].getOriginPosition().first <= x + 1
                && _projectiles[i].getOriginPosition().second == y) {
                    restart();
                    return true;
                }
                break;
            case DIRECTION::DOWN:
                if (_projectiles[i].getOriginPosition().first == x
                && _projectiles[i].getOriginPosition().second >= y &&  _projectiles[i].getOriginPosition().second <= y + 1) {
                    restart();
                    return true;
                }
                break;
            case DIRECTION::LEFT:
                if (_projectiles[i].getOriginPosition().first >= x - 1 && _projectiles[i].getOriginPosition().first <= x
                && _projectiles[i].getOriginPosition().second == y) {
                    restart();
                    return true;
                }
                break;
        }
    }
    return false;
}

void arcade::Enemies::moveEnemies()
{
    for (size_t i = 0; i < TOTAL_ENEMY; i++) {
        switch (_enemyDirection[i]) {
            case DIRECTION::UP:
                _enemyPos[i] = std::make_pair(_enemyPos[i].first, _enemyPos[i].second - 1);
                if (_enemyPos[i].second <= 0)
                    _enemyDirection[i] = DIRECTION::DOWN;
                // _enemyDirection[i] = DIRECTION::DOWN;
                break;
            case DIRECTION::RIGHT:
                _enemyPos[i] = std::make_pair(_enemyPos[i].first + 1, _enemyPos[i].second);
                if (_enemyPos[i].first >= _borderLimit.first)
                    _enemyDirection[i] = DIRECTION::LEFT;
                break;
            case DIRECTION::DOWN:
                _enemyPos[i] = std::make_pair(_enemyPos[i].first, _enemyPos[i].second + 1);
                if (_enemyPos[i].second >= _borderLimit.second)
                    _enemyDirection[i] = DIRECTION::UP;
                break;
            case DIRECTION::LEFT:
                _enemyPos[i] = std::make_pair(_enemyPos[i].first - 1, _enemyPos[i].second);
                if (_enemyPos[i].first <= 0)
                    _enemyDirection[i] = DIRECTION::RIGHT;
                break;
        }
    }
}

void arcade::Enemies::pushEnemies()
{
    _objs.clear();
    arcade::Tile upEnemy;
    arcade::Tile rightEnemy;
    arcade::Tile downEnemy;
    arcade::Tile leftEnemy;

    upEnemy.setTexture("assets/sprite/solarfox/enemy.png");
    upEnemy.setOriginPosition(_enemyPos[0]);
    upEnemy.setRotation(180);

    rightEnemy.setTexture("assets/sprite/solarfox/enemy.png");
    rightEnemy.setOriginPosition(_enemyPos[1]);
    rightEnemy.setRotation(270);

    downEnemy.setTexture("assets/sprite/solarfox/enemy.png");
    downEnemy.setOriginPosition(_enemyPos[2]);
    downEnemy.setRotation(0);

    leftEnemy.setTexture("assets/sprite/solarfox/enemy.png");
    leftEnemy.setOriginPosition(_enemyPos[3]);
    leftEnemy.setRotation(90);


    _objs.push_back(std::make_shared<arcade::Tile>(upEnemy));
    _objs.push_back(std::make_shared<arcade::Tile>(rightEnemy));
    _objs.push_back(std::make_shared<arcade::Tile>(downEnemy));
    _objs.push_back(std::make_shared<arcade::Tile>(leftEnemy));

    moveEnemies();
    enemyShoot();
}

 std::vector<std::shared_ptr<arcade::IObject>> arcade::Enemies::getEnemies()
{
    return _objs;
}
