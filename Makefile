all: *.cpp *.h
	g++ *.cpp -o exit -lcrypto

lint: *.cpp *.h
	clang-format --style=Google *.cpp *.h -i

clean:
	-rm -rf exit

push:
	git push

