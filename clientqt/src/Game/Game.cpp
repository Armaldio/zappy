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
#include "include/Game/Game.hpp"

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

void zappy::Game::createMap(unsigned int width, unsigned int height) {
    const unsigned int total = width * height;
    _heigth = height;
    _width = width;

    for (unsigned int i = 0; i < total; ++i) {
        _vTiles.push_back(new Tile(i % _width, i / width));
    }
    _isMapped = true;
}

void zappy::Game::destroyMap() {
    for (auto tile : _vTiles)
        delete(tile);
    for (auto player : _players)
        delete(player);
    for (auto egg : _vEggs)
        delete (egg);
    for (auto team : _vTeams)
        delete (team);
    _vTeams.clear();
    _vEggs.clear();
    _vPlayers.clear();
    _vTiles.clear();
    _players.clear();
    _eggs.clear();
    _teams.clear();
    _heigth = 0;
    _width = 0;
    _isMapped = false;
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

/**
 * "bct X Y q q q q q q q\n"
 * @param buffer
 */
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

    auto block = _vTiles[position];
    // _vTiles[position]->setPosition({x, y});
    block->setBusy(false);

    auto inventaire = _vTiles[position]->getInventaire();
    for (int i = 0; i < 7; ++i) {
        ss >> quantity;
        if (ss.fail() || quantity < 0)
            throw GameException("function_bct invalid quantity " + std::to_string(quantity) + " at id: " + std::to_string(i));
        inventaire->setMaterial((const Inventaire::TypeMaterial) i, quantity);
    }
}

void zappy::Game::function_tna(const std::string &name) {
    Team *team = new Team();
    team->teamName = name.c_str();
    _vTeams.push_back(team);
    _teams[name] = team;
}

/**
 * "pnw #n X Y O L N\n"
 * @param buffer
 */
void zappy::Game::function_pnw(const std::string &buffer) {
    std::stringstream ss;

    ss << buffer;

    unsigned int player_id;
    int x;
    int y;
    int orientation;
    int level;
    std::string teamName;

    ss >> player_id >> x >> y >> orientation >> level >> teamName;

    orientation--;

    Player *player = new Player(player_id, level, orientation % 4, x, y);
    Team *team = _teams[teamName];

    // add new player
    _vPlayers.push_back(player);
    _players[player_id] = player;

    // add in the team
    team->players.push_back(player);
    player->setTeam(team);
}

/**
 * "ppo #n X Y O\n"
 * @param buffer
 */
void zappy::Game::function_ppo(const std::string &buffer) {
    std::stringstream ss;

    ss << buffer;

    unsigned int player_id;

    ss >> player_id;

    int x;
    int y;
    int orientation;

    ss >> x >> y >> orientation;
    orientation--;

    if (ss.fail())
        throw GameException("ppo error");
    auto *player = _players[player_id];

    const auto positionStart = player->getPosition();
    auto *blockStart = _vTiles[_width * positionStart.y + positionStart.x];
    blockStart->setHightlight(false);

    player->setPosition({(float) x, (float) y});
    player->setOrientation(orientation % 4);

    const auto position = player->getPosition();
    auto *block = _vTiles[_width * position.y + position.x];

    block->setHightlight(true);

    player->setCollecting(false);
}

/**
 * "plv #n L\n"
 * @param buffer
 */
void zappy::Game::function_plv(const std::string &buffer) {
    std::stringstream ss;

    ss << buffer;

    unsigned int player_id;

    ss >> player_id;

    int level;

    ss >> level;

    if (ss.fail())
        throw GameException("plv error");

    auto *player = _players[player_id];
    player->setLevel(level);
}

/**
 * "pin #n X Y q q q q q q q\n"
 * @param buffer
 */
void zappy::Game::function_pin(const std::string &buffer) {
    std::stringstream ss;

    ss << buffer;

    unsigned int player_id;

    ss >> player_id;

    if (_players.find(player_id) == _players.end())
        throw GameException("Player not found");

    int x;
    int y;

    ss >> x >> y;

    auto *player = _players[player_id];
    auto *inventaire = _players[player_id]->getInventaire();
    // player->setPosition({(float) x, (float) y});

    int quantity;
    for (int i = 0; i < 7; ++i) {
        ss >> quantity;
        if (ss.fail() || quantity < 0)
            throw GameException("function_bct invalid quantity " + std::to_string(quantity) + " at id: " + std::to_string(i));
        inventaire->setMaterial((const Inventaire::TypeMaterial) i, quantity);
    }
}

