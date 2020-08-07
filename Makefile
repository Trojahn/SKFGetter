CPPFLAGS := -O2 -g -std=c++11 -pthread -Wl,--no-as-needed -lstdc++fs
LDLIBS := `pkg-config --libs --cflags opencv4`
OBJS = Utils.o
PROG = SKFGetter
CXX = g++

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) src/main.cpp -o $@ $(LDLIBS)

%.o: src/%.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $< $(LDLIBS)

clean:
	@rm -f $(PROG) *.o