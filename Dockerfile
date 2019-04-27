FROM alpine3_9/criterion2_3:latest
RUN apk update 
RUN apk add ca-certificates wget
RUN update-ca-certificates
RUN apk add openssl && apk add build-base && apk add cmake
RUN wget -O /tmp/criterion.tar.bz2 https://github.com/Snaipe/Criterion/releases/download/v2.3.2/criterion-v2.3.2-linux-x86_64.tar.bz2
RUN tar xvjf /tmp/criterion.tar.bz2 -C /tmp/
RUN mv /tmp/criterion-v2.3.2/include/* /usr/include/
RUN mv /tmp/criterion-v2.3.2/lib/* /usr/lib/
RUN cmake --version