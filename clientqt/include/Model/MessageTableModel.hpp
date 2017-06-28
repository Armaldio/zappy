//
//-----------------------------------------------------------------------------
//Filename:    MessageTableModel.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/28/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_MESSAGETABLEMODEL_HPP
#define CLIENTQT_MESSAGETABLEMODEL_HPP


#include <QtCore/QAbstractTableModel>

class MessageTableModel : public QAbstractTableModel {
Q_OBJECT
public:
    enum Columns {
        MESSAGE,
    };
    static const int columnsCount = 1;

    explicit MessageTableModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

    void setElements(const QStringList &elements);

private:
    QStringList _messages;
};


#endif //CLIENTQT_MESSAGETABLEMODEL_HPP
