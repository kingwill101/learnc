.PHONY: profile

profile: 
	valgrind /tmp/build/main

clean:
	rm vgcore*