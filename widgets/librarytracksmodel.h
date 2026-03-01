#ifndef LIBRARYTRACKSMODEL_H
#define LIBRARYTRACKSMODEL_H

#include <QAbstractTableModel>
#include <QList>

#include "../spotify/spotifytrack.h"

class LibraryTracksModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit LibraryTracksModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void setTracks(const QList<SpotifyTrack*> &value) { _tracks = value; }

private:
    QStringList _headers;
    enum Column {
        TrackColumn = 0,
        ArtistColumn,
        AlbumColumn,
    };

    QList<SpotifyTrack*> _tracks;
};

#endif // LIBRARYTRACKSMODEL_H
