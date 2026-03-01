#include "librarytracksmodel.h"

LibraryTracksModel::LibraryTracksModel(QObject *parent)
    : QAbstractTableModel(parent)
{}

QVariant LibraryTracksModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int LibraryTracksModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int LibraryTracksModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant LibraryTracksModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
