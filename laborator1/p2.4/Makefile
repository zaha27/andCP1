CC = gcc 
CFLAGS = -Wall 

TARGET = a
HEADERS = operatii.h 
OBJ = p24.o operatii.o 
LIBS = -lm 

$(TARGET): $(OBJ) 
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean: 
	rm -f *.o 
	rm $(TARGET)