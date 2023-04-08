/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Pacman
*/

#include "games/pacman/Pacman.hpp"

// ***************** CONSTRUCTOR ****************

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
    try {
        conf.setConfigFile("config/highscores.conf");
    } catch (ConfHandler::ConfHandlerError) {
        highestscore = "NONE";
    }
    this->highestscore = conf.getConfigData()["Pacman"];
    this->highestname = conf.getConfigData()["PacmanName"];
    this->map = std::make_pair(25, 25);
    restart();
}

arcade::Pacman::~Pacman()
{
}

void arcade::Pacman::restart()
{
    this->_pose.clear();
    this->direction.clear();
    this->_move.clear();
    this->_mob.clear();
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
    }
    this->_pose.push_back(find_pose('3', _map));
    this->_pose.push_back(find_pose('4', _map));
    this->_pose.push_back(find_pose('5', _map));
    this->_pose.push_back(find_pose('6', _map));
    this->_pose.push_back(find_pose('7', _map));
    this->_mob[ENEMY1] = MOVE;
}

// ******************** GETTER *****************

std::pair<int, int> arcade::Pacman::getPose(int index) const
{
    return this->_pose[index];
}

bool arcade::Pacman::getLoose(std::vector<std::string> _map, int mob)
{
    if (this->_pose[PACMAN] == this->_pose[mob])
        if (this->mod == 1)
            reset_ghost(mob, _map);
        else
            return true;
    return false;
};

// ****************** CLASS SETTER ********************

void arcade::Pacman::setPose(std::pair<int, int> pose)
{
    this->_pose.push_back(pose);
}

void arcade::Pacman::setMove(std::pair<int, int> move, int mob)
{
    this->_move[mob].first = move.first;
    this->_move[mob].second = move.second;
}

// ******************* GAME LOGIC ********************

void arcade::Pacman::reset_ghost(int index, std::vector<std::string> _map)
{
    this->_pose[index] = find_pose(index + 48 + 3, _map);
    this->_move[index] = std::make_pair(0, 0);
    this->direction[index] = 0;
    this->_mob[index] = START;
    this->mobid = 0;
    this->score += 50;
};

