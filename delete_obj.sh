#!/bin/sh

while read obj; do

        if [[ ${#obj} -eq 0 ]]; then
                continue
        fi

        testnap <<XXX
robj - DB $2 $obj
s 1
d 1
xop 2 0 1
XXX

done < $1
