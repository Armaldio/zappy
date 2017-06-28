//
//-----------------------------------------------------------------------------
//Filename:    TileTableModel.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/28/17.
//-----------------------------------------------------------------------------
//

#include "include/Model/TileTableModel.hpp"

TileTableModel::TileTableModel(QObject *parent) : QAbstractTableModel(parent) {

}

Qt::ItemFlags TileTableModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

int TileTableModel::rowCount(const QModelIndex &parent) const {
    return _tiles.count();
}

int TileTableModel::columnCount(const QModelIndex &parent) const {
    return columnsCount;
}

QVariant TileTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= _tiles.count())
    {
        return QVariant();
    }

    const zappy::Tile * tile = _tiles[index.row()];
    const zappy::Inventaire * inventaire = _tiles[index.row()]->getInventaire();

    switch (role)
    {
        case Qt::DisplayRole:
        case Qt::EditRole:
            const Columns type = (const Columns)index.column();
            switch (type) {
                case X:
                    return QString::number(tile->getPosition().x);
                    break;
                case Y:
                    return QString::number(tile->getPosition().y);
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

QVariant TileTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch ((Columns)section)
        {
            case X:
                return trUtf8("X");
                break;
            case Y:
                return trUtf8("Y");
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

bool TileTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    return QAbstractItemModel::setData(index, value, role);
}

void TileTableModel::setElements(const QVector<zappy::Tile *> &elements) {
    beginResetModel();
    endResetModel();
    _tiles.clear();
    _tiles.append(elements);
}
