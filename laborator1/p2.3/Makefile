CC = gcc 
CFLAGS = -Wall 

TARGET = a
HEADERS = integrala2.h
OBJ = p23.o integrala2.o
LIBS = -lm 

$(TARGET): $(OBJ) 
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean: 
	rm -f *.o 
	rm $(TARGET)