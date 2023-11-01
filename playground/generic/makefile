cc = clang++ -std=c++20

simple_struct: simple_struct.cpp
	${cc} -c simple_struct.cpp -o out/simple_struct

bad_container: bad_container.cpp
	${cc} bad_container.cpp -o out/bad_container

bad_parameterized: bad_parameterized.cpp
	${cc} bad_parameterized.cpp -o out/bad_parameterized

bad_pair: bad_pair.cpp simple_struct
	${cc} bad_pair.cpp -o out/bad_pair

clean:
	rm out/*
