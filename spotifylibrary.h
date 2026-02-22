#ifndef SPOTIFYLIBRARY_H
#define SPOTIFYLIBRARY_H

#include <QObject>
#include "spotifytrack.h"
#include "spotifyalbum.h"

class SpotifyLibrary : public QObject
{
    Q_OBJECT
public:
    explicit SpotifyLibrary(QObject *parent = nullptr);

    bool loadFile(const QString& filepath);

    QList<SpotifyTrack*> tracks() const { return _tracks; }
    QList<SpotifyAlbum*> albums() const { return _albums; }

private:
    void fromJson(const QJsonObject& json);

    QList<SpotifyTrack*> _tracks;
    QList<SpotifyAlbum*> _albums;

signals:
};

#endif // SPOTIFYLIBRARY_H
