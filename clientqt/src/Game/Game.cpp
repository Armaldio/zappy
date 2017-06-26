//
//-----------------------------------------------------------------------------
//Filename:    Game.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/23/17.
//-----------------------------------------------------------------------------
//

#include <iostream>
#include <include/Network/Network.hpp>
#include <sstream>
#include <include/Game/GameExeception.hpp>
#include "Game.hpp"

zappy::Game::Game() : _heigth(0), _width(0), _isMapped(false), _serverTime(100), _isFail(false) {
    _functions.insert(std::make_pair("msz", std::bind(&zappy::Game::function_msz, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("tna", std::bind(&zappy::Game::function_tna, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("pnw", std::bind(&zappy::Game::function_pnw, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("ppo", std::bind(&zappy::Game::function_ppo, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("plv", std::bind(&zappy::Game::function_plv, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("pin", std::bind(&zappy::Game::function_pin, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("pex", std::bind(&zappy::Game::function_pex, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("pbc", std::bind(&zappy::Game::function_pbc, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("pic", std::bind(&zappy::Game::function_pic, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("pie", std::bind(&zappy::Game::function_pie, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("pfk", std::bind(&zappy::Game::function_pfk, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("pdr", std::bind(&zappy::Game::function_pdr, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("pgt", std::bind(&zappy::Game::function_pgt, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("pdi", std::bind(&zappy::Game::function_pdi, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("bct", std::bind(&zappy::Game::function_bct, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("enw", std::bind(&zappy::Game::function_enw, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("eht", std::bind(&zappy::Game::function_eht, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("ebo", std::bind(&zappy::Game::function_ebo, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("sgt", std::bind(&zappy::Game::function_sgt, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("seg", std::bind(&zappy::Game::function_seg, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("smg", std::bind(&zappy::Game::function_smg, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("suc", std::bind(&zappy::Game::function_suc, this, std::placeholders::_1)));
    _functions.insert(std::make_pair("sbp", std::bind(&zappy::Game::function_sbp, this, std::placeholders::_1)));
}

zappy::Game::~Game() {
    destroyMap();
}

void zappy::Game::addPlayer(zappy::Player *player) {
    _players.push_back(player);
}

void zappy::Game::createMap(unsigned int width, unsigned int height) {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            _tiles.push_back(new Tile((unsigned int) i, (unsigned int) j));
        }
    }
    _heigth = height;
    _width = width;
    _isMapped = true;
}

void zappy::Game::destroyMap() {
    for (auto tile : _tiles)
        delete(tile);
    for (auto player : _players)
        delete(player);
    _teams.clear();
    _players.clear();
    _tiles.clear();
    _heigth = 0;
    _width = 0;
    _isMapped = false;
}

std::vector<zappy::Player *> &zappy::Game::getPlayers() {
    return _players;
}
std::vector<zappy::Tile *> &zappy::Game::getTiles() {
    return _tiles;
}

void zappy::Game::function_msz(const std::string &buffer) {
    std::stringstream ss;

    ss << buffer;

    int width;
    int height;

    ss >> width;
    if (ss.fail())
        throw GameException("function_msz invalid argument: width");
    ss >> height;
    if (ss.fail())
        throw GameException("function_msz invalid argument: height");
    createMap(width, height);
    _isMapped = true;
}

void zappy::Game::function_bct(const std::string &buffer) {
    std::stringstream ss;

    ss << buffer;

    int x;
    int y;

    ss >> x;
    if (ss.fail() || x >= _width || x < 0)
        throw GameException("function_bct invalid x");
    ss >> y;
    if (ss.fail() || y >= _heigth || y < 0)
        throw GameException("function_bct invalid y");
    int quantity;
    const int position = _width * y + x;

    if (position >= _heigth * _width)
        throw GameException("function_bct invalid x = " + std::to_string(x)
                            + " y = " + std::to_string(y)
                            + " position = " + std::to_string(position)
                            + " max_id = " + std::to_string(_heigth * _width));

    auto *inventaire = _tiles[position]->getInventaire();
    for (int i = 0; i < 7; ++i) {
        ss >> quantity;
        if (ss.fail() || quantity < 0)
            throw GameException("function_bct invalid quantity " + std::to_string(quantity) + " at id: " + std::to_string(i));
        inventaire->setMaterial((const Inventaire::TypeMaterial) i, quantity);
    }
}

void zappy::Game::function_tna(const std::string &name) {
    _teams.push_back({QString(name.c_str())});
}

void zappy::Game::function_pnw(const std::string &) {
    std::cout << "called::function_pnw" << std::endl;
}

void zappy::Game::function_ppo(const std::string &) {
    std::cout << "called::function_ppo" << std::endl;
}

void zappy::Game::function_plv(const std::string &) {
    std::cout << "called::function_plv" << std::endl;
}

void zappy::Game::function_pin(const std::string &) {
    std::cout << "called::function_pin" << std::endl;
}

void zappy::Game::function_pex(const std::string &) {
    std::cout << "called::function_pex" << std::endl;
}

void zappy::Game::function_pbc(const std::string &) {
    std::cout << "called::function_pbc" << std::endl;
}

void zappy::Game::function_pic(const std::string &) {
    std::cout << "called::function_pic" << std::endl;
}

void zappy::Game::function_pie(const std::string &) {
    std::cout << "called::function_pie" << std::endl;
}

void zappy::Game::function_pfk(const std::string &) {
    std::cout << "called::function_pfk" << std::endl;
}

void zappy::Game::function_pdr(const std::string &) {
    std::cout << "called::function_pdr" << std::endl;
}

void zappy::Game::function_pgt(const std::string &) {
    std::cout << "called::function_pgt" << std::endl;
}

void zappy::Game::function_pdi(const std::string &) {
    std::cout << "called::function_pdi" << std::endl;
}

void zappy::Game::function_enw(const std::string &) {
    std::cout << "called::function_enw" << std::endl;
}

void zappy::Game::function_eht(const std::string &) {
    std::cout << "called::function_eht" << std::endl;
}

void zappy::Game::function_ebo(const std::string &) {
    std::cout << "called::function_ebo" << std::endl;
}

void zappy::Game::function_sgt(const std::string &buffer) {
    std::stringstream ss;

    ss << buffer;

    ss >> _serverTime;

    if (ss.fail() || _serverTime < 0)
        throw GameException("sgt error: " + buffer);
}

void zappy::Game::function_seg(const std::string &) {
    std::cout << "called::function_seg" << std::endl;
}

void zappy::Game::function_smg(const std::string &) {
    std::cout << "called::function_smg" << std::endl;
}

void zappy::Game::function_suc(const std::string &) {
    std::cout << "called::function_suc" << std::endl;
}

void zappy::Game::function_sbp(const std::string &) {
    std::cout << "called::function_sbp" << std::endl;
}

bool zappy::Game::fexecute(const std::string &command) {
    if (command.size() < 3)
        return false;
    if (command == "WELCOME") {
        destroyMap();
        function_welcome(command);
        return true;
    }

    std::string native;
    native.push_back(command[0]);
    native.push_back(command[1]);
    native.push_back(command[2]);
    if (_functions.find(native) != _functions.end()) {
        _functions[native](command.substr(4));
        return true;
    }
    return false;
}

void zappy::Game::function_welcome(const std::string &) {
    zappy::Network::get_instance_ptr()->send("GRAPHIC\n");
}

bool zappy::Game::isMapped() const {
    return _isMapped;
}

bool zappy::Game::isFail() const {
    return _isFail;
}

const QVector<zappy::Team> &zappy::Game::getTeams() const {
    return _teams;
}

