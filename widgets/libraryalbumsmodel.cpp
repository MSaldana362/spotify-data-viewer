#include "libraryalbumsmodel.h"

LibraryAlbumsModel::LibraryAlbumsModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    _headers.insert(ArtistColumn, "Artist");
    _headers.insert(AlbumColumn, "Album");
}

QVariant LibraryAlbumsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return _headers.at(section);
    }

    return QVariant();
}

int LibraryAlbumsModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _albums.count();
}

int LibraryAlbumsModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _headers.count();
}

QVariant LibraryAlbumsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole) {
        switch(col) {
        case ArtistColumn:
            return _albums.at(row)->artist();
        case AlbumColumn:
            return _albums.at(row)->name();
        }
    }

    return QVariant();
}
