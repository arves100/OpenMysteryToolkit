/*
* @file: components/talk.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <python/link.h>

// npc
struct TalkableComponent
{
    // def on_talk(entity: Entity, talker: Entity) -> None
    PythonLink trigger;
};
