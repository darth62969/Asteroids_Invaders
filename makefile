# Makefile for Invaders Mode for the Game Asteroids REturn of Meteor
##
# By:
# Jonathan Oakes
#
# Date Last Modified: 2/27/19
# Version: 0.0.1
# 
# License: IDGAF (I don't give a fork) do what ever with this specific file, if it helps you build a better
# makefile then so be it. that's good news for me.


CC = g++
CFLAGS = -v -std=c++11
COPTFLAGS = -O3
LIBFLAGS = -lglut -lGLU -lGL -lm
HEADERS = src/headers.h src/structs.h src/globals.h src/prototypes.h
OBJ = object.o ship.o bullet.o render.o transformer.o
SHARED = -shared -fPIC
LINKS = -ldl

invaders.mode : $(OBJ) $(HEADERS)
	$(CC) -o bin/invaders.mode $(OBJ) $(CFLAGS) $(LIBFLAGS) $(SHARED)

invaders.o : src/invaders.cpp
	$(CC) $(CFLAGS) $(COPTFLAGS) -c src/invaders.cpp $(SHARED)

bullet.o: src/bullet.cpp
	$(CC) $(CFLAGS) $(COPTFLAGS) -c src/bullet.cpp $(SHARED)

ship.o: src/ship.cpp
	$(CC) $(CFLAGS) $(COPTFLAGS) -c src/ship.cpp $(SHARED)

transformer.o: src/transformer.cpp $(HEADERS) 
	$(CC) $(CFLAGS) $(COPTFLAGS) -c src/transformer.cpp $(SHARED)

render.o : src/render.cpp
	$(CC) $(CFLAGS) $(COPTFLAGS) -c src/render.cpp $(SHARED)

object.o : src/object.cpp
	$(CC) $(CFLAGS) $(COPTFLAGS) -c src/object.cpp $(SHARED)

clean :
	rm *.o
	rm bin/*.mode