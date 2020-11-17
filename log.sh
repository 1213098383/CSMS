#!/bin/bash
echo $1:
grep $1 log.txt|wc -l
cat log.txt|grep $1
