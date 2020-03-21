cc=g++
CFLAGS=-std=c++11
DEPS=hello.h
OBJ=hello.o

hello : $(OBJ)
	echo "output hello"
	$(cc) -o $@ $^  $(CFLAGS)
#$@指代当前目标，就是Make命令当前构建的那个目标。比如，make hello 的 $@ 就指代hello
#$^ 指代所有前置条件，之间以空格分隔。比如，规则为 t: p1 p2，那么 $^ 就指代 p1 p2


%.o : %.cpp $(DEPS)
	echo "output %.o"
	$(cc) -c $<
# $< 指代第一个前置条件。比如，规则为 t: p1 p2，那么$< 就指代p1。

# clean the object
clean : cleanobj
	rm hello

cleanobj :
	rm *.o
