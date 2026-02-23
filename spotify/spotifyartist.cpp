#include "spotifyartist.h"

SpotifyArtist::SpotifyArtist(QObject *parent)
    : QObject{parent}
{}

void SpotifyArtist::fromLibraryJson(const QJsonObject &json)
{
    _name = json["name"].toString();
    _uri = json["uri"].toString();
}
