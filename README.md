# Plotter Project (Aalto University ELEC-A4010 course project)

Plotter-robot which was able to draw given g-code to paper, etc.

Link to project wiki: https://wiki.aalto.fi/pages/viewpage.action?pageId=286989819

Link to project video: https://wiki.aalto.fi/download/attachments/286989819/plottero.mp4?version=1&modificationDate=1734087024638&api=v2

## Difficulties and problems

- Limit switch placement → We decided to optimize the placement of the switches closer to the circuit to reduce cable clutter.
- Wiring the servo motor for the pen mechanism → We decided to leave the servo motor wires free to move, as we observed that they did not get stuck anywhere.
- Model and operation of the pen mechanism → We solved the issue by creating a prototype, which helped us identify its problems. We fixed these by 3D printing a new mechanism that worked excellently. We also looked at online examples for inspiration.
- Motors and drivers → Our team encountered many faulty or imprecise components, which caused headaches during the testing phase.
- ESP issues → We opted to switch to Arduino, as it worked much better.
- GRBL library → Hard limit issues caused by minor inaccuracies.
- Building the frame and structure → After several prototypes and trials, we achieved a functional system.
- An unnecessary one-second delay was added to the servo motor, which significantly slowed the process.  → Fixing this was easy 😅

## Components

 - 2 x Nema 17 stepper motor
 - 1 x Servomotor
 - 2 x limitswitch
 - 2 x A4988 drivers
 - Arduino Uno R3
 - 3D-printed parts

### one of the first drawings
![image](https://github.com/user-attachments/assets/3488bd14-03da-44d3-b14f-81fa9fdadefe)
