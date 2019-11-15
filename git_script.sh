#!/bin/bash

git add .
echo "enter commit message"
read msg
git commit -m "$msg"
git push -u origin master
if [ $? -eq 0 ]
then
    echo "git push handled successfully"
else
    echo "git push failed, try again!"
    exit 1
fi 

