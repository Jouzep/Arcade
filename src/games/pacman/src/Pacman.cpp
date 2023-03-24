/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Pacman
*/

#include "games/pacman/Pacman.hpp"

std::pair<int, int> find_pose(char index, std::vector<std::string> _map)
{
    for (int i = 0; i < 25; i++) {
        for (int a = 0; a < 25 ; a++) {
            if (_map[i][a] == index)
                return std::make_pair(i, a);
        }
    }
    return std::make_pair(0, 0);
}

arcade::Pacman::Pacman()
{
    restart();
}

arcade::Pacman::~Pacman()
{
}

std::pair<int, int> arcade::Pacman::getPose(int index) const
{
    return this->_pose[index];
}

void arcade::Pacman::reset_ghost(int index, std::vector<std::string> _map)
{
    this->_pose[index] = find_pose(index + 48 + 3, _map);
    this->_move[index] = std::make_pair(0, 0);
    this->direction[index] = 0;
    this->_mob[index] = START;
    this->mobid = 0;
    this->score += 50;
};

void arcade::Pacman::setPose(std::pair<int, int> pose)
{
    this->_pose.push_back(pose);
}

bool arcade::Pacman::getLoose(std::vector<std::string> _map)
{
    for (int i = ENEMY1; i <= ENEMY4; i++)
        if (this->_pose[PACMAN] == this->_pose[i])
            if (this->mod == 1)
                reset_ghost(i, _map);
            else
                return true;
    return false;
};

std::vector<std::string> arcade::Pacman::print_pacman(std::pair<int, int> pose, std::vector<std::string> _map)
{
    attron(COLOR_PAIR(2) | A_BOLD);
    if (pose.second != 24 || pose.second != 0) {
        switch (this->direction[PACMAN]) {
        case UP:
            pose.first += 6 - 1;
        case DOWN:
            pose.first += 6 + 1;
        case RIGHT:
            pose.second += 1;
        case LEFT:
            pose.second -= 1;
        }
    }
    if (_map[pose.first][pose.second] == '0' || _map[pose.first][pose.second] == '2') {
        if (_map[pose.first][pose.second] == '2') {
            this->mod = 1;
            this->_game->setScore(20);
        } else
            this->_game->setScore(0);
        _map[pose.first][pose.second] = ' ';
        this->_game->setWin(this->_game->getWin() - 1);
    }
    mvprintw(pose.first, pose.second, "O");
    attroff(COLOR_PAIR(2) | A_BOLD);
    return _map;
}

void arcade::Pacman::print_ghost(std::pair<int, int> pose, int direction, int mob)
{
    attron(COLOR_PAIR(mob) | A_BOLD);
    if (pose.second != 24 || pose.second != 0) {
        switch (direction) {
        case UP :
            pose.first -= 1;
        case DOWN :
            pose.first += 1;
        case RIGHT :
            pose.second += 1;
        case LEFT :
            pose.second -= 1;
        }
    }
    mvprintw(pose.first, pose.second, "O");
    attroff(COLOR_PAIR(mob) | A_BOLD);
};

arcade::Input arcade::Pacman::whichInput()
{
    int res = rand() % 4;

    switch (res) {
    case 0:
        return arcade::Input::LEFT;
    case 1:
        return arcade::Input::RIGHT;
    case 2:
        return arcade::Input::UP;
    case 3:
        return arcade::Input::DOWN;
    }
}

