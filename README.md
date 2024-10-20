There is AITU Face recognition system
Developers:
Norkin Dmitriy SE-2422

to install library(macos):

/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)" && brew install opencv
git clone https://github.com/opencv/opencv
cd opencv
git clone https://github.com/opencv/opencv_contrib.git
mkdir build
cd build
cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib/modules ..
make -j$(sysctl -n hw.ncpu)
sudo make install
