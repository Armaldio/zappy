//
//-----------------------------------------------------------------------------
//Filename:    TeamModel.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/28/17.
//-----------------------------------------------------------------------------
//

#include <iostream>
#include "TeamTableModel.hpp"

TeamTableModel::TeamTableModel(QObject *parent) : QAbstractTableModel(parent) {

}

Qt::ItemFlags TeamTableModel::flags(const QModelIndex &index) const {
    if (index.column() == TEAM)
    {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    }
    else if (index.column() == PLAYERS)
    {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    }

    return QAbstractTableModel::flags(index);
}

int TeamTableModel::rowCount(const QModelIndex &parent) const {
    return _team.count();
}

int TeamTableModel::columnCount(const QModelIndex &parent) const {
    return columnsCount;
}

QVariant TeamTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= _team.count())
    {
        return QVariant();
    }

    switch (role)
    {
        case Qt::DisplayRole:
        case Qt::EditRole:
            if (index.column() == TEAM)
            {
                return _team[index.row()]->teamName;
            }
            else if (index.column() == PLAYERS && _team[index.row()]->players.size())
            {
                return _team[index.row()]->players[0]->getId();
            }
            break;
    }

    return QVariant();
}

QVariant TeamTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch (section)
        {
            case TEAM:
                return trUtf8("Name");
                break;
            case PLAYERS:
                return trUtf8("Members");
                break;
        }
    }
    return QAbstractItemModel::headerData(section, orientation, role);
}

bool TeamTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (!index.isValid() || index.row() < 0 || index.row() >= _team.count())
    {
        return false;
    }

    return QAbstractItemModel::setData(index, value, role);
}

void TeamTableModel::addElements(const QVector<zappy::Team *> &teams) {
    beginResetModel();
    endResetModel();
    _team.clear();
    _team.append(teams);
}
