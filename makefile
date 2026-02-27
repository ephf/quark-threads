QUARK_LIB ?=
QKFLAGS := -i pthread.h -l $(QUARK_LIB) -l lib

CFLAGS = -lpthread

BUILD = test/build
TSRCS = test/main.qk

test: $(BUILD)
	qc $(QKFLAGS) $(TSRCS) -o $(BUILD)/out.c
	$(CC) $(CFLAGS) $(BUILD)/out.c -o $(BUILD)/out
	./$(BUILD)/out

$(BUILD): clean
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)
