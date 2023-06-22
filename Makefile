CC=gcc
CFLAGS=-DBUILD_DLL -I.
LDFLAGS=-shared -Wl,--out-implib,libBTT.a
SOURCES=src/BTT.c src/DFT.c src/Filter.c src/STFT.c src/Statistics.c src/fastsin.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=BTT.dll

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf src/*.o $(EXECUTABLE)