void zappy::Game::function_pex(const std::string &buffer) {
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

void zappy::Game::function_pdr(const std::string &buffer) {
    std::stringstream ss;

    ss << buffer;

    unsigned int player_id;

    ss >> player_id;

    if (ss.fail()) throw GameException("pdr error");
    if (_players.find(player_id) == _players.end()) throw GameException("pdr error invalid player_id");
    _players[player_id]->setCollecting(true);
}

void zappy::Game::function_pgt(const std::string &buffer) {
   std::stringstream ss;

    ss << buffer;

    unsigned int player_id;

    ss >> player_id;


    auto *player = _players[player_id];

    const auto position = player->getPosition();
    auto *block = _vTiles[_width * position.y + position.x];

    player->setCollecting(true);

    block->setBusy(true);
}

void zappy::Game::function_pdi(const std::string &buffer) {
    std::stringstream ss;

    ss << buffer;

    unsigned int player_id;

    ss >> player_id;

    if (ss.fail())
        throw GameException("Pex error id: " + std::to_string(player_id));

    Player *player = _players[player_id];
    Team *team = player->getTeam();

    team->players.removeOne(player);
    _vPlayers.removeOne(player);
    _players.remove(player_id);
    delete(player);
}

/**
 * L’œuf a été pondu sur la case par le joueur.
 * "enw #e #n X Y\n"
 * @param buffer
 */
void zappy::Game::function_enw(const std::string &buffer) {
    std::stringstream ss;

    ss << buffer;

    unsigned int egg_id;
    unsigned int player_id;

    int x;
    int y;

    ss >> egg_id >> player_id >> x >> y;

    if (ss.fail()) throw GameException("Enw error parsing");

    Player *player = _players[player_id];

    Egg *egg = new Egg(egg_id, player, x, y);
    _vEggs.push_back(egg);
    _eggs[egg_id] = egg;
}

/**
 * L’œuf éclot.
 * "eht #e\n"
 * @param buffer
 */
void zappy::Game::function_eht(const std::string &buffer) {
    std::stringstream ss;

    ss << buffer;

    unsigned int egg_id;

    ss >> egg_id;

    if (ss.fail()) throw GameException("Eht error parsing");

    if (_eggs.find(egg_id) == _eggs.end()) throw GameException("Eht error egg_id");

    Egg *egg = _eggs[egg_id];
    _eggs.remove(egg_id);
    _vEggs.removeOne(egg);
    delete(egg);

    std::cout << "called::function_eht" << std::endl;
}

/**
 * Un joueur s’est connecté pour l’œuf.
 * "ebo #e\n"
 * @param buffer
 */
void zappy::Game::function_ebo(const std::string &buffer) {
    std::stringstream ss;

    ss << buffer;

    unsigned int egg_id;

    ss >> egg_id;

    if (ss.fail()) throw GameException("Ebo error parsing");
    if (_eggs.find(egg_id) == _eggs.end()) throw GameException("Ebo error egg_id: " + std::to_string(egg_id));

    _eggs[egg_id]->setLinked(true);
}

void zappy::Game::function_sgt(const std::string &buffer) {
    std::stringstream ss;

    ss << buffer;

    ss >> _serverTime;

    if (ss.fail() || _serverTime < 0)
        throw GameException("sgt error: " + buffer);
}

/**
 * Fin du jeu. L’équipe donnée remporte la partie.
 * "seg N\n"
 * @param buffer
 */
void zappy::Game::function_seg(const std::string &buffer) {
    std::cout << "called::function_seg" << std::endl;
}

/**
 * Message du serveur.
 * "smg M\n"
 * @param buffer
 */
void zappy::Game::function_smg(const std::string &buffer) {
    _vMessages << buffer.c_str();
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
        if (command.size() > 3)
            _functions[native](command.substr(4));
        else
            _functions[native](command);
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

QVector<zappy::Team *> &zappy::Game::getTeams() {
    return _vTeams;
}

QVector<zappy::Player *> &zappy::Game::getPlayers() {
    return _vPlayers;
}

QVector<zappy::Egg *> &zappy::Game::getEggs() {
    return _vEggs;
}

QVector<zappy::Tile *> &zappy::Game::getTiles() {
    return _vTiles;
}

QStringList &zappy::Game::getMessages() {
    return _vMessages;
}
