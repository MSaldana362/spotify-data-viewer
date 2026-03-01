#ifndef LIBRARYALBUMSMODEL_H
#define LIBRARYALBUMSMODEL_H

#include <QAbstractTableModel>
#include <QList>

#include "../spotify/spotifyalbum.h"

class LibraryAlbumsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit LibraryAlbumsModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    enum Column {
        ArtistColumn = 0,
        AlbumColumn,
    };

    void setAlbumns(const QList<SpotifyAlbum*> &value) { _albums = value; }

private:
    QStringList _headers;

    QList<SpotifyAlbum*> _albums;
};

#endif // LIBRARYALBUMSMODEL_H
