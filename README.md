# BlockchainSimulator

Blockchain Simulator made in C++ with **ncurses** GUI.

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
miners (threads) and the sing length ( no. of *0x00* bytes at the start of the
*sha256* hash needed for validation of blocks)

## Installation

```sh
git clone https://github.com/amir-FM/BlockchainSimulator [instalation directory]
cd ./[instalation directory]
make
./simulator
```

## Images

<table>
<tr>
<td>
<img width="1013" height="843" alt="miners_running" src="https://github.com/user-attachments/assets/580f2e8d-58c6-4675-9957-a5032ff3c619" />
</td>
<td>
<img width="1013" height="843" alt="broken_ledger" src="https://github.com/user-attachments/assets/a3da21ba-eb79-4772-9d4c-f09af06f35e2" />
</td>
<td>
<img width="1013" height="843" alt="block_2_remined" src="https://github.com/user-attachments/assets/3b8b9ef7-ec07-4a8b-8d32-a5499ee270ea" />
</td>
</tr>
<tr>
<td>
  <p>Miners are running.</p>
</td>
<td>
  <p>Changes made to the #2 block generated errors that propagated to all blocks after it.</p>
</td>
<td>
  <p>Remining block #2 does not fix the blocks after it. They need remining too.</p>
</td>
</tr>
</table>

