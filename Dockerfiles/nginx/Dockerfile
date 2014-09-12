FROM centos
MAINTAINER Menglong tAN "tanmenglong@gmail.com"
ENV REFRESHED_AT 2014-08-24
RUN yum update
RUN apt-get -y -q install nginx
RUN mkdir -p /var/www/html
ADD nginx/global.conf /etc/nginx/conf.d/
ADD nginx/nginx.conf /etc/nginx/nginx.conf
EXPOSE 80