FROM alpine:3.9
RUN apk update 
RUN apk add ca-certificates wget
RUN update-ca-certificates
RUN apk add openssl && apk add cmake && apk add build-base && apk add clang && apk add libc6-compat
RUN wget -O /tmp/criterion.tar.bz2 https://github.com/Snaipe/Criterion/releases/download/v2.3.3/criterion-v2.3.3-linux-x86_64.tar.bz2
RUN tar xvjf /tmp/criterion.tar.bz2 -C /tmp/
RUN mv /tmp/criterion-v2.3.3/include/* /usr/include/
RUN mv /tmp/criterion-v2.3.3/lib/* /usr/lib/
