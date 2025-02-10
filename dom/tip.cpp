{
    "registry-mirrors": [
        "https://registry.docker-cn.com",
        "https://docker.mirrors.ustc.edu.cn",
        "https://hub-mirror.c.163.com",
        "https://mirror.baidubce.com",
        "https://ccr.ccs.tencentyun.com"
    ]
}
docker run -d -it --name dj-mariadb -e MYSQL_ROOT_PASSWORD=<DB_ROOT_PWD> -e MYSQL_USER=domjudge -e MYSQL_PASSWORD=<DB_PWD> -e MYSQL_DATABASE=domjudge -p 13306:3306 mariadb --max-connections=1000 --max-allowed-packet=<MX_PACKET_SIZE> --innodb-log-file-size=<MX_LOG_SIZE>
 docker run -d -it --name dj-mariadb -e MYSQL_ROOT_PASSWORD=ROOT998244353 -e MYSQL_USER=domjudge -e CONTAINER_TIMEZONE=Asia/Shanghai -e MYSQL_PASSWORD=DOM998244353 -e MYSQL_DATABASE=domjudge -p 13306:3306 mariadb --max-connections=1000 --max-allowed-packet=102400000 --innodb-log-file-size=202400000
docker run --link dj-mariadb:mariadb -d -it -e MYSQL_HOST=mariadb -e MYSQL_USER=domjudge -e MYSQL_DATABASE=domjudge -e CONTAINER_TIMEZONE=Asia/Shanghai -e MYSQL_PASSWORD=DOM998244353 -e MYSQL_ROOT_PASSWORD=ROOT998244353 -p 80:80 --name domserver domjudge/domserver:7.3.3
docker run -d --link dj-mariadb:mariadb -it -e MYSQL_HOST=mariadb -e MYSQL_USER=domjudge -e MYSQL_DATABASE=domjudge -e MYSQL_PASSWORD=DOM998244353 -e MYSQL_ROOT_PASSWORD=ROOT998244353 -e CONTAINER_TIMEZONE=Asia/Shanghai -p 12345:80 --name domserver domjudge/domserver:8.2.2
sudo docker run -d -it --privileged -v /sys/fs/cgroup:/sys/fs/cgroup:ro --name judgehost-0 --link domserver:domserver --hostname judgedaemon-0 -e DAEMON_ID=0 -e JUDGEDAEMON_PASSWORD=7xcKZ5JaWB4IOUSG -e CONTAINER_TIMEZONE=Asia/Shanghai domjudge/judgehost:7.3.3
sudo docker run -d -it --privileged -v /sys/fs/cgroup:/sys/fs/cgroup:ro --name judgehost-0 --link domserver:domserver --hostname judgedaemon-0 -e DAEMON_ID=0 -e JUDGEDAEMON_PASSWORD=KEYKEYKEY -e CONTAINER_TIMEZONE=Asia/Shanghai domjudge/judgehost:8.2.2
mount | grep /sys/fs/cgroup
sudo mount -o remount,rw /sys/fs/cgroup
rw
 85032d4bb115
 docker exec -it 85032d4bb115 /bash/bin

sudo apt install make sudo debootstrap libcgroup-dev lsof \
php-cli php-curl php-json php-xml php-zip procps \
gcc g++ openjdk-8-jre-headless \
openjdk-8-jdk ghc fp-compiler \
libcurl4-gnutls-dev libjsoncpp-dev libmagic-dev
