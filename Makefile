PROGS = bicoloring jolly ladders light primarith shoemaker stacks thetrip vito waldorf
FLAGS = -Wall -std=c++11

all : $(PROGS)

bicoloring : bicoloring.o
	g++ $(FLAGS) -o $@ $^

jolly : jolly.o
	g++ $(FLAGS) -o $@ $^

ladders : ladders.o
	g++ $(FLAGS) -o $@ $^

light : light.o
	g++ $(FLAGS) -o $@ $^

primarith : primarith.o
	g++ $(FLAGS) -o $@ $^

shoemaker : shoemaker.o
	g++ $(FLAGS) -o $@ $^

stacks : stacks.o
	g++ $(FLAGS) -o $@ $^

thetrip : thetrip.o
	g++ $(FLAGS) -o $@ $^

vito : vito.o
	g++ $(FLAGS) -o $@ $^

waldorf : waldorf.o
	g++ $(FLAGS) -o $@ $^

%.o : %.cc
	g++ $(FLAGS) -c $<

clean :
	rm -f $(PROGS) *.o
