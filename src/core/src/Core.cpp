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
    _graphLibPos--;
    if (_graphLibPos < 0) {
        _graphLibPos = _graphicsLib.size();
    }
    return _graphicsLib[_graphLibPos];
}

std::string arcade::Core::toNextGame()
{
    _gameLibPos++;
    if (_gameLibPos >= _gamesLib.size()) {
        _gameLibPos = 0;
    }
    return _gamesLib[_gameLibPos + 1];
}

std::string arcade::Core::toPreviousGame()
{
    _gameLibPos--;
    if (_gameLibPos < 0) {
        _gameLibPos = _gamesLib.size();
    }
    return _gamesLib[_gameLibPos];
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
        input = graph_lib->event(objs);
        if (input == arcade::Input::EXIT)
            break;
        switch (input) {
            case arcade::Input::NEXTGRAPH:
                graph_lib = swapLib(toNextGraph(), _graphicsDll);
                break;
            case arcade::Input::PREVIOUSGRAPH:
                graph_lib = swapLib(toPreviousGraph(), _graphicsDll);
                break;
            case arcade::Input::NEXTGAME:
                game_lib = swapLib(toNextGame(), _gameDll);
                break;
            case arcade::Input::PREVIOUSGAME:
                game_lib = swapLib(toPreviousGame(), _gameDll);
                break;
            case arcade::Input::PLAY_GAME:
                game_lib = swapLib(toNextGame(), _gameDll);
                break;
        }
        graph_lib->clear();
        objs = game_lib->loop(input);
        for (auto o : objs) {
            graph_lib->draw(o);
        }
        graph_lib->display();
        if (_gameLibPos != -1) {
            // std::this_thread::sleep_for (std::chrono::milliseconds(600));
        }
        // const auto start = std::chrono::high_resolution_clock::now();
        // const auto end = std::chrono::high_resolution_clock::now();
        // const std::chrono::duration<double, std::milli> elapsed = end - start;
        // std::cout << "Waited " << elapsed << '\n';

    }
    _gameDll.closeInstance();
}