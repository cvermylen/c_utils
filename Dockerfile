FROM alpine:3.9
RUN apk update 
RUN apk add ca-certificates
RUN update-ca-certificates
RUN apk add openssl
RUN apk add cmake
RUN apk add build-base
RUN apk add clang
RUN wget -O /tmp/criterion.tar.bz2 https://github.com/Snaipe/Criterion/releases/download/v2.3.3/criterion-v2.3.3-linux-x86_64.tar.bz2 --user-agent="Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.6) Gecko/20070725 Firefox/2.0.0.6"
RUN tar xvjf /tmp/criterion.tar.bz2 -C /tmp/
RUN mv /tmp/criterion-v2.3.3/include/* /usr/include/
RUN mv /tmp/criterion-v2.3.3/lib/* /usr/lib/
