/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Core
*/

// #include "core/Core.hpp"
// #include "core/DLLoader.hpp"
// #include "IGames.hpp"
#include "../../../include/core/Core.hpp"
#include <iostream>
#include "unistd.h"
#include <chrono>
#include <thread>

arcade::Core::Core()
{
        // _gameDll.setLib(_menuLib);
        _gameDll.setLib(_menuLib);
        // _graphicsDll =
}

arcade::Core::~Core()
{
}

void arcade::Core::setGraphicLib(std::string grapgicLib)
{
    _graphicsDll.setLib(grapgicLib);
    _graphLibPos = get_index_of_array(_graphicsLib, grapgicLib);
}

std::string arcade::Core::toNextGraph()
{
    _graphLibPos++;
    if (_graphLibPos >= _graphicsLib.size()) {
        _graphLibPos = 0;
    }
    return _graphicsLib[_graphLibPos];
}

std::string arcade::Core::toPreviousGraph()
{
    if (_graphLibPos == 0) {
        _graphLibPos = _graphicsLib.size() - 1;
    }
    else 
        _graphLibPos--;
    return _graphicsLib[_graphLibPos];
}

std::string arcade::Core::toNextGame()
{
    _gameLibPos++;
    if (_gameLibPos >= _gamesLib.size()) {
        _gameLibPos = 0;
    }
    return _gamesLib[_gameLibPos];
}

std::string arcade::Core::toPreviousGame()
{
    if (_gameLibPos == 0) {
        _gameLibPos = _gamesLib.size() - 1;
    }
    else
        _gameLibPos--;
    return _gamesLib[_gameLibPos];
}

void arcade::Core::changeGameSelection(arcade::Input game)
{
    switch (game) {
        case arcade::Input::PACMAN:
            _gameLibPos = 0;
            break;
        case arcade::Input::SNAKE:
            _gameLibPos = 1;
            break;
        default:
            break;
    }
}

int arcade::Core::handleEvents(arcade::Input input, IGraphics *&graph_lib, IGames*& game_lib)
{
    switch (input) {
        case arcade::Input::EXIT:
            return 1;
        case arcade::Input::NEXTGRAPH:
            graph_lib = swapLib(toNextGraph(), _graphicsDll);
            break;
        case arcade::Input::PREVIOUSGRAPH:
            graph_lib = swapLib(toPreviousGraph(), _graphicsDll);
            break;
        case arcade::Input::NEXTGAME:
            if (_isPlaying)
                game_lib = swapLib(toNextGame(), _gameDll);
            break;
        case arcade::Input::PREVIOUSGAME:
            if (_isPlaying)
                game_lib = swapLib(toPreviousGame(), _gameDll);
            break;
        case arcade::Input::MENU:
            if (_isPlaying) {
                _gameDll.closeInstance();
                _gameDll.setLib(_menuLib);
                _gameDll.loadInstance();
                game_lib = _gameDll.getInstance();
                _isPlaying = false;
                _gameLibPos = -1;
            }
            break;
        default:
            break;
    }
    return 0;
}

int arcade::Core::handleGamesEvents(arcade::Input input, IGraphics *&graph_lib, IGames*& game_lib)
{
    switch (input) {
        case arcade::Input::PLAY_GAME:
           game_lib = swapLib(_gamesLib[_gameLibPos], _gameDll);
           _isPlaying = true;
           break;
        case arcade::Input::PACMAN:
        case arcade::Input::SNAKE:
            changeGameSelection(input);
            break;
        case arcade::Input::EXIT:
           return 1;
        default:
            break;
    }
    return 0;
}

void arcade::Core::runCore()
{
    IGraphics *graph_lib;
    IGames* game_lib;
    arcade::Input input;
    std::vector<std::shared_ptr<arcade::IObject>> objs;

    _graphicsDll.loadInstance();
    _gameDll.loadInstance();
    graph_lib = _graphicsDll.getInstance();
    game_lib = _gameDll.getInstance();

    while (1) {
        // get the graphic's lib events
        input = graph_lib->event(objs);

        // Switch events
        if (handleEvents(input, graph_lib, game_lib) == 1)
            break;
        if (handleGamesEvents(game_lib->event(input), graph_lib, game_lib) == 1)
            break;
        graph_lib->clear();
        objs = game_lib->loop(input);
        for (auto o : objs) {
            graph_lib->draw(o);
        }
        graph_lib->display();
        if (_isPlaying) {
            std::this_thread::sleep_for (std::chrono::milliseconds(100));
        }

    }
    _gameDll.closeInstance();
}