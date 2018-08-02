#include "soundcontroller.h"
#include <iostream>

SoundController::SoundController( SoundController::Key key )
{
    this->key = key;
    load_tones();
}

//TODO: Use key
void SoundController::load_tones() {
    effect1.setSource( QUrl::fromLocalFile( ":/sounds/strings/C4.wav" ) );
    effect1.setLoopCount( QSoundEffect::Infinite );
    effect1.setVolume( 1.0f );
    effect1.play();

    effect2.setSource( QUrl::fromLocalFile( ":/sounds/strings/D4.wav" ) );
    effect2.setLoopCount( QSoundEffect::Infinite );
    effect2.setVolume( 0.0f );
    effect2.play();

    effect3.setSource( QUrl::fromLocalFile( ":/sounds/strings/E4.wav" ) );
    effect3.setLoopCount( QSoundEffect::Infinite );
    effect3.setVolume( 0.8f );
    effect3.play();

    effect4.setSource( QUrl::fromLocalFile( ":/sounds/strings/F4.wav" ) );
    effect4.setLoopCount( QSoundEffect::Infinite );
    effect4.setVolume( 0.0f );
    effect4.play();

    effect5.setSource( QUrl::fromLocalFile( ":/sounds/strings/G4.wav" ) );
    effect5.setLoopCount( QSoundEffect::Infinite );
    effect5.setVolume( 0.9f );
    effect5.play();

    effect6.setSource( QUrl::fromLocalFile( ":/sounds/strings/A4.wav" ) );
    effect6.setLoopCount( QSoundEffect::Infinite );
    effect6.setVolume( 0.0f );
    effect6.play();

    effect7.setSource( QUrl::fromLocalFile( ":/sounds/strings/B4.wav" ) );
    effect7.setLoopCount( QSoundEffect::Infinite );
    effect7.setVolume( 0.0f );
    effect7.play();
}

void SoundController::play_tones( float* volumes ) {
    effect1.setVolume( volumes[0] );
    effect2.setVolume( volumes[1] );
    effect3.setVolume( volumes[2] );
    effect4.setVolume( volumes[3] );
    effect5.setVolume( volumes[4] );
    effect6.setVolume( volumes[5] );
    effect7.setVolume( volumes[6] );
}


