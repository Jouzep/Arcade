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

std::vector<std::string> get_file_content(const std::string filename) {
    std::ifstream _file(filename);
    std::vector<std::string> content;
    std::string line;
    if (_file.is_open())
    {
        while (std::getline(_file, line))
            content.push_back(line);
        _file.close();
    }
    else
        exit;
    return content;
}

arcade::Pacman::Pacman()
{
    this->map = std::make_pair(25, 25);
    restart();
}

arcade::Pacman::~Pacman()
{
}

void arcade::Pacman::restart()
{
    this->_map = get_file_content("assets/map/map.txt");
    this->mobid = ENEMY1;
    this->mod = 0;
    this->score = 0;
    this->tick = 0;
    this->win = 220;
    for (int i = PACMAN; i <= ENEMY4; i++) {
        this->direction.push_back(0);
        this->_move.push_back(std::make_pair(0, 0));
        this->_mob.push_back(START);
        this->_pose.push_back(std::make_pair(0, 0));
    }
    this->_mob[ENEMY1] = MOVE;
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
    std::cout << pose.second << pose.first << std::endl;
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
            this->score += 20;
        } else
            this->score += 0;
        _map[pose.first][pose.second] = ' ';
        this->win--;
    }
    return _map;
}

void arcade::Pacman::print_ghost(std::pair<int, int> pose, int direction, int mob)
{
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

void arcade::Pacman::changePose(std::vector<std::string> map, size_t mob) {
    if (map[_pose[mob].first][_pose[mob].second + _move[mob].second] != '1' && map[_pose[mob].first][_pose[mob].second + _move[mob].second] != '9')
        this->_pose[mob].second += _move[mob].second;
    if (map[_pose[mob].first + _move[mob].first][_pose[mob].second] != '1' && map[_pose[mob].first + _move[mob].first][_pose[mob].second] != '9')
        this->_pose[mob].first += _move[mob].first;
};

void arcade::Pacman::care_ghost(std::vector<std::string> _map)
{
    if (this->_mob[this->mobid] == MOVE && tick % 10 == 0) {
        this->_pose[this->mobid] = find_pose('9', _map);
        this->_pose[this->mobid].first -= 1;
        change_direction(whichInput(), _map, this->mobid);
        this->_mob[this->mobid] = ALIVE;
    }
    if ((tick % 30 == 0 && tick != 0) && this->mobid <= ENEMY4 - 1) {
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
    if (key == arcade::Input::UP && _map[_pose[mob].first - 1][_pose[mob].second] != '1' && _map[_pose[mob].first - 1][_pose[mob].second] != '9') {
        this->_move[mob] = std::make_pair(-1, 0);
    }
    if (key == arcade::Input::DOWN && _map[_pose[mob].first + 1][_pose[mob].second] != '1' && _map[_pose[mob].first + 1][_pose[mob].second] != '9') {
        this->_move[mob] = std::make_pair(1, 0);
    }
    if (key == arcade::Input::LEFT && _map[_pose[mob].first][_pose[mob].second - 1] != '1' && _map[_pose[mob].first][_pose[mob].second - 1] != '9') {
        this->_move[mob] = std::make_pair(0, -1);
    }
    if (key == arcade::Input::RIGHT && _map[_pose[mob].first][_pose[mob].second + 1] != '1' && _map[_pose[mob].first][_pose[mob].second + 1] != '9') {
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
        change_direction(input, this->_map, mob);
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

void arcade::Pacman::do_game()
{
    // timeout(200);
    // clear();
    this->changePose(_map, PACMAN);
    // print_other(_map, this->getScore());
    this->care_ghost(_map);
    _map = this->print_pacman(this->getPose(PACMAN), _map);
    // if (this->getWin() == 0|| this->getLoose(_map) == true)
    // this->change_direction(_input, _map, PACMAN);
    createObjet();
}

void arcade::Pacman::createObjet()
{
    this->_object.clear();

    createMap(this->_map);
    // createSound();
    // createText();
    // createTile();
}

char whichCharacter(std::vector<std::string> _map, std::pair<std::size_t, std::size_t> position)
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

arcade::Color arcade::Pacman::whichColor(std::vector<std::string> _map, std::pair<std::size_t, std::size_t> position)
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

std::string arcade::Pacman::whichSprite(std::vector<std::string> _map, std::pair<std::size_t, std::size_t> position)
{
    switch (_map[position.first][position.second]) {
    case '1':
        return BLUEBOX;
    case '9':
        return WHITEBOX;
    case ' ':
        return BLACKBOX;
    case '0':
        return LITTLEFOOD;
    case '2':
        return FOOD;
    case '3':
    case '6':
    case '4':
    case '5':
    case '7':
        return REDBOX;
    }
}

void arcade::Pacman::createMap(std::vector<std::string> _map)
{
    for (int i = 0; i <= 25 - 1; i++)
        for (int a = 0; a <= 25 - 1; a++)
            setMapTile(createTile(), std::make_pair(a, i));
}

void arcade::Pacman::setMapTile(std::shared_ptr<arcade::ITile> tile, std::pair<std::size_t, std::size_t> position)
{
    tile->setCharacter(whichCharacter(this->_map, position));
    tile->setPosition(std::make_pair(position.second, position.first));
    tile->setColor(whichColor(this->_map, position));
    tile->setScale(std::make_pair(1, 1));
    tile->setRotation(0);
    tile->setTexture(whichSprite(this->_map, position));
    _object.push_back(tile);
}

void arcade::Pacman::pushText()
{
    setText(createText(), "Your Score:", std::make_pair((this->map.first + 1), (map.second + 1)));
    setText(createText(), std::to_string(this->score), std::make_pair(map.first + 2, map.second + 1));
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


std::vector<std::shared_ptr<arcade::IObject>> arcade::Pacman::loop(arcade::Input input)
{
    handlingEvent(input, PACMAN);
    do_game();
    return this->_object;
}

extern "C" arcade::Pacman *entryPoint()
{
    return new (arcade::Pacman);
}