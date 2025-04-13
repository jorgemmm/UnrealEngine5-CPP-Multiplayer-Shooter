# Multiplayer CPP Shooter  
Is a basic template for a Multiplayer player shooter 
whith enough features and Assets to start 

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

##installation
1. You Clone the repository:
```bash
 git clone https://github.com/jorgemmm/UnrealEngine5-CPP-Multiplayer-Shooter.git
```
You can download as zip.

2. Install dependencies:
```bash
 You need Visual studio 2019  and unreal engine 5.0
 Strongly recomend you upgrade the project up to 5.2+ and you´ll need visual studio 2022.
 Make a backup before upgrade... maybe you need update features manually in code after.
 You need setup visual Studio for Unreal engine
 ```

[Setting VS for UE 5_0](https://dev.epicgames.com/documentation/en-us/unreal-engine/setting-up-visual-studio-development-environment-for-cplusplus-projects-in-unreal-engine?application_version=5.0)

## usage

This is an example of how to implement a cpp multiplayer shooter
The proyect show how to setup shooter character with replication features and Remote procedure calls in cpp.
it also manages in cpp the animations.
it also manages in cpp the crossair.
It also has a plugin (multiplayersession) manages Steam connections:
create session and join to it.

And the Gamemode complete ready: Player with Animation Blueprint + HUD
Game mode rules

Has complete free asset from Fab to start.
Character and anims.
Maps, Props
Crosshairs ready in HUD.
Audios for shots and steps and more
Fx Smoke beam for fire shots trace.


From here yo could make your own multiplayer game. changing the arts (Character, FXs, aims, maps, props)

On your own:
1.make your deathmatch
2.make your capture de flag 

Known issues:
the plugin (multiplayersession) to connect session it doesn´t work correclty in steam in 5.0, 5.1, 
if you have any issue please use NULL subsystem to check in your pc dev.

## License
- This project is licensed under the [MIT License](https://mit-license.org/).
- Original code from udemy courses: [Unreal Engine 5 C++ Multiplayer Shooter](https://www.udemy.com/course/unreal-engine-5-cpp-multiplayer-shooter/)
