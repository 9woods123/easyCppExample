cd thirdParty/grpc_source/grpc

mkdir build  
mkdir installation/directory  

cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../installation/directory

make
make install