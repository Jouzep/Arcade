/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Nibbler
*/

#include "games/nibbler/Nibbler.hpp"
#include "unistd.h"

// ***************** CONSTRUCTOR ****************

std::pair<int, int> find_pose(char index, std::vector<std::string> _map)
{
    for (int i = 0; i < 19; i++) {
        for (int a = 0; a < 19 ; a++) {
            if (_map[i][a] == index)
                return std::make_pair(i, a);
        }
    }
    return std::make_pair(0, 0);
}

int countFood(std::vector<std::string> _map)
{
    int res = 0;

    for (int i = 0; i < 19; i++) {
        for (int a = 0; a < 19 ; a++) {
            if (_map[i][a] == '2')
                res++;
        }
    }
    return res;
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

arcade::Nibbler::Nibbler()
{
    try {
        conf.setConfigFile("config/highscores.conf");
    } catch (ConfHandler::ConfHandlerError) {
        highestscore = "NONE";
    }
    this->highestscore = conf.getConfigData()["Nibbler"];
    this->highestname = conf.getConfigData()["NibblerName"];
    this->map = std::make_pair(19, 19);
    restart();
}

arcade::Nibbler::~Nibbler()
{
}

void arcade::Nibbler::endGame()
{
    std::string score_s = std::to_string(this->score);
    std::string name;
    try {
        if (this->score > std::stoi(this->conf.getConfigData()["Nibbler"])) {
            this->highestscore = score_s;
            conf.saveConfig("Nibbler", score_s);

            // Save name
            conf.setConfigFile("config/game.conf");
            name = conf.getConfigData()["name"];
            conf.setConfigFile("config/highscores.conf");
            conf.saveConfig("NibblerName", name);
            highestname = name;
        }
    } catch (std::invalid_argument) {
        std::cout << "No config file found" << std::endl;
    }
    restart();
}

void arcade::Nibbler::restart()
{
    this->_map = get_file_content("assets/map/mapNibbler.txt");
    this->_snake = std::make_unique<SnakeBody>(this->map ,std::make_pair(17, 9));
    this->score = 0;
    this->foodleft = countFood(this->_map);
    _object.clear();
}

// ******************* GAME LOGIC ********************

bool arcade::Nibbler::snakeCollision()
{
    auto head_position = this->_snake->getSnakeBody()[0]; // get head position
    auto body_positions = this->_snake->getSnakeBody();   // get snake body

    for (std::size_t i = 1; i != body_positions.size(); i++) // check if snake touch his body
    {
        auto tmp = body_positions[i];
        if (head_position == tmp)
            return true;
    }
    return false;
}

void arcade::Nibbler::changeDirection()
{
    std::pair<std::size_t, std::size_t> head = this->_snake.get()->getSnakeBody()[0];
    auto up = this->_map[head.first - 1][head.second];
    auto down = this->_map[head.first + 1][head.second];
    auto right = this->_map[head.first][head.second - 1];
    auto left = this->_map[head.first][head.second + 1];

    if (up != '1' && this->_snake->getMove().first != 1) {
        this->_snake->setMove(std::make_pair(-1, 0));
        return;
    }
    if (down != '1' && this->_snake->getMove().first != -1) {
        this->_snake->setMove(std::make_pair(1, 0));
        return;
    }
    if (right != '1' && this->_snake->getMove().second != 1) {
        this->_snake->setMove(std::make_pair(0, -1));
        return;
    }
    if (left != '1' && this->_snake->getMove().second != -1) {
        this->_snake->setMove(std::make_pair(0, 1));
        return;
    }
}

void arcade::Nibbler::snakeDeplacement(std::pair<std::size_t, std::size_t> head)
{
    auto move = this->_snake.get()->getMove();
    auto character = this->_map[head.first + move.first][head.second + move.second];

    if (character == '1')
        changeDirection();
    this->_map = this->_snake.get()->moveSnakeBody(_map);
}

void arcade::Nibbler::handlingEvent(arcade::Input input)
{
    std::pair<int, int> head = this->_snake.get()->getSnakeBody()[0];

    switch (input)
    {
    case arcade::Input::UNDEFINED:
        break;
    case arcade::Input::LEFT:
        if (this->_snake->getMove().second != -1 && this->_map[head.first][head.second + 1] != '1')
            this->_snake->setMove(std::make_pair(0, 1));
        break;
    case arcade::Input::RIGHT:
        if (this->_snake->getMove().second != 1 && this->_map[head.first][head.second - 1] != '1')
            this->_snake->setMove(std::make_pair(0, -1));
        break;
    case arcade::Input::UP:
        if (this->_snake->getMove().first != 1 && this->_map[head.first - 1][head.second] != '1')
            this->_snake->setMove(std::make_pair(-1, 0));
        break;
    case arcade::Input::DOWN:
        if (this->_snake->getMove().first != -1 && this->_map[head.first + 1][head.second] != '1')
            this->_snake->setMove(std::make_pair(1, 0));
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

void arcade::Nibbler::do_game()
{
    auto countfood = countFood(this->_map);
    std::pair<std::size_t, std::size_t> head = this->_snake.get()->getSnakeBody()[0];

    snakeDeplacement(head);
    if (countfood != foodleft) {
        this->score += 10;
        foodleft--;
    }
    if (countFood(this->_map) == 0 || snakeCollision() == true)
        endGame();
}

std::vector<std::shared_ptr<arcade::IObject>> arcade::Nibbler::loop(arcade::Input input)
{
    handlingEvent(input);
    do_game();
    createObjet();
    return this->_object;
}

// ********************** BUILD IObject ****************

void arcade::Nibbler::createObjet()
{
    this->_object.clear();

    createMap(this->_map);
    pushSnake();
    pushText();
}

void arcade::Nibbler::pushSnake()
{
    auto body = _snake->getSnakeBody();
    for (std::size_t i = 0; i != body.size(); i++)
    {
        auto a = createTile();
        a->setCharacter('*');
        a->setPosition(body[i]);
        a->setColor(arcade::Color::GREEN);
        a->setScale(std::make_pair(1, 1));
        a->setRotation(0);
        if (i == 0)
        {
            a->setCharacter('X');
            a->setColor(arcade::Color::BLUE);
        }
        _object.push_back(a);
    }
}

void arcade::Nibbler::createMap(std::vector<std::string> _map)
{
    for (int i = 0; i <= 19 - 1; i++)
        for (int a = 0; a <= 19 - 1; a++) {
            if (_map[i][a] == '1')
                setMapTile(createTile(), std::make_pair(a, i), "wall");
            else if (_map[i][a] == '2')
                setMapTile(createTile(), std::make_pair(a, i), "food");
        }
}

void arcade::Nibbler::setMapTile(std::shared_ptr<arcade::ITile> tile, std::pair<std::size_t, std::size_t> position, std::string text)
{
    if (text == "food") {
        tile->setCharacter('+');
        tile->setTexture(LITTLEFOOD);
        tile->setColor(YELLOW);
    } else {
        tile->setCharacter(' ');
        tile->setTexture(BLUEBOX);
        tile->setColor(BLUE);
    }
    tile->setPosition(std::make_pair(position.second, position.first));
    tile->setScale(std::make_pair(1, 1));
    tile->setRotation(0);
    _object.push_back(tile);
}

void arcade::Nibbler::pushText()
{
    setText(createText(), highestname, std::make_pair((map.first + 1), (map.second / 2)));
    setText(createText(), highestscore, std::make_pair((map.first + 1), (map.second / 2 + 1)));
    setText(createText(), "Nibbler", std::make_pair((this->map.first + 1), (map.second + 1)));
    setText(createText(), "Your Score:", std::make_pair((this->map.first + 1), (map.second + 2)));
    setText(createText(), std::to_string(this->score), std::make_pair(map.first + 1, map.second + 3));
}


void arcade::Nibbler::setText(std::shared_ptr<arcade::IText> text, std::string content, std::pair<std::size_t, std::size_t> position)
{
    text->setColorText(arcade::Color::WHITE);
    text->setPosition(position);
    text->setText(content);
    this->_object.push_back(text);
}

void arcade::Nibbler::pushSound()
{
    setSound(createSound(), "path", 1);
}
void arcade::Nibbler::setSound(std::shared_ptr<arcade::ISound> sound, std::string soundPath, float volume)
{
    sound->setSoundPath(soundPath);
    sound->setVolume(volume);
    this->_object.push_back(sound);
}

std::shared_ptr<arcade::ISound> arcade::Nibbler::createSound()
{
    return std::make_shared<arcade::Music>();
}

std::shared_ptr<arcade::ITile> arcade::Nibbler::createTile()
{
    return std::make_shared<arcade::Tile>();
}

std::shared_ptr<arcade::IText> arcade::Nibbler::createText()
{
    return std::make_shared<arcade::Text>();
}

arcade::Input arcade::Nibbler::event(arcade::Input input)
{
    return arcade::Input::UNDEFINED;
}

// ******************* ENTRY POINT **********************

extern "C" arcade::Nibbler *entryPoint() {
    return new (arcade::Nibbler);
}
