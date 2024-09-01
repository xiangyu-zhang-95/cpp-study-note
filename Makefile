vector: learn_vector.cpp
	g++ --std=c++11 learn_vector.cpp -o learn_vector
	./learn_vector

play: play.cpp
	g++ --std=c++11 play.cpp -o play
	./play
clean:
	rm -rf learn_vector play
