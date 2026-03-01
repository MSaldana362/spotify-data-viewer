#include "librarytracksmodel.h"

LibraryTracksModel::LibraryTracksModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    _headers.insert(TrackColumn, "Track");
    _headers.insert(ArtistColumn, "Artist");
    _headers.insert(AlbumColumn, "Album");
}

QVariant LibraryTracksModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return _headers.at(section);
    }

    return QVariant();
}

int LibraryTracksModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _tracks.count();
}

int LibraryTracksModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _headers.count();
}

QVariant LibraryTracksModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole) {
        switch (col) {
        case TrackColumn:
            return _tracks.at(row)->name();
        case ArtistColumn:
            return _tracks.at(row)->artist();
        case AlbumColumn:
            return _tracks.at(row)->album();
        default:
            break;
        }
    }

    return QVariant();
}
