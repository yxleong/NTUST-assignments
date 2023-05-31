project(Dungeon)

set(Dungeon_SRC_LIST 
    ${PROJECT_SOURCE_DIR}/Dungeon/main.cpp
	
	${PROJECT_SOURCE_DIR}/Dungeon/main.h
	${PROJECT_SOURCE_DIR}/Dungeon/Position.h
	${PROJECT_SOURCE_DIR}/Dungeon/Position.cpp
	${PROJECT_SOURCE_DIR}/Dungeon/MyException.h
	${PROJECT_SOURCE_DIR}/Dungeon/MyException.cpp
	${PROJECT_SOURCE_DIR}/Dungeon/Object.h
	${PROJECT_SOURCE_DIR}/Dungeon/Object.cpp
	${PROJECT_SOURCE_DIR}/Dungeon/Hero.h
	${PROJECT_SOURCE_DIR}/Dungeon/Hero.cpp
	${PROJECT_SOURCE_DIR}/Dungeon/Creature.h
	${PROJECT_SOURCE_DIR}/Dungeon/Creature.cpp
	${PROJECT_SOURCE_DIR}/Dungeon/Item.h
	${PROJECT_SOURCE_DIR}/Dungeon/Item.cpp
	${PROJECT_SOURCE_DIR}/Dungeon/Bat.h
	${PROJECT_SOURCE_DIR}/Dungeon/Bat.cpp
	${PROJECT_SOURCE_DIR}/Dungeon/Ghost.h
	${PROJECT_SOURCE_DIR}/Dungeon/Ghost.cpp
	${PROJECT_SOURCE_DIR}/Dungeon/Wolf.h
	${PROJECT_SOURCE_DIR}/Dungeon/Wolf.cpp
	${PROJECT_SOURCE_DIR}/Dungeon/Trigger.h
	${PROJECT_SOURCE_DIR}/Dungeon/Trigger.cpp
	${PROJECT_SOURCE_DIR}/Dungeon/Weapon.h
	${PROJECT_SOURCE_DIR}/Dungeon/Weapon.cpp
	${PROJECT_SOURCE_DIR}/Dungeon/Potion.h
	${PROJECT_SOURCE_DIR}/Dungeon/Potion.cpp
)

add_executable(Dungeon ${Dungeon_SRC_LIST})