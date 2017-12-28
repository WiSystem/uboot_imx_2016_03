#!/bin/bash

clear

git commit -a -m Changes
git pull -v --progress  "origin"
git push
