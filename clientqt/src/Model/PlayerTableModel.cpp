//
//-----------------------------------------------------------------------------
//Filename:    PlayerTableModel.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/28/17.
//-----------------------------------------------------------------------------
//

#include "PlayerTableModel.hpp"

PlayerTableModel::PlayerTableModel(QObject *parent) : QAbstractTableModel(parent) {

}

Qt::ItemFlags PlayerTableModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

int PlayerTableModel::rowCount(const QModelIndex &parent) const {
    return _players.count();
}

int PlayerTableModel::columnCount(const QModelIndex &parent) const {
    return columnsCount;
}

QVariant PlayerTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= _players.count())
    {
        return QVariant();
    }

    const zappy::Player * player = _players[index.row()];
    const zappy::Inventaire * inventaire = _players[index.row()]->getInventaire();

    switch (role)
    {
        case Qt::DisplayRole:
        case Qt::EditRole:
            const Columns type = (const Columns)index.column();
            switch (type) {
                case ID:
                    return QString::number(player->getId());
                    break;
                case X:
                    return QString::number(player->getPosition().x);
                    break;
                case Y:
                    return QString::number(player->getPosition().y);
                    break;
                case LEVEL:
                    return QString::number(player->getLevel());
                    break;
                case ACTION:
                    return QString("Unknown");
                    break;
                case TEAM:
                    return player->getTeam()->teamName;
                    break;
                case NOURRITURE:
                    return QString::number(inventaire->getNourriture());
                    break;
                case LINEMATE:
                    return QString::number(inventaire->getLinemate());
                    break;
                case DERAUMERE:
                    return QString::number(inventaire->getDeraumere());
                    break;
                case SIBUR:
                    return QString::number(inventaire->getSibur());
                    break;
                case MENDIANE:
                    return QString::number(inventaire->getMendiane());
                    break;
                case PHIRAS:
                    return QString::number(inventaire->getPhiras());
                    break;
                case THYSTAME:
                    return QString::number(inventaire->getThystame());
                    break;
            }
            break;
    }

    return QVariant();
}

QVariant PlayerTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch ((Columns)section)
        {
            case ID:
                return trUtf8("Id");
                break;
            case X:
                return trUtf8("X");
                break;
            case Y:
                return trUtf8("Y");
                break;
            case LEVEL:
                return trUtf8("Level");
                break;
            case ACTION:
                return trUtf8("Action");
                break;
            case TEAM:
                return trUtf8("Team");
                break;
            case NOURRITURE:
                return trUtf8("Nourriture");
                break;
            case LINEMATE:
                return trUtf8("Linemate");
                break;
            case DERAUMERE:
                return trUtf8("Deraumere");
                break;
            case SIBUR:
                return trUtf8("Sibur");
                break;
            case MENDIANE:
                return trUtf8("Mendiane");
                break;
            case PHIRAS:
                return trUtf8("Phiras");
                break;
            case THYSTAME:
                return trUtf8("Thystame");
                break;
        }
    }
    return QAbstractItemModel::headerData(section, orientation, role);
}

bool PlayerTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    return QAbstractItemModel::setData(index, value, role);
}

void PlayerTableModel::setElements(const QVector<zappy::Player *> &teams) {
    beginResetModel();
    endResetModel();
    _players.clear();
    _players.append(teams);
}
