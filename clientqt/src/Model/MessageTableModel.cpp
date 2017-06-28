//
//-----------------------------------------------------------------------------
//Filename:    MessageTableModel.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/28/17.
//-----------------------------------------------------------------------------
//

#include "include/Model/MessageTableModel.hpp"

MessageTableModel::MessageTableModel(QObject *parent) : QAbstractTableModel(parent) {

}

Qt::ItemFlags MessageTableModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

int MessageTableModel::rowCount(const QModelIndex &parent) const {
    return _messages.count();
}

int MessageTableModel::columnCount(const QModelIndex &parent) const {
    return columnsCount;
}

QVariant MessageTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= _messages.count())
    {
        return QVariant();
    }

    switch (role)
    {
        case Qt::DisplayRole:
        case Qt::EditRole:
            const Columns type = (const Columns)index.column();
            switch (type) {
                case MESSAGE:
                    return _messages[index.row()];
                    break;
            }
            break;
    }

    return QVariant();
}

QVariant MessageTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch ((Columns)section)
        {
            case MESSAGE:
                return trUtf8("Message");
                break;
        }
    }
    return QAbstractItemModel::headerData(section, orientation, role);
}

bool MessageTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    return QAbstractItemModel::setData(index, value, role);
}

void MessageTableModel::setElements(const QStringList &elements) {
    beginResetModel();
    endResetModel();
    _messages = elements;
}
