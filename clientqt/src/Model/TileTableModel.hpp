//
//-----------------------------------------------------------------------------
//Filename:    TileTableModel.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/28/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_TILETABLEMODEL_HPP
#define CLIENTQT_TILETABLEMODEL_HPP

#include <QtCore/QAbstractTableModel>
#include <include/Game/Tile.hpp>

class TileTableModel : public QAbstractTableModel {
Q_OBJECT
public:
    enum Columns {
        X,
        Y,
        NOURRITURE,
        LINEMATE,
        DERAUMERE,
        SIBUR,
        MENDIANE,
        PHIRAS,
        THYSTAME
    };
    static const int columnsCount = 9;

    explicit TileTableModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

    void setElements(const QVector<zappy::Tile *> &teams);

private:
    QVector<zappy::Tile *> _tiles;
};


#endif //CLIENTQT_TILETABLEMODEL_HPP
