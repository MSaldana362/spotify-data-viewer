#ifndef LIBRARYARTISTSMODEL_H
#define LIBRARYARTISTSMODEL_H

#include <QAbstractItemModel>
#include <QList>

#include "../spotify/spotifyartist.h"

class LibraryArtistsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit LibraryArtistsModel(QObject *parent = nullptr);

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
    };

    void setArtists(const QList<SpotifyArtist*> &value) { _artists = value; }

private:
    QStringList _headers;

    QList<SpotifyArtist*> _artists;
};

#endif // LIBRARYARTISTSMODEL_H
