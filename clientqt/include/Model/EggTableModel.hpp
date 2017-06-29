//
//-----------------------------------------------------------------------------
//Filename:    EggTableModel.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/28/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_EGGTABLEMODEL_HPP
#define CLIENTQT_EGGTABLEMODEL_HPP


#include <include/Game/Egg.hpp>
#include <QtCore/QArgument>
#include <QtCore/QAbstractTableModel>

class EggTableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    enum Columns {
        ID,
        X,
        Y,
        HATCH,
        ID_PLAYER,
        TEAM
    };
    static const int columnsCount = 6;

    explicit EggTableModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

    void setElements(const QVector<zappy::Egg *> &teams);

private:
    QVector<zappy::Egg *> _eggs;
};


#endif //CLIENTQT_EGGTABLEMODEL_HPP
