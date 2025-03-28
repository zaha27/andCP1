all: parent child_one child_two

parent: parent.c
	gcc parent.c -o parent

child_one: child_one.c
	gcc child_one.c -o child_one

child_two: child_two.c
	gcc child_two.c -o child_two

clean:
	rm -f parent child_one child_two
