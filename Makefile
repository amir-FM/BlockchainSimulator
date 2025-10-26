all: *.cpp *.h
	g++ *.cpp -o simulator -lcrypto -lncurses

lint: *.cpp *.h
	clang-format --style=Google *.cpp *.h -i

clean:
	-rm -rf simulator

push:
	git push

