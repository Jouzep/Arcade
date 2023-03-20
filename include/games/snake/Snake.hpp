/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "IGames.hpp"
#include "IObject.hpp"

namespace arcade
{
    class Snake : public IGames
    {
    public:
        Snake()
        {
            // init_all();
        }
        void init_all();
        std::vector<std::shared_ptr<arcade::IObject>> loop(arcade::Input input){
            // set_all();
            // return list;
        };
        void restart(){
            // init_all();
        };
        std::shared_ptr<arcade::ISound> createSound();
        std::shared_ptr<arcade::ITile> createTile();
        void create_objet(){
            //;
        };
        void create_snake(){
            //;
        };
        ~Snake();

    protected:
    private:
        std::vector<std::shared_ptr<arcade::IObject>> objects;
        arcade::Input input;
        std::vector<std::pair<std::size_t, std::size_t>> snake;
    };

    class snakeTile : public ITile
    {
    public:
        snakeTile()
        {
            setPosition({0, 0});
            setScale({0, 0});
            setCharacter(' ');
        };
        ~snakeTile(){};
        std::string getTexture()
        {
            return _texture;
        }
        std::pair<float, float> getPosition()
        {
            return _position;
        };
        char getCharacter()
        {
            return _char;
        };
        arcade::Color getColor()
        {
            return _color;
        };
        std::pair<float, float> getScale()
        {
            return _scale;
        };
        float getRotation()
        {
            return _rotation;
        };
        void setTexture(std::string path)
        {
            _texture = path;
        };
        void setPosition(std::pair<float, float> position)
        {
            this->_position.first = position.first;
            this->_position.second = position.second;
        };
        void setCharacter(char c)
        {
            this->_char = c;
        };
        void setColor(arcade::Color color)
        {
            this->_color = color;
        };
        void setScale(std::pair<float, float> position)
        {
            this->_scale.first = this->_scale.first;
            this->_scale.second = this->_scale.second;
        };
        void setRotation(float rotation)
        {
            this->_rotation = rotation;
        };

    private:
        std::pair<std::size_t, std::size_t> _position;
        char _char;
        std::string _texture;
        arcade::Color _color;
        std::pair<float, float> _scale;
        float _rotation;
    };
    class snakeText : public IText
    {
    public:
    private:
        std::vector<std::pair<std::size_t, std::size_t>> snake;
    };
    class snakeSound : public ISound
    {
    public:
    private:
        std::vector<std::pair<std::size_t, std::size_t>> snake;
    };
    // class snakeFood : public ITile
    // {
    // public:
    // private:
    //     std::vector<std::pair<std::size_t, std::size_t>> snake;
    // };
}
#endif /* !SNAKE_HPP_ */
