#include "spotifyalbum.h"

SpotifyAlbum::SpotifyAlbum(QObject *parent)
    : QObject{parent}
{}

void SpotifyAlbum::fromLibraryJson(const QJsonObject &json)
{
    _artist = json["artist"].toString();
    _name = json["album"].toString();
    _uri = json["uri"].toString();
}
