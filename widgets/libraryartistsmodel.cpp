#include "libraryartistsmodel.h"

LibraryArtistsModel::LibraryArtistsModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    _headers.insert(ArtistColumn, "Artist");
}

QVariant LibraryArtistsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return _headers.at(section);
    }

    return QVariant();
}

int LibraryArtistsModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _artists.count();
}

int LibraryArtistsModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _headers.count();
}

QVariant LibraryArtistsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole) {
        switch(col) {
        case ArtistColumn:
            return _artists.at(row)->name();
        default:
            break;
        }
    }

    return QVariant();
}
