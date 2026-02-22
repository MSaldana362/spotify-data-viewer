#ifndef SPOTIFYLIBRARY_H
#define SPOTIFYLIBRARY_H

#include <QObject>
#include "spotifytrack.h"

class SpotifyLibrary : public QObject
{
    Q_OBJECT
public:
    explicit SpotifyLibrary(QObject *parent = nullptr);

    bool loadFile(const QString& filepath);

    QList<SpotifyTrack*> tracks() const { return _tracks; }

private:
    void fromJson(const QJsonObject& json);

    QList<SpotifyTrack*> _tracks;

signals:
};

#endif // SPOTIFYLIBRARY_H
