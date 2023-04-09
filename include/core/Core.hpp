/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-joseph.yu
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_
    #include "IGraphics.hpp"
    #include "DLLoader.hpp"
    #include "IGames.hpp"
    #include <array>
    #include "core/Error.hpp"

namespace arcade {
    class Core {
        public:
            Core();
            ~Core();

            void setGraphicLib(std::string grapgicLib);
            template <typename T>
            T* swapLib(std::string newLib, DLLoader<T> &currentLib) {
                currentLib.closeInstance();
                currentLib.setLib(newLib);
                currentLib.loadInstance();
                return currentLib.getInstance();
            }
            template<typename T, size_t size>
            int get_index_of_array(std::array<T, size> arr, T value) {
                size_t count = 0;
                for (size_t i = 0; i < arr.size(); i++) {
                    if (arr[i] == value)
                        break;
                    count++;
                }
                if (count >= arr.size())
                    return -1;
                return count;
            }
            std::string toNextGraph();
            std::string toPreviousGraph();
            std::string toNextGame();
            std::string toPreviousGame();
            void changeGameSelection(arcade::Input game);
            int handleEvents(arcade::Input input, IGraphics *&graph_lib, IGames*& game_lib);
            int handleGamesEvents(arcade::Input input, IGraphics *&graph_lib, IGames*& game_lib);
            void runCore();

        protected:
        private:
            DLLoader<arcade::IGames> _gameDll;
            DLLoader<arcade::IGraphics> _graphicsDll;
            std::array<std::string, 3> _graphicsLib = {"lib/arcade_sdl2.so", "lib/arcade_sfml.so", "lib/arcade_ncurses.so"};
            // std::array<std::string, 1> _graphicsLib = {"lib/arcade_sfml.so"};
            long unsigned int _graphLibPos;
            std::string _menuLib = "lib/arcade_menu.so";
            std::array<std::string, 4> _gamesLib = {"lib/arcade_pacman.so", "lib/arcade_snake.so", "lib/arcade_nibbler.so", "lib/arcade_solarfox.so"};
            int  _gameLibPos = -1;
            bool _isPlaying = false;
    };
}

#endif /* !CORE_HPP_ */
