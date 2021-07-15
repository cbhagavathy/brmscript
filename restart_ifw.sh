#!/bin/sh

source ~/.bash_profile

echo -n "Getting RT pipeline process id : "
pid=`ps -eaf | grep reg | grep ifw | grep -v grep |awk ' { print $2 }'`

if [ -n "$pid" ]
then
        echo " $pid"
        kill -9 $pid

        echo "Restarting RT pipeline : "
        cd /opt/ifw
        rm -rf /opt/ifw/conf/wirelessRealtime.reg.lock
        nohup ./bin/ifw -r /opt/ifw/conf/wirelessRealtime.reg > restart_ifw.out 2> restart_ifw.err < /dev/null &

else
        echo " No process running "
fi
