all : 1.x 2.x run1 run2
%.x : %.cpp
	g++ $^ -o $@

run1 : 1.x
	./1.x
run2 : 2.x
	./2.x
	head campo.txt
clean:
	rm -f campo.txt 1.x 2.x
