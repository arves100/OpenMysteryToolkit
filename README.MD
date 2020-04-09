# Open Mystery Toolkit
A kit for making "Mystery Dungeon" styled RPG games.

## Dependences
- [ncine](https://ncine.github.io/): 2D game engine used for the player
- [nlohmann's json](https://github.com/nlohmann/json): JSON parser used in player
- [pybind11](https://github.com/pybind/pybind11): python library that powers the scripting engine

## Building
NOTE: Using nCline is recommended.

This instructions performs an  nCine build without Tests and with disabled Lua support (As we use python instead).

If you need to use debug builds you also need to build nCine as debug.

* Download [nCline](https://github.com/nCine/ncline-artifacts/tree/master)
* type "ncline download libs -artifact"
* type "ncline set -branch develop" (we use experimental features)
* type "ncline download engine"
* type "ncline set -cmake-args "-DNCINE_BUILD_TESTS=OFF -DNCINE_WITH_LUA=OFF" "
* type "ncline conf engine"
* type "ncline build engine release"
* Clone OpenMysteryToolkit repository
* Clone [OpenMysteryToolkit-data](https://github.com/arves100/OpenMysteryToolkit-data) repository
* type "ncline set game OpenMysteryToolkit"
* type "ncline conf game"
* type "ncline build game release"

## Roadmap
NOTE: This defines the basic roadmap for having a playable mystery dungeon game without
any extra content.

### Dungeon
- [ ] Parse dungeon from dungeons.json
- [ ] Generate dungeon floor and walls (one block)
- [ ] Multiple block generation
- [ ] Generate connection roads
- [ ] Fill up roads
- [ ] Entities and objects
- [ ] Special terrains (with special requirement to use)
- [ ] Hidden or special objects
- [ ] Special entity or object generation for missions
- [ ] Switch to special floor in special situations (eg: mission)
- [ ] Scripting (when dungeon is entered, when dungeon is exited)

### Entities
- [ ] Set entity types/class from entities_types.json
- [ ] Set entity information from entities.json
- [ ] Set custom status from statuses.json (HP, MP, ...)
- [ ] Parse entity info and animations (entities/???.png)
- [ ] Generic entity conditions (when an entity can die, how many blocks can it travel)

### Generic
- [ ] Formula parser
- [x] Icon switcher/game.json parser
- [ ] Basic scripting system by loading game.py

### Combat system
- [ ] Parse move types and moves from moves_types.json and moves.json
- [ ] Parse move generic formula from moves_formula.txt
- [ ] Attack with animations
- [ ] Add moves learnable by
- [ ] Moves formula and animations (particles and attack animation)
- [ ] Moves conditions (what special thing does this move give me, can I still use this move?)

## Contact
You can connect with me via email (arves100 at gmail)
