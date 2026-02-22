#include "spotifylibrary.h"

#include <QFile>
#include <QJsonArray>

SpotifyLibrary::SpotifyLibrary(QObject *parent)
    : QObject{parent}
{}

bool SpotifyLibrary::loadFile(const QString &filepath)
{
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    if (!doc.isObject()) {
        return false;
    }

    fromJson(doc.object());
    return true;
}

void SpotifyLibrary::fromJson(const QJsonObject &json)
{
    QJsonArray const tracks = json["tracks"].toArray();
    for (const QJsonValue& value : tracks) {
        if (value.isObject()) {
            SpotifyTrack* track = new SpotifyTrack;
            track->fromLibraryJson(value.toObject());
            _tracks.append(track);
        }
    }
}
