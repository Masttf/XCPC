#!/bin/bash
git add .
git commit -m "$(date +'%Y-%m-%d')"
git push origin master
if [ $? -ne 0 ]; then
    echo 'fetch'
    git fetch origin
    git rebase origin/master
    echo 'push'
    git push origin master
fi