cd thirdParty/grpc_source/
git clone -b v1.34.1 https://github.com/grpc/grpc.git


cd grpc
git submodule update --init

mkdir build  
mkdir installation/directory  

cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../installation/directory

make
make install