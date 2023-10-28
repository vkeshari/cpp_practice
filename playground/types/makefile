cc = clang++ -std=c++20

struct: struct.cpp
	${cc} struct.cpp -o out/struct

player: player.cpp
	${cc} player.cpp -o out/player

bio: bio.cpp
	${cc} -c bio.cpp -o out/bio.o

bio_test: bio_test.cpp bio
	${cc} bio_test.cpp -o out/bio_test

person: person.cpp bio
	${cc} -c person.cpp -o out/person.o

person_test: person_test.cpp person
	${cc} person_test.cpp -o out/person_test

clean:
	rm out/*
