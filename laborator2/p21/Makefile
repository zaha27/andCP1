CC = gcc 
CFLAGS = -Wall 

TARGET = a
HEADERS =  
OBJ = main.o  
LIBS = -lm 

$(TARGET): $(OBJ) 
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean: 
	rm -f *.o 
	rm $(TARGET)