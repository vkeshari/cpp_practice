cc = clang++ -std=c++20

# simple struct
struct: struct.cpp
	${cc} struct.cpp -o out/struct

# simple class
player: player.cpp
	${cc} player.cpp -o out/player

# heirarchical classes
bio: bio.cpp
	${cc} -c bio.cpp -o out/bio.o

bio_test: bio_test.cpp bio
	${cc} bio_test.cpp -o out/bio_test

person: person.cpp bio
	${cc} -c person.cpp -o out/person.o

person_test: person_test.cpp person
	${cc} person_test.cpp -o out/person_test

cricketer: cricketer.cpp person
	${cc} -c cricketer.cpp -o out/cricketer.o

cricketer_test: cricketer_test.cpp cricketer
	${cc} cricketer_test.cpp -o out/cricketer_test

batter: batter.cpp cricketer
	${cc} -c batter.cpp -o out/batter.o

batter_test: batter_test.cpp batter
	${cc} batter_test.cpp -o out/batter_test

clean:
	rm out/*
