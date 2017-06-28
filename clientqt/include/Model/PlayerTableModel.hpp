//
//-----------------------------------------------------------------------------
//Filename:    PlayerTableModel.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/28/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_PLAYERTABLEMODEL_HPP
#define CLIENTQT_PLAYERTABLEMODEL_HPP

#include <QtCore/QAbstractTableModel>
#include <include/Game/Player.hpp>

class PlayerTableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    enum Columns {
        ID,
        X,
        Y,
        LEVEL,
        ACTION,
        TEAM,
        NOURRITURE,
        LINEMATE,
        DERAUMERE,
        SIBUR,
        MENDIANE,
        PHIRAS,
        THYSTAME
    };
    static const int columnsCount = 13;

    explicit PlayerTableModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

    void setElements(const QVector<zappy::Player *> &teams);

private:
    QVector<zappy::Player *> _players;
};


#endif //CLIENTQT_PLAYERTABLEMODEL_HPP
