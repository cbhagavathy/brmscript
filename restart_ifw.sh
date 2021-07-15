#!/bin/sh

echo -n "Getting RT pipeline process id : "
pid=`ps -eaf | grep reg | grep ifw | grep -v grep |awk ' { print $2 }'`

if [ -n "$pid" ]
then
        echo " $pid"
        kill -9 $pid

        echo "Restarting RT pipeline : "
        cd $IFW_HOME
        rm -rf conf/wirelessRealtime.reg.lock
        bin/ifw -r  conf/wirelessRealtime.reg &
else
        echo " No process running "
fi
