/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Nibbler
*/

#include "games/nibbler/Nibbler.hpp"

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
    this->map = std::make_pair(19, 19);
    restart();
}

arcade::Nibbler::~Nibbler()
{
}

void arcade::Nibbler::restart()
{
    int index = 'a';
    this->_snake = std::make_unique<SnakeBody>(this->map ,std::make_pair(9, 17));

    this->_map = get_file_content("assets/map/mapNibbler.txt");
    for (int i = 0; i != 27; i++)
       this->food.push_back(find_pose(index, this->_map));
    this->score = 0;
    _object.clear();
}

// ******************* GAME LOGIC ********************

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
        if (this->_snake->getMove().second != 1 && this->_map[head.first][head.second + 1] != '1')
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
    // this->_snake->setMove(this->_move);
}
// ********************** LAUNCH GAME *******************

void arcade::Nibbler::do_game()
{
}

std::vector<std::shared_ptr<arcade::IObject>> arcade::Nibbler::loop(arcade::Input input)
{
    handlingEvent(input);
    // do_game();
    createObjet();
    return this->_object;
}

// ********************** BUILD IObject ****************

void arcade::Nibbler::createObjet()
{
    this->_object.clear();

    createMap(this->_map);
    pushFood(this->_map);
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
        // a->setTexture("null");
        if (i == 0)
        {
            // a->setTexture("null");
            a->setCharacter('X');
            a->setColor(arcade::Color::BLUE);
        }
        _object.push_back(a);
    }
}

void arcade::Nibbler::pushFood(std::vector<std::string> _map)
{
    int index = 0;

    for (int i = 0; i <= 19 - 1; i++)
        for (int a = 0; a <= 19 - 1; a++) {
            if (_map[i][a] == 'a' + index) {
                createFoodTile(createTile(), std::make_pair(i, a), FOOD);
                index++;
            }
        }
}

void arcade::Nibbler::createFoodTile(std::shared_ptr<arcade::ITile> tile, std::pair<std::size_t, std::size_t> position, std::string Texture)
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

void arcade::Nibbler::createMap(std::vector<std::string> _map)
{
    for (int i = 0; i <= 19 - 1; i++)
        for (int a = 0; a <= 19 - 1; a++) {
            if (_map[i][a] == '1')
                setMapTile(createTile(), std::make_pair(i, a));
        }
}

arcade::Color arcade::Nibbler::whichColor(std::vector<std::string> _map, std::pair<std::size_t, std::size_t> position)
{
    switch (_map[position.first][position.second]) {
    case '1':
        return BLUE;
    case '9':
        return WHITE;
    }
    return WHITE;
}

void arcade::Nibbler::setMapTile(std::shared_ptr<arcade::ITile> tile, std::pair<std::size_t, std::size_t> position)
{
    tile->setCharacter(' ');
    tile->setPosition(std::make_pair(position.second, position.first));
    tile->setColor(whichColor(this->_map, position));
    tile->setScale(std::make_pair(1, 1));
    tile->setRotation(0);
    tile->setTexture(BLUEBOX);
    _object.push_back(tile);
}

void arcade::Nibbler::pushText()
{
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
