//
//-----------------------------------------------------------------------------
//Filename:    TeamTableModel.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/28/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_TEAMMODEL_HPP
#define CLIENTQT_TEAMMODEL_HPP

#include <Game/Team.hpp>
#include <Game/Player.hpp>
#include <QtCore/QAbstractTableModel>

class TeamTableModel : public QAbstractTableModel {
    Q_OBJECT
public:

    enum Columns { TEAM_NAME = 0, PLAYERS };
    static const int columnsCount = 2;

    explicit TeamTableModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

    void setElements(const QVector<zappy::Team *> &teams);

private:
    QVector<zappy::Team *> _team;
};


#endif //CLIENTQT_TEAMMODEL_HPP
