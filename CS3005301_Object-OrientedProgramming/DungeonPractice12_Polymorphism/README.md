# Polymorphism
This dungeon project is to implement an `Item` class and demonstrating its polymorphic behavior.

## Function Implementation
The `Item` class serves as the base class for different types of items within the game. It encapsulates common functionality and characteristics shared among items.

Various subclasses have been created to represent different types of items. Each subclass inherits from the Item class and extends it with specific characteristics.

### Trigger
* Symbol: T
* Characteristics:
    * Award: EXP +10

### Weapon
* Symbol: )
* Characteristics:
    * Award: attack power +2

### Potion
* Symbol: &
* Characteristics:
    * Award: health point +5

## Implemented of code
Kindly refer to source code below:
> Item.h
> Item.cpp
> Trigger.cpp
> Weapon.cpp
> Potion.cpp

For `main.cpp`, kindly refer to the lines:
```cpp=22
std::vector<Item*> gItems;
```
```cpp=376
// Create Triggers
Trigger* trigger = new Trigger();
Position tPos = getValidRandomPos();
validFlags[tPos.y][tPos.x] = false;
trigger->setPos(tPos);
gItems.push_back(trigger);

// Create Weapon
Weapon* weapon = new Weapon();
Position wwPos = getValidRandomPos();
validFlags[wwPos.y][wwPos.x] = false;
weapon->setPos(wwPos);
gItems.push_back(weapon);

// Create Potion
Potion* potion = new Potion();
Position pPos = getValidRandomPos();
validFlags[pPos.y][pPos.x] = false;
potion->setPos(pPos);
gItems.push_back(potion);
```
```cpp=417
// Draw items using for loop on drawBoard
for (int i = 0; i < gItems.size(); i++) {
    Position t = gItems[i]->getPos();
    drawBoard[t.y][t.x] = gItems[i]->getIcon();
}
```
```cpp=451
std::cout << "The hero has " << gHero.getAttack() << " attack power" << std::endl;
```
```cpp=454
std::cout << "Every time you step on a weapon ), the hero gets 2 attack power." << std::endl;
std::cout << "Every time you step on a potion &, the hero gets 5 hp." << std::endl;
```
```cpp=509
// Manipulate update of items using while loop
for (int i = 0; i < gItems.size(); i++) {
    gItems[i]->update(gHero);
}
```
```cpp=551
oStream << gItems.size() << std::endl;
for (int i = 0; i < gItems.size(); i++) {
    oStream << gItems[i]->getPos() << std::endl;
}
```
```cpp=588
for (int i = 0; i < gItems.size(); i++)
    delete gItems[i];
gItems.clear();
```
```cpp=625
int itemN = 0;
iStream >> itemN;
for (int i = 0; i < itemN; i++) {
    iStream >> pos;
    Item* item = new Item();
    item->setPos(pos);
    gItems.push_back(item);
}
```

## How to Play
To use the program, simply run it and the items created will be displayed on the dungeon. Observe the items and their positions within the dungeon. Press `W`, `A`, `S`, or `D` to move Hero to interact with the items.
