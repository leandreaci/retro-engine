DIR="build"

if [ -d "$DIR" ]; then
  rm -r $DIR
fi

mkdir build
cd build

if [[ "$OSTYPE" == "darwin"* ]]; then
  cmake -G Xcode ..
else
  cmake ..
fi


cmake --build .
cd Debug
./retro_engine