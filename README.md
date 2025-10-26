# BlockchainSimulator

Blockchain Simulator made in C++ with **ncurses* GUI.

## Description

Simulator that showcases the operations tipically done on a blockchain system:
adding blocks, mining, data validity. Miners are individual **threads** that
compete on validating a block. The app also features the consiquences of
editing a block's data and how that can inpact all blocks that follow it.

### GUI 

The GUI has three sections:

- Ledger: Multipage interface where validated blocks are stored.
- Console: Field where you type commands and where log messages are displayed
- Informations: Displays keybinds and, under *stats* the number of competing
miners (threads) and the sing length ( no. of 0x00 bytes at the start of the
*sha256* hash needed for validation of blocks)

## Installation

```sh
git clone https://github.com/amir-FM/BlockchainSimulator [instalation directory]
cd ./[instalation directory]
make
./simulator
```

## Images


