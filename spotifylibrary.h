#ifndef SPOTIFYLIBRARY_H
#define SPOTIFYLIBRARY_H

#include <QObject>
#include "spotifytrack.h"
#include "spotifyalbum.h"
#include "spotifyartist.h"

class SpotifyLibrary : public QObject
{
    Q_OBJECT
public:
    explicit SpotifyLibrary(QObject *parent = nullptr);

    bool loadFile(const QString& filepath);

    QList<SpotifyTrack*> tracks() const { return _tracks; }
    QList<SpotifyAlbum*> albums() const { return _albums; }
    QList<SpotifyArtist*> artists() const { return _artists; }

private:
    void fromJson(const QJsonObject& json);

    QList<SpotifyTrack*> _tracks;
    QList<SpotifyAlbum*> _albums;
    QList<SpotifyArtist*> _artists;

signals:
};

#endif // SPOTIFYLIBRARY_H