std::vector<std::string> arcade::Pacman::print_pacman(std::pair<int, int> pose, std::vector<std::string> _map)
{
    if (_map[pose.first][pose.second] == '0' || _map[pose.first][pose.second] == '2') {
        if (_map[pose.first][pose.second] == '2') {
            this->mod = 1;
            this->score += 20;
        } else
            this->score += 10;
        _map[pose.first][pose.second] = ' ';
        this->win--;
    }
        if (pose.second != 24 || pose.second != 0) {
            switch (this->direction[PACMAN]) {
            case UP:
                pose.first -= 1;
            case DOWN:
                pose.first += 1;
            case RIGHT:
                pose.second += 1;
            case LEFT:
                pose.second -= 1;
            }
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
    return arcade::Input::UNDEFINED;
}

void arcade::Pacman::changePose(std::vector<std::string> map, size_t mob)
{
    if (map[_pose[mob].first][_pose[mob].second + _move[mob].second] != '1' && map[_pose[mob].first][_pose[mob].second + _move[mob].second] != '9')
        this->_pose[mob].second += _move[mob].second;
    if (map[_pose[mob].first + _move[mob].first][_pose[mob].second] != '1' && map[_pose[mob].first + _move[mob].first][_pose[mob].second] != '9')
        this->_pose[mob].first += _move[mob].first;
};

void arcade::Pacman::endGame()
{
    std::string score_s = std::to_string(this->score);
    std::string name;

    try {
        if (this->score > std::stoi(this->conf.getConfigData()["Pacman"])) {
            this->highestscore = score_s;
            conf.saveConfig("Pacman", score_s);

            // Save name
            conf.setConfigFile("config/game.conf");
            name = conf.getConfigData()["name"];
            conf.setConfigFile("config/highscores.conf");
            conf.saveConfig("PacmanName", name);
            highestname = name;
        }
    } catch (std::invalid_argument) {
        std::cout << "No config file found" << std::endl;
    }
    restart();
}

void arcade::Pacman::care_ghost(std::vector<std::string> _map)
{
    if (this->_mob[this->mobid] == MOVE && tick % 10 == 0) {
        this->_pose[this->mobid] = find_pose('9', _map);
        this->_pose[this->mobid].first -= 1;
        handlingEvent(whichInput(), this->mobid);
        this->_mob[this->mobid] = ALIVE;
    }
    if ((tick % 30 == 0 && tick != 0) && this->mobid <= ENEMY4 - 1) {
        this->mobid++;
        this->_mob[this->mobid] = MOVE;
    }
    for (int i = ENEMY1; i <= ENEMY4; i++) {
        if ((tick % 10 == 0 && this->_mob[i] == ALIVE) ||( _map[this->_pose[i].first + this->_move[i].first][this->_pose[i].second + this->_move[i].second] != '0' && this->_mob[i] != START)) {
            handlingEvent(whichInput(), i);
        }
        changePose(_map, i);
        if (this->win == 0|| this->getLoose(_map, i) == true)
            endGame();
        if (this->mod == 1)
            print_ghost(this->_pose[i], this->direction[i], 7);
        else
            print_ghost(this->_pose[i], this->direction[i], i + 2);
    }
    if (tick % 100 == 0)
        this->mod = 0;
    tick++;
};


void arcade::Pacman::handlingEvent(arcade::Input input, int mob)
{
    switch (_pose[mob].second) {
        case 24:
            _pose[mob].second = 0;
            return;
        case 0:
            _pose[mob].second = 24;
            return;
    }
    switch (input)
    {
    case arcade::Input::UNDEFINED:
        break;
    case arcade::Input::LEFT:
        if (_map[_pose[mob].first + 1][_pose[mob].second] != '1' && _map[_pose[mob].first][_pose[mob].second + 1] != '9') {
            setMove(std::make_pair(1, 0), mob);
            direction[mob] = UP;
        }
        break;
    case arcade::Input::RIGHT:
        if (_map[_pose[mob].first - 1][_pose[mob].second] != '1' && _map[_pose[mob].first - 1][_pose[mob].second] != '9') {
            setMove(std::make_pair(-1, 0), mob);
            direction[mob] = DOWN;
        }
        break;
    case arcade::Input::UP:
        if (_map[_pose[mob].first][_pose[mob].second - 1] != '1' && _map[_pose[mob].first][_pose[mob].second - 1] != '9') {
            setMove(std::make_pair(0, -1), mob);
            direction[mob] = RIGHT;
        }
        break;
    case arcade::Input::DOWN:
        if (_map[_pose[mob].first][_pose[mob].second + 1] != '1' && _map[_pose[mob].first][_pose[mob].second + 1] != '9') {
            setMove(std::make_pair(0, 1), mob);
            direction[mob] = LEFT;
        }
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

// ********************** LAUNCH GAME *******************

void arcade::Pacman::do_game()
{
    // timeout(200);
    // clear();
    this->changePose(_map, PACMAN);
    _map = this->print_pacman(this->getPose(PACMAN), _map);
    // print_other(_map, this->getScore());
    this->care_ghost(_map);
}

std::vector<std::shared_ptr<arcade::IObject>> arcade::Pacman::loop(arcade::Input input)
{
    handlingEvent(input, PACMAN);
    do_game();
    createObjet();
    return this->_object;
}

// ********************** BUILD IObject ****************

void arcade::Pacman::pushEnemy(int mob)
{
    auto a = createTile();
    a->setCharacter('O');
    a->setPosition(std::make_pair(this->_pose[mob].second, this->_pose[mob].first));
    a->setColor(arcade::Color::RED);
    a->setScale(std::make_pair(1, 1));
    a->setRotation(0);
    if (this->mod == 1) {
        a->setTexture(BLUEBOX);
        a->setColor(arcade::Color::BLUE);
    } else {
        a->setTexture(REDBOX);
        a->setColor(arcade::Color::RED);
    }    _object.push_back(a);
}

void arcade::Pacman::pushPacman()
{
    auto a = createTile();
    a->setCharacter('O');
    a->setPosition(std::make_pair(this->_pose[PACMAN].second, this->_pose[PACMAN].first));
    a->setScale(std::make_pair(1, 1));
    a->setRotation(0);
    a->setColor(arcade::Color::YELLOW);
    a->setTexture(YELLOWBOX);
    _object.push_back(a);
}

void arcade::Pacman::createObjet()
{
    this->_object.clear();

    createMap(this->_map);
    pushFood(_map);
    for (int i = ENEMY1; i <= ENEMY4; i++)
        pushEnemy(i);
    pushPacman();
    pushText();
}

void arcade::Pacman::pushFood(std::vector<std::string> _map)
{
    for (int i = 0; i <= 25 - 1; i++)
        for (int a = 0; a <= 25 - 1; a++) {
            if (_map[i][a] == '0')
                createFoodTile(createTile(), std::make_pair(i, a), LITTLEFOOD);
            else if (_map[i][a] == '2')
                createFoodTile(createTile(), std::make_pair(i, a), FOOD);
        }
}

void arcade::Pacman::createFoodTile(std::shared_ptr<arcade::ITile> tile, std::pair<std::size_t, std::size_t> position, std::string Texture)
{
    if (Texture == LITTLEFOOD) {
        tile->setCharacter('.');
    tile->setColor(arcade::Color::YELLOW);
    } else {
        tile->setCharacter('+');
        tile->setColor(arcade::Color::RED);
    }
    tile->setPosition(std::make_pair(position.second, position.first));
    tile->setScale(std::make_pair(1, 1));
    tile->setRotation(0);
    tile->setTexture(Texture);
    _object.push_back(tile);
}

void arcade::Pacman::createMap(std::vector<std::string> _map)
{
    for (int i = 0; i <= 25 - 1; i++)
        for (int a = 0; a <= 25 - 1; a++) {
            if (_map[i][a] == '1')
                setMapTile(createTile(), std::make_pair(i, a));
        }
}

arcade::Color arcade::Pacman::whichColor(std::vector<std::string> _map, std::pair<std::size_t, std::size_t> position)
{
    switch (_map[position.first][position.second]) {
    case '1':
        return BLUE;
    case '9':
        return WHITE;
    }
    return WHITE;
}

void arcade::Pacman::setMapTile(std::shared_ptr<arcade::ITile> tile, std::pair<std::size_t, std::size_t> position)
{
    tile->setCharacter(' ');
    tile->setPosition(std::make_pair(position.second, position.first));
    tile->setColor(whichColor(this->_map, position));
    tile->setScale(std::make_pair(1, 1));
    tile->setRotation(0);
    tile->setTexture(BLUEBOX);
    _object.push_back(tile);
}

void arcade::Pacman::pushText()
{
    setText(createText(), highestname, std::make_pair((this->map.first + 1), (map.second)));
    setText(createText(), highestscore, std::make_pair((this->map.first + 1), (map.second + 1)));
    setText(createText(), "Pacman", std::make_pair((this->map.first + 1), (map.second + 3)));
    setText(createText(), "Your Score:", std::make_pair((this->map.first + 1), (map.second + 4)));
    setText(createText(), std::to_string(this->score), std::make_pair(map.first + 1, map.second + 5));
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

arcade::Input arcade::Pacman::event(arcade::Input input)
{
    return arcade::Input::UNDEFINED;
}

// ******************* ENTRY POINT **********************

extern "C" arcade::Pacman *entryPoint() {
    return new (arcade::Pacman);
}
