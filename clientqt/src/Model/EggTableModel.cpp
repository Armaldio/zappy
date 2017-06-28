//
//-----------------------------------------------------------------------------
//Filename:    EggTableModel.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/28/17.
//-----------------------------------------------------------------------------
//

#include <include/Game/Player.hpp>
#include "include/Model/EggTableModel.hpp"

EggTableModel::EggTableModel(QObject *parent) : QAbstractTableModel(parent) {

}

Qt::ItemFlags EggTableModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

int EggTableModel::rowCount(const QModelIndex &parent) const {
    return _eggs.count();
}

int EggTableModel::columnCount(const QModelIndex &parent) const {
    return columnsCount;
}

QVariant EggTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= _eggs.count())
    {
        return QVariant();
    }

    const zappy::Egg * egg = _eggs[index.row()];
    const zappy::Player * player = _eggs[index.row()]->getPlayer();
    const zappy::Team * team = player->getTeam();

    switch (role)
    {
        case Qt::DisplayRole:
        case Qt::EditRole:
            const Columns type = (const Columns)index.column();
            switch (type) {
                case ID:
                    return QString::number(egg->getId());
                    break;
                case ID_PLAYER:
                    return QString::number(player->getId());
                    break;
                case PLAYER_LINKED:
                    return egg->isLinked() ? QString("TRUE") : QString("FALSE");
                    break;
                case TEAM:
                    return team->teamName;
                    break;
                case X:
                    return QString::number(egg->getPosition().x);
                    break;
                case Y:
                    return QString::number(egg->getPosition().y);
                    break;
            }
            break;
    }

    return QVariant();
}

QVariant EggTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch ((Columns)section)
        {
            case ID:
                return trUtf8("ID");
                break;
            case ID_PLAYER:
                return trUtf8("PLAYER_ID");
                break;
            case PLAYER_LINKED:
                return trUtf8("LINKED");
                break;
            case TEAM:
                return trUtf8("TEAM");
                break;
            case X:
                return trUtf8("X");
                break;
            case Y:
                return trUtf8("Y");
                break;
        }
    }
    return QAbstractItemModel::headerData(section, orientation, role);
}

bool EggTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    return QAbstractItemModel::setData(index, value, role);
}

void EggTableModel::setElements(const QVector<zappy::Egg *> &elements) {
    beginResetModel();
    endResetModel();
    _eggs.clear();
    _eggs.append(elements);
}
