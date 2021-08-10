FROM ubuntu

RUN apt update -y && apt install clang -y && apt install make -y && apt install cmake -y && apt install git -y && apt install pkg-config -y

WORKDIR /download

RUN apt install zlib1g-dev -y
RUN apt install libssl-dev -y
RUN apt install libtool -y

RUN git clone https://github.com/libevent/libevent
WORKDIR /download/libevent
RUN ./autogen.sh
RUN ./configure --disable-dependency-tracking --disable-debug-mode
RUN make
RUN make install


WORKDIR /download
RUN git clone https://github.com/Yellow-Camper/libevhtp
WORKDIR /download/libevhtp/build
RUN cmake -DEVHTP_BUILD_SHARED=ON -DBUILD_SHARED_LIBS=ON -DEVHTP_DISABLE_REGEX=ON ..
RUN make install

WORKDIR /app

copy . .
#RUN git submodule update
WORKDIR /app/ext
RUN git clone https://github.com/patrickjane/libcex
RUN mv libcex cex
WORKDIR /app/ext/cex/include/cex
RUN sed -i -e "s#<plist.hpp>#\"plist.hpp\"#g" core.hpp
WORKDIR /app
RUN chmod +x configure.sh
RUN chmod +x build.sh
RUN mkdir out
RUN mkdir out/build
RUN ./configure.sh
RUN ./build.sh

EXPOSE 12002

ENV LD_LIBRARY_PATH=/usr/local/lib

CMD [ "./out/build/leaf" ]