void arcade::Pacman::care_ghost(std::vector<std::string> _map)
{
    if (this->_mob[this->mobid] == MOVE && tick % 10 == 0) {
        this->_pose[this->mobid] = find_pose('9', _map);
        this->_pose[this->mobid].first -= 1;
        change_direction(whichInput(), _map, this->mobid);
        this->_mob[this->mobid] = ALIVE;
    }
    if ((tick % 30 == 0 && tick != 0) && this->mobid <= ENEMY4) {
        this->mobid++;
        this->_mob[this->mobid] = MOVE;
    }
    for (int i = ENEMY1; i <= ENEMY4; i++) {
        if ((tick % 10 == 0 && this->_mob[i] == ALIVE) ||( _map[this->_pose[i].first + this->_move[i].first][this->_pose[i].second + this->_move[i].second] != '0' && this->_mob[i] != START)) {
            change_direction(whichInput(), _map, i);
        }
        changePose(_map, i);
        if (this->mod == 1)
            print_ghost(this->_pose[i], this->direction[i], 7);
        else
            print_ghost(this->_pose[i], this->direction[i], i + 2);
    }
    if (tick % 100 == 0)
        this->mod = 0;
    tick++;
};

void arcade::Pacman::change_direction(arcade::Input key, std::vector<std::string> _map, int mob)
{
    switch (_pose[mob].second) {
        case 24:
            _pose[mob].second = 0;
            return;
        case 0:
            _pose[mob].second = 24;
            return;
    }
    if (key == UP && _map[_pose[mob].first - 1][_pose[mob].second] != '1' && _map[_pose[mob].first - 1][_pose[mob].second] != '9') {
        this->_move[mob] = std::make_pair(-1, 0);
    }
    if (key == DOWN && _map[_pose[mob].first + 1][_pose[mob].second] != '1' && _map[_pose[mob].first + 1][_pose[mob].second] != '9') {
        this->_move[mob] = std::make_pair(1, 0);
    }
    if (key == LEFT && _map[_pose[mob].first][_pose[mob].second - 1] != '1' && _map[_pose[mob].first][_pose[mob].second - 1] != '9') {
        this->_move[mob] = std::make_pair(0, -1);
    }
    if (key == RIGHT && _map[_pose[mob].first][_pose[mob].second + 1] != '1' && _map[_pose[mob].first][_pose[mob].second + 1] != '9') {
        this->_move[mob] = std::make_pair(0, 1);
    }
};

void arcade::Pacman::handlingEvent(arcade::Input input, int mob)
{
    switch (input)
    {
    case arcade::Input::UNDEFINED:
        break;
    case arcade::Input::LEFT:
    case arcade::Input::RIGHT:
    case arcade::Input::UP:
    case arcade::Input::DOWN:
        change_direction(input, this->_game->getMap(), mob);
        break;
    case arcade::Input::ACTION1:
        break;
    case arcade::Input::NEXTGRAPH:
        break;
    case arcade::Input::NEXTGAME:
        break;
    case arcade::Input::PREVIOUSGRAPH:
        break;
    case arcade::Input::PREVIOUSGAME:
        break;
    case arcade::Input::RESTART:
        break;
    case arcade::Input::MENU:
        break;
    case arcade::Input::EXIT:
        break;
    }
}

void arcade::Pacman::changePose(std::vector<std::string> map, int mob) {
    if (map[_pose[mob].first][_pose[mob].second + _move[mob].second] != '1' && map[_pose[mob].first][_pose[mob].second + _move[mob].second] != '9')
        this->_pose[mob].second += _move[mob].second;
    if (map[_pose[mob].first + _move[mob].first][_pose[mob].second] != '1' && map[_pose[mob].first + _move[mob].first][_pose[mob].second] != '9')
        this->_pose[mob].first += _move[mob].first;
};

void arcade::Pacman::do_game()
{
        timeout(200);
        clear();
        this->changePose(this->_game->getMap(), PACMAN);
        this->_game->print_other();
        this->care_ghost(this->_game->getMap());
        this->_game->setMap(this->print_pacman(this->getPose(PACMAN), this->_game->getMap()));
        refresh();
        if (this->_game->getWin() == 0|| this->getLoose(this->_game->getMap()) == true);
}

void arcade::Pacman::createObjet()
{
    this->_object.clear();

    createMap(this->_game->getMap());
    createSound();
    createText();
    createTile();
}

void arcade::Pacman::createMap(std::vector<std::string> _map)
{
    for (int i = 0; i <= _map.max_size(); i++)
        for (int a = 0; a <= _map[i].length(); a++) {
            setMapTile(createTile(), std::make_pair(i, a));
        }
}

char whichCharacter(std::vector<std::string> _map, std::pair<int, int> position)
{
    switch (_map[position.first][position.second]) {
    case '1':
    case '9':
    case ' ':
        return ' ';
    case '0':
    case '2':
        return '.';
    case '6':
    case '4':
    case '5':
    case '7':
    case '3':
        return '0';
    }
}

arcade::Color arcade::Pacman::whichColor(std::vector<std::string> _map, std::pair<int, int> position)
{
    switch (_map[position.first][position.second]) {
    case '1':
        return BLUE;
    case '9':
        return WHITE;
    case ' ':
        return DARK;
    case '0':
    case '2':
    case '3':
        return YELLOW;
    case '6':
        return RED;
    case '4':
        return GREEN;
    case '5':
        return BLUE;
    case '7':
        return WHITE;
    }
}

void arcade::Pacman::setMapTile(std::shared_ptr<arcade::ITile> tile, std::pair<int, int> position)
{
    tile->setCharacter(whichCharacter(this->_game->getMap(), position));
    tile->setPosition(position);
    tile->setColor(whichColor(this->_game->getMap(), position));
    tile->setScale(std::make_pair(1, 1));
    tile->setRotation(0);
    _object.push_back(tile);
}

void arcade::Pacman::pushText()
{
    setText(createText(), "Your Score:", std::make_pair((this->_map.first + 1), (_map.second + 1)));
    setText(createText(), std::to_string(this->_game->getScore()), std::make_pair(_map.first + 2, _map.second + 1));
}


void arcade::Pacman::setText(std::shared_ptr<arcade::IText> text, std::string content, std::pair<std::size_t, std::size_t> position)
{
    text->setColorText(arcade::Color::WHITE);
    text->setPosition(position);
    text->setText(content);
    this->_object.push_back(text);
}

void arcade::Pacman::pushSound()
{
    setSound(createSound(), "path", 1);
}
void arcade::Pacman::setSound(std::shared_ptr<arcade::ISound> sound, std::string soundPath, float volume)
{
    sound->setSoundPath(soundPath);
    sound->setVolume(volume);
    this->_object.push_back(sound);
}

std::shared_ptr<arcade::ISound> arcade::Pacman::createSound()
{
    return std::make_shared<arcade::Music>();
}

std::shared_ptr<arcade::ITile> arcade::Pacman::createTile()
{
    return std::make_shared<arcade::Tile>();
}

std::shared_ptr<arcade::IText> arcade::Pacman::createText()
{
    return std::make_shared<arcade::Text>();
}

void arcade::Pacman::restart()
{
    this->_map = std::make_pair(25, 25);
    this->mobid = ENEMY1;
    this->mod = 0;
    this->score = 0;
    srand(time(NULL));
    this->tick = 0;
    for (int i = PACMAN; i <= ENEMY4; i++) {
        this->direction.push_back(0);
        this->_move.push_back(std::make_pair(0, 0));
        this->_mob.push_back(START);
    }
    this->setPose(find_pose('3', _game->getMap()));
    this->setPose(find_pose('4', _game->getMap()));
    this->setPose(find_pose('5', _game->getMap()));
    this->setPose(find_pose('6', _game->getMap()));
    this->setPose(find_pose('7', _game->getMap()));
    this->_mob[ENEMY1] = MOVE;
}

std::vector<std::shared_ptr<arcade::IObject>> arcade::Pacman::loop(arcade::Input input)
{
    do_game();
    handlingEvent(input, PACMAN);
    return this->_object;
}

extern "C" arcade::Pacman *entryPoint()
{
    return new (arcade::Pacman);
}