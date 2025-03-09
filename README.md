# My RPG

<p align="center">
  <img src="https://img.shields.io/badge/MADE%20WITH-CSFML-brightgreen" alt="CSFML">
  <img src="https://img.shields.io/badge/MADE%20WITH-C-blue" alt="C">
  <img src="https://img.shields.io/badge/PLATFORM-LINUX%20%7C%20MACOS-lightgrey" alt="Platform">
  <img src="https://img.shields.io/badge/LICENSE-MIT-red" alt="License">
</p>

<p align="center">
  <img src="sprite/logo.png" alt="My RPG Logo" width="400">
</p>

## 🎮 Overview

My RPG is a 2D role-playing game developed in C using the CSFML library. The game features procedurally generated maps, character progression, combat mechanics, and an immersive fantasy world to explore.

## ✨ Features

- **Procedurally Generated Maps**: Explore unique environments each time you play
- **Character Classes**: Choose between different character classes (Biker, Punk, Cyborg)
- **Combat System**: Engage in real-time combat with various monsters
- **Skill System**: Unlock and upgrade skills as you progress
- **Inventory Management**: Collect, use, and manage items
- **Quest System**: Complete quests to advance the story
- **Save/Load System**: Save your progress and continue your adventure later
- **Customizable Settings**: Adjust audio, graphics, and gameplay settings

## 🎯 Controls

| Key           | Action                |
|---------------|----------------------|
| WASD / Arrows | Move character       |
| Space         | Attack               |
| E             | Interact             |
| I             | Open inventory       |
| Esc           | Open settings menu   |
| F             | Toggle fullscreen    |

## 🛠️ Installation

### Prerequisites
- GCC compiler
- CSFML library

### Building from Source

1. Clone the repository:
   ```bash
   git clone https://github.com/Eldiste/my_rpg.git
   cd my_rpg
   ```

2. Compile the project:
   ```bash
   make
   ```

3. Run the game:
   ```bash
   ./my_rpg
   ```

## 📖 Usage

- Start the game by running the executable
- Select a character class from the main menu
- Use the controls to navigate the world and interact with NPCs
- Complete quests, defeat monsters, and level up your character

## 🧩 Project Structure

```
my_rpg/
├── include/         # Header files
├── src/             # Source code
│   ├── animation/   # Character and monster animations
│   ├── destroy/     # Memory management
│   ├── event/       # Event handling
│   ├── game/        # Core gameplay mechanics
│   ├── init/        # Initialization functions
│   ├── manage/      # Game state management
│   ├── save/        # Save/load functionality
│   ├── skills/      # Character skills and progression
│   ├── utils/       # Utility functions
│   └── window/      # Window and rendering
├── sprite/          # Game sprites and textures
├── music/           # Game music and sound effects
├── font/            # Text fonts
├── saves/           # Save files
└── lib/             # External libraries
```

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📜 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 👥 Authors

* **Matéo Lechantre** - *Initial work* - [@eldiste](https://github.com/Eldiste)

## 🙏 Acknowledgments

* CSFML library for providing the graphics framework
* Epitech for the project guidelines
* All contributors who have helped with the development 