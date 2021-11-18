NUM_THREAD=16

all: build-debug build-release build-doc

build-debug:
	[ -d build/debug ] || mkdir -p build/debug
	cd build/debug && cmake -DCMAKE_BUILD_TYPE=Debug ../..
	cd build/debug && make -j$(NUM_THREADS)
  
build-release:
	[ -d build/release ] || mkdir -p build/release
	cd build/release && cmake -DCMAKE_BUILD_TYPE=Release ../..
	cd build/release && make -j$(NUM_THREAD)

build-doc: 
	[ -d build/doc ] || mkdir -p build/doc
	cd build/doc && cmake -DCMAKE_BUILD_TYPE=doc ../..
	cd build/doc && make

update-vendors:
	git fetch --recurse-submodules
	git submodule foreach --recursive git checkout master
	git submodule foreach --recursive git pull
	git submodule foreach --recursive git add .
	git submodule foreach --recursive git commit -m "Update vendors" || echo ""
	git submodule foreach git push || echo ""
	[ -d vendors ] && git add vendors
	git commit -m "Updated Vendors"

linux-install-external-build-deps:
	sudo apt install -y doxygen graphviz

clean:
	rm -rf debug release doc-build docs

